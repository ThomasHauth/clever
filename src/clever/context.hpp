//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/algorithm/string.hpp>

#include "error.hpp"
#include "opencl.hpp"
#include "icontext.hpp"
#include "kernel_proxy.hpp"

namespace clever
{

struct context_settings
{
	context_settings(std::string const& platform_name = "",
			opencl::device_type device_type = opencl::device_type::default_,
			std::string build_options = "",
			bool profile = false,
			cl_command_queue_properties cmd_queue_properties = 0,
			int useComputeUnits = -1) :

			m_platform_name(platform_name),
			m_device_type( device_type ),
			m_build_options(build_options),
			m_profile(profile),
			m_cmd_queue_properties( cmd_queue_properties),
			m_useComputeUnits( useComputeUnits)
	{

	}

	std::string m_platform_name;
	opencl::device_type m_device_type;
	std::string m_build_options;
	bool m_profile;
	cl_command_queue_properties m_cmd_queue_properties;
	int m_useComputeUnits;

};

struct source_modifier: public boost::noncopyable
{
	virtual void modify(std::string & src) const = 0;
};

class context: public clever::icontext
{
public:
	context(const context_settings & settings = context_settings()) :
			m_settings(settings)
	{

		context_ = opencl::createContext(m_settings.m_device_type,
				m_settings.m_platform_name, m_settings.m_useComputeUnits);
		::size_t size;
		ERROR_HANDLER(
				ERROR = opencl::clGetContextInfo( context_, CL_CONTEXT_DEVICES, 0, NULL, &size ));
		ERROR_HANDLER( ERROR = size > 0 ? CL_SUCCESS : CL_DEVICE_NOT_AVAILABLE);
		m_devices.reset(new cl_device_id[size]);
		ERROR_HANDLER(
				ERROR = opencl::clGetContextInfo( context_, CL_CONTEXT_DEVICES, size, m_devices.get(), NULL ));

		if (m_settings.m_profile)
		{
			m_settings.m_cmd_queue_properties |= CL_QUEUE_PROFILING_ENABLE;
		}

		ERROR_HANDLER(
				queue_ = opencl::clCreateCommandQueue( context_, m_devices.get()[ 0 ], m_settings.m_cmd_queue_properties, &ERROR ));
		// $$$$ 2010-03-09 SILVIN: harcoded on first device
	}

	~context()
	{
		//std::cout << std::endl << "Flushing command q to free OpenCL context";
		ERROR_HANDLER( ERROR = opencl::clFlush( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clFinish( queue_ ));

		ERROR_HANDLER( ERROR = opencl::clReleaseCommandQueue( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clReleaseContext( context_ ));
		//std::cout << std::endl << "OpenCL context freed";
	}

	cl_mem create_buffer(size_t buffer_size) const
	{
		cl_mem buff;
		ERROR_HANDLER(
				buff = opencl::clCreateBuffer( this->native_context(), CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
				buffer_size, NULL, &ERROR ));

		return buff;
	}

	void release_buffer(cl_mem memory_handle)
	{
		ERROR_HANDLER( ERROR = opencl::clReleaseMemObject( memory_handle ));
	}

	void transfer_to_buffer(cl_mem buffer_handle, void * buffer_data,
			size_t buffer_size) const
	{
		ERROR_HANDLER(
				ERROR = opencl::clEnqueueReadBuffer( this->default_queue(), buffer_handle, CL_TRUE, 0, buffer_size, buffer_data, 0, NULL, NULL ));
	}

	void transfer_from_buffer(cl_mem buffer_handle, void * buffer_data,
			size_t buffer_size) const
	{
		ERROR_HANDLER(
				ERROR = opencl::clEnqueueWriteBuffer( this->default_queue(), buffer_handle, CL_TRUE, 0, buffer_size, buffer_data, 0, NULL, NULL ));
	}

	/*    virtual cl_mem download_buffer( cl_mem buffer, size_t size ) const = 0;

	 ERROR_HANDLER( handle.mem_ = wrapper.clCreateBuffer( context.native_context(),
	 CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
	 handle.value_size * count, NULL, &ERROR ) );*/

	std::auto_ptr<clever::ikernel_proxy> create(const std::string& name,
			const std::string& sources) const
	{
		//std::cout << "Compiling kernel " << name ;
		//std::cout << " Build Options: " << build_options_ << std::endl;

		// todo: make this more generic
		// add to the source code
		std::stringstream final_source;

		// insert new lines
		std::string sFind(";");
		std::string sReplace(";\n");
		std::string local_sources(sources);
		//boost::replace_all( local_sources, sFind, sReplace );
		//boost::replace_all( local_sources, ",", ",\n" );

		if ((m_settings.m_platform_name == opencl::PlatformNameAMD())
				&& (m_settings.m_device_type == opencl::gpu))
		{
			// special dbl precision floating point flag for AMD GPUs
			final_source << "#pragma OPENCL EXTENSION cl_amd_fp64: enable"
					<< std::endl;
		}
		else
		{
			final_source << "#pragma OPENCL EXTENSION cl_khr_fp64: enable"
					<< std::endl;
		}

		//boost::replace_all( sources, ";", ";\n" );

		final_source << local_sources << std::endl;
		std::string final_sources_str(final_source.str());

		char * line_buffer[2048];

		typedef std::vector<std::string> split_vector_type;

		split_vector_type SplitVec; // #2: Search for tokens
		boost::split(SplitVec, final_sources_str, boost::is_any_of(";"),
				boost::token_compress_on);

		size_t line_count = 0;
		for (auto & one_line : SplitVec)
		{
			if (line_count < (SplitVec.size() - 1))
				one_line += ";";

			line_buffer[line_count] = const_cast<char *>(one_line.c_str());
			line_count++;

			//std::cout << std::endl << one_line;
		}

		//const ::size_t size = final_sources_str.size();
		//const char* buffer = final_sources_str.c_str();
		//buffer[ size + 1 ] = null;
		//size++;

		cl_program program;
		ERROR_HANDLER(
				program = opencl::clCreateProgramWithSource( context_, line_count, (const char**) &line_buffer[0], NULL, &ERROR ));
		//std::cout << std::endl << build_options_;
		// passing the build options here wastes the NVIDIA SDK somehow, even the option are "" ??s
		//cl_int build_result = wrapper_.clBuildProgram( program, 0, NULL, build_options_.c_str(), NULL, NULL );
		cl_int build_result = opencl::clBuildProgram(program, 0, NULL, "", NULL,
				NULL);

		char char_out[1024];
		size_t char_out_size = 1024;
		size_t char_out_final;

		cl_device_id dev_id = *m_devices;

		if (build_result != CL_SUCCESS)
		{
			opencl::clGetProgramBuildInfo(program, dev_id, CL_PROGRAM_BUILD_LOG,
					char_out_size, &char_out, &char_out_final);

			std::cout << std::endl << " Source: ";
			std::cout << std::endl << final_sources_str << std::endl;

			std::cout << std::endl << "Compile error:" << char_out << std::endl;
			throw std::runtime_error(
					"OpenCL error while compiling kernel " + name);
		}

		//std::cout << "Compile done" << std::endl;

		return std::auto_ptr<clever::ikernel_proxy>(
				new clever::kernel_proxy(name, program));
	}

	void finish_default_queue() const
	{
		ERROR_HANDLER( ERROR = opencl::clFlush( default_queue() ));
		ERROR_HANDLER( ERROR = opencl::clFinish( default_queue() ));
	}

	cl_event execute_params(kernel_parameter_list const& parameter,
			const clever::ikernel_proxy& proxy, const clever::range & r,
			const bool reverseParameters = false) const
	{
		return proxy.execute_params(parameter, context_, queue_, r,
				reverseParameters);
	}

	void add_profile_event(cl_event evt, std::string evt_name)
	{

	}

	void add_source_modifier(source_modifier * mod)
	{
		m_source_modifier.push_back(mod);
	}

	bool is_profile() const
	{
		return m_settings.m_profile;
	}

	void report_profile(cl_event ev, profile_info & pinfo) const
	{
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_QUEUED, sizeof ( cl_ulong), &pinfo.queued, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_SUBMIT, sizeof ( cl_ulong), &pinfo.submit, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_START, sizeof ( cl_ulong), &pinfo.start, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_END, sizeof ( cl_ulong), &pinfo.end, NULL ));
	}

	/*
	 virtual void execute_params_var(
	 const openclam::ikernel_proxy& k,
	 const openclam::range & r,
	 kernel_parameter const& kp1) const
	 {
	 proxy.execute_params_var( k, r, kp1);
	 }*/

	const cl_command_queue default_queue() const
	{
		return queue_;
	}
	const cl_context native_context() const
	{
		return context_;
	}

private:

	context_settings m_settings;

	cl_context context_;
	cl_command_queue queue_;
	//cl_device_id m_devices;

	std::auto_ptr<cl_device_id> m_devices;

	boost::ptr_vector<source_modifier> m_source_modifier;
};

}
