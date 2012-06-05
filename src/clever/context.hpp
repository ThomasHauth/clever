//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_CONTEXT_HPP_INCLUDED
#define OPENCLAM_CONTEXT_HPP_INCLUDED

#include <boost/algorithm/string.hpp>

#include "error.hpp"
#include "iopencl.hpp"
#include "icontext.hpp"
#include "kernel_proxy.hpp"
#include "opencl.hpp"

namespace openclam
{

class context : public openclam::icontext
{
public:
    context( const openclam::iopencl& wrapper, std::string platformName = "", icontext::device_type type = default_,
    		const std::string& build_options = "",
    		cl_command_queue_properties cmd_queue_properties = 0,
    		const bool profile = false,
    		const int useComputeUnits = -1) // "-1 means no limit
        : used_compute_units ( useComputeUnits  ),
          wrapper_( wrapper ),
          build_options_ ( build_options ),
          is_profile_ ( profile )
    {
        context_ = wrapper_.createContext( type, platformName, useComputeUnits );
        ::size_t size;
        ERROR_HANDLER( ERROR = wrapper_.clGetContextInfo( context_, CL_CONTEXT_DEVICES, 0, NULL, &size ) );
        ERROR_HANDLER( ERROR = size > 0 ? CL_SUCCESS : CL_DEVICE_NOT_AVAILABLE );
        devices_.reset( new cl_device_id[ size ] );
        ERROR_HANDLER( ERROR = wrapper_.clGetContextInfo( context_, CL_CONTEXT_DEVICES, size, devices_.get(), NULL ) );

	m_platformName = platformName;
	m_deviceType = type;

        if ( is_profile_ )
        {
        	cmd_queue_properties |= CL_QUEUE_PROFILING_ENABLE;
        }

        ERROR_HANDLER( queue_ = wrapper_.clCreateCommandQueue( context_,
        		devices_.get()[ 0 ],
        		cmd_queue_properties,
        		&ERROR ) ); // $$$$ 2010-03-09 SILVIN: harcoded on first device
    }
    virtual ~context()
    {
    	std::cout << std::endl << "Flushing command q to free OpenCL context";
    	ERROR_HANDLER( ERROR = wrapper_.clFlush( queue_ ) );
    	ERROR_HANDLER( ERROR = wrapper_.clFinish( queue_ ) );

    	ERROR_HANDLER( ERROR = wrapper_.clReleaseCommandQueue( queue_ ) );
        ERROR_HANDLER( ERROR = wrapper_.clReleaseContext( context_ ) );
        std::cout << std::endl << "OpenCL context freed";
    }

    virtual std::auto_ptr< openclam::ikernel_proxy > create( const std::string& name,
    		const std::string& sources ) const
    {
    	//std::cout << "Compiling kernel " << name ;
    	//std::cout << " Build Options: " << build_options_ << std::endl;

    	// todo: make this more generic
    	// add to the source code
    	std::stringstream final_source;

    	// insert new lines
    	std::string sFind (";");
    	std::string sReplace ( ";\n");
    	std::string local_sources ( sources );
    	//boost::replace_all( local_sources, sFind, sReplace );
    	//boost::replace_all( local_sources, ",", ",\n" );

	if ( ( m_platformName == opencl::PlatformNameAMD() ) && 
	     ( m_deviceType == icontext::gpu ))
	{
		// special dbl precision floating point flag for AMD GPUs
	    	final_source << "#pragma OPENCL EXTENSION cl_amd_fp64: enable" <<std::endl;
	}
	else
	{
		final_source << "#pragma OPENCL EXTENSION cl_khr_fp64: enable" <<std::endl;
	}

    	//boost::replace_all( sources, ";", ";\n" );

    	final_source << local_sources << std::endl;
    	std::string final_sources_str ( final_source.str() );

    	char * line_buffer[2048];

        typedef std::vector< std::string > split_vector_type;

        split_vector_type SplitVec; // #2: Search for tokens
        boost::split( SplitVec, final_sources_str , boost::is_any_of(";"), boost::token_compress_on );

        int line_count = 0;
        for ( auto & one_line : SplitVec )
        {
        	if ( line_count <  ( SplitVec.size() - 1 ))
        		one_line += ";";

        	line_buffer[line_count] = const_cast<char *>( one_line.c_str() );
        	line_count++;

        	//std::cout << std::endl << one_line;
        }

        //const ::size_t size = final_sources_str.size();
        //const char* buffer = final_sources_str.c_str();
        //buffer[ size + 1 ] = null;
        //size++;

        cl_program program;
        ERROR_HANDLER( program = wrapper_.clCreateProgramWithSource( context_,
        		line_count,
        		(const char**) &line_buffer[0],
        		NULL , &ERROR ) );
        //std::cout << std::endl << build_options_;
        // passing the build options here wastes the NVIDIA SDK somehow, even the option are "" ??s
        //cl_int build_result = wrapper_.clBuildProgram( program, 0, NULL, build_options_.c_str(), NULL, NULL );
        cl_int build_result = wrapper_.clBuildProgram( program, 0, NULL, "", NULL, NULL );

		char char_out[1024];
		size_t char_out_size = 1024;
		size_t char_out_final;

		cl_device_id dev_id = *devices_;

        if ( build_result != CL_SUCCESS )
        {
        	wrapper_.clGetProgramBuildInfo ( program,
        			dev_id,
        			CL_PROGRAM_BUILD_LOG,
        			char_out_size,
        		  	&char_out,
        		  	&char_out_final);

        	std::cout << std::endl << " Source: ";
        	std::cout << std::endl << final_sources_str << std::endl;

        	std::cout << std::endl << "Compile error:" << char_out << std::endl;
                throw std::runtime_error( "Openclam error while compiling kernel " + name );
        }

        std::cout << "Compile done" << std::endl;

        return std::auto_ptr< openclam::ikernel_proxy >( new openclam::kernel_proxy( name, wrapper_, program ) );
    }

    virtual void finish_default_queue() const
	{
    	ERROR_HANDLER( ERROR = wrapper_.clFlush( default_queue() ));
    	ERROR_HANDLER( ERROR = wrapper_.clFinish( default_queue() ));
	}


    virtual void execute( void* data, ::size_t size, const openclam::ikernel_proxy& proxy ) const
    {
        proxy.execute( data, size, context_, queue_ );
    }

    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		 const openclam::ikernel_proxy& proxy,
    		 const openclam::range & r,
    		 const bool reverseParameters = false ) const
    {
        return proxy.execute_params( parameter,  context_, queue_, r, reverseParameters );
    }


    virtual void add_profile_event( cl_event evt, std::string evt_name )
    {

    }

    virtual bool is_profile() const
    {
    	return is_profile_;
    }

    virtual void report_profile(cl_event ev, profile_info & pinfo) const
    {
    	ERROR_HANDLER( ERROR = wrapper_.clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_QUEUED, sizeof ( cl_ulong), &pinfo.queued, NULL ) );
    	ERROR_HANDLER( ERROR = wrapper_.clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_SUBMIT, sizeof ( cl_ulong), &pinfo.submit, NULL ) );
    	ERROR_HANDLER( ERROR = wrapper_.clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_START, sizeof ( cl_ulong), &pinfo.start, NULL ) );
    	ERROR_HANDLER( ERROR = wrapper_.clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_END, sizeof ( cl_ulong), &pinfo.end, NULL ) );
    }

/*
    virtual void execute_params_var(
    		 const openclam::ikernel_proxy& k,
    		 const openclam::range & r,
    		 kernel_parameter const& kp1) const
    {
    	proxy.execute_params_var( k, r, kp1);
    }*/


    virtual const cl_command_queue default_queue() const { return queue_; }
    virtual const cl_context native_context() const { return context_; }

    int used_compute_units;

private:
    const openclam::iopencl& wrapper_;
    const std::string & build_options_;
    cl_context context_;
    cl_command_queue queue_;
    //cl_device_id devices_;
    std::auto_ptr< cl_device_id > devices_;
    bool is_profile_;
    std::string m_platformName;
    icontext::device_type m_deviceType;

};

}

#endif // #ifndef OPENCLAM_CONTEXT_HPP_INCLUDED
