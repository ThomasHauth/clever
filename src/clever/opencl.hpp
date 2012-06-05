//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_OPENCL_HPP_INCLUDED
#define OPENCLAM_OPENCL_HPP_INCLUDED

#include <stdexcept>

#include "iopencl.hpp"
#include "error.hpp"


namespace openclam
{

class opencl : public iopencl
{
public:
             opencl() {}
    virtual ~opencl() {}

    //const std::string PlatformNameIntel = "Intel(R) OpenCL";
    //const std::string PlatformNameNVIDIA = "NVIDIA CUDA";
    //const std::string PlatformNameAMD = "AMD Accelerated Parallel Processing";

    static std::string PlatformNameIntel()
    {
    	return "Intel(R) OpenCL";
    }

    static std::string PlatformNameNVIDIA()
    {
    	return "NVIDIA CUDA";
    }
    static std::string PlatformNameAMD()
    {
    	return "AMD Accelerated Parallel Processing";
    }

    static std::string GetPlatformNameShort( std::string const& name)
    {
    	if ( name == PlatformNameIntel())
    		return "intel";
    	if ( name == PlatformNameNVIDIA())
    		return "nvidia";
    	if ( name == PlatformNameAMD())
    		return "amd";
    	else
    		throw new std::runtime_error( "Unknown OpenCL Platform " + name);
    }

    virtual cl_uint getPlatformDeviceMaxComputeUnits ( icontext::device_type type, std::string platformName = ""  ) const
    {

        cl_device_id dev;
        dev = getDeviceId( platformName, type );

        return getDeviceMaxComputeUnits( dev );

    }

    virtual cl_context createContext( icontext::device_type dev_type,
    		std::string platformName = "",
    		int limitComputeUnits = -1 ) const
    {
        cl_context result;

       // PrintInformation();

// * 	old and easier version which did not work with VTune
/*        cl_context_properties props[3];
        props[0] = (cl_context_properties)CL_CONTEXT_PLATFORM;  // indicates that next element is platform
        props[1] = (cl_context_properties) getDefaultPlatformId();  // platform is of type cl_platform_id
        props[2] = (cl_context_properties)0;   // last element must be 0

        ERROR_HANDLER( result = ::clCreateContextFromType( props, type, NULL, NULL, &ERROR ) );
*/
/*
        cl_context_properties props[3];
        props[0] = (cl_context_properties)CL_CONTEXT_PLATFORM;  // indicates that next element is platform
        props[1] = (cl_context_properties) getDefaultPlatformId();  // platform is of type cl_platform_id
        props[2] = (cl_context_properties)0;   // last element must be 0
*/
        cl_device_id devs[1];
        devs[0] = getDeviceId( platformName, dev_type );
		//does not work with the AMD SDK
     /*
	not supported by amd*/
   if ( limitComputeUnits > 0)
        {
			cl_uint part_count = 1;
			cl_device_id device_id_part[1];
			const cl_device_partition_property_ext part_props[] = {
					CL_DEVICE_PARTITION_BY_COUNTS_EXT,
					// somehow we must add +1 here for the system to use actually the correct number
					// not understood why, yet
					(cl_device_partition_property_ext)limitComputeUnits +1,
					CL_PARTITION_BY_COUNTS_LIST_END_EXT,
					CL_PROPERTIES_LIST_END_EXT };

			ERROR_HANDLER( ERROR =  ::clCreateSubDevicesEXT( devs[0], part_props, 1, device_id_part, &part_count) );

			// we have a new device which must be used to create the context
			devs[0] = device_id_part[0];
        }

        ERROR_HANDLER( result = ::clCreateContext( NULL, 1, devs , NULL, NULL, &ERROR  ) );

        return result;
    }

    virtual cl_int clGetContextInfo( cl_context context,
                                     cl_context_info param_name, 
                                     ::size_t param_value_size,
                                     void* param_value, 
                                     ::size_t* param_value_size_ret ) const
    {
        return ::clGetContextInfo( context, param_name, param_value_size, param_value, param_value_size_ret );
    }

    virtual cl_command_queue clCreateCommandQueue( cl_context context,
                                                   cl_device_id device, 
                                                   cl_command_queue_properties properties,
                                                   cl_int* errcode_ret ) const
    {
        return ::clCreateCommandQueue( context, device, properties, errcode_ret );
    }

    virtual cl_int clReleaseCommandQueue( cl_command_queue command_queue ) const
    {
        return ::clReleaseCommandQueue( command_queue );
    }

    virtual cl_int clReleaseContext( cl_context context ) const
    {
        return ::clReleaseContext( context );
    }

    virtual cl_int clGetEventProfilingInfo ( 	cl_event ev,
												cl_profiling_info param_name,
												size_t param_value_size,
												void *param_value,
												size_t *param_value_size_ret) const
    {
    	return ::clGetEventProfilingInfo( ev,
    			param_name,
    			param_value_size,
    			param_value,
    			param_value_size_ret );
    }


    virtual cl_program clCreateProgramWithSource( cl_context context,
                                                  cl_uint count,
                                                  const char** strings,
                                                  const ::size_t* lengths,
                                                  cl_int* errcode_ret ) const
    {
        return ::clCreateProgramWithSource( context, count, strings, lengths, errcode_ret );
    }

    virtual cl_mem clCreateBuffer( cl_context context,
                                   cl_mem_flags flags,
                                   ::size_t size,
                                   void* host_ptr,
                                   cl_int* errcode_ret ) const
    {
        return ::clCreateBuffer( context, flags, size, host_ptr, errcode_ret );
    }

    virtual cl_int clSetKernelArg( cl_kernel clkernel,
                                   cl_uint arg_index,
                                   ::size_t arg_size,
                                   const void* arg_value ) const
    {
        return ::clSetKernelArg( clkernel, arg_index, arg_size, arg_value );
    }

    virtual cl_int clFinish ( 	cl_command_queue command_queue) const
    {
    	return ::clFinish( command_queue );
    }

    virtual cl_int clFlush ( 	cl_command_queue command_queue) const
    {
    	return ::clFlush( command_queue );
    }


    virtual cl_int clEnqueueWriteBuffer( cl_command_queue command_queue, 
                                         cl_mem buffer, 
                                         cl_bool blocking_write, 
                                         ::size_t offset,
                                         ::size_t cb,
                                         const void* ptr, 
                                         cl_uint num_events_in_wait_list, 
                                         const cl_event* event_wait_list, 
                                         cl_event* event ) const
    {
        return ::clEnqueueWriteBuffer( command_queue, buffer, blocking_write, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event );
    }

    virtual cl_int clEnqueueNDRangeKernel( cl_command_queue command_queue,
                                           cl_kernel clkernel,
                                           cl_uint work_dim,
                                           const ::size_t* global_work_offset,
                                           const ::size_t* global_work_size,
                                           const ::size_t* local_work_size,
                                           cl_uint num_events_in_wait_list,
                                           const cl_event* event_wait_list,
                                           cl_event* event ) const
    {
        return ::clEnqueueNDRangeKernel( command_queue, clkernel, work_dim, global_work_offset, global_work_size,
                                         local_work_size, num_events_in_wait_list, event_wait_list, event );
    }

    virtual cl_int clEnqueueReadBuffer( cl_command_queue command_queue,
                                        cl_mem buffer,
                                        cl_bool blocking_read,
                                        size_t offset,
                                        ::size_t cb,
                                        void* ptr,
                                        cl_uint num_events_in_wait_list,
                                        const cl_event* event_wait_list,
                                        cl_event* event ) const
    {
        return ::clEnqueueReadBuffer( command_queue, buffer, blocking_read, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event );
    }

    virtual cl_int clReleaseMemObject( cl_mem memobj ) const
    {
        return ::clReleaseMemObject( memobj );
    }

    virtual cl_int clBuildProgram( cl_program program,
                                   cl_uint num_devices,
                                   const cl_device_id* device_list,
                                   const char* options, 
                                   void ( *pfn_notify )( cl_program program, void* user_data ),
                                   void* user_data ) const
    {
        return ::clBuildProgram( program, num_devices, device_list, options, pfn_notify, user_data );
    }

    virtual cl_int clReleaseProgram( cl_program program ) const
    {
        return ::clReleaseProgram( program );
    }

    virtual cl_kernel clCreateKernel( cl_program program,
                                      const char* kernel_name,
                                      cl_int* errcode_ret ) const
    {
        return ::clCreateKernel( program, kernel_name, errcode_ret );
    }

    virtual cl_int clReleaseKernel( cl_kernel clKernel ) const
    {
        return ::clReleaseKernel( clKernel );
    }

    // ugly stuff by thomas

    static  cl_platform_id getPlatformId( std::string platformName = "")
    {
		char char_out[1024];
		size_t char_out_size = 1024;
		size_t char_out_final;

		cl_platform_id platforms[32];
		cl_uint numPlatforms;
		ERROR_HANDLER ( ERROR = ::clGetPlatformIDs ( 32, platforms, &numPlatforms ) );

		assert ( numPlatforms > 0 );

		if ( platformName == "")
			return platforms[0];

		for ( size_t i = 0; i < numPlatforms; ++ i )
		{
			::clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, char_out_size, &char_out, &char_out_final );

			std::string pname ( char_out );
			if ( pname == platformName)
			{
				std::cout << std::endl << "Found platform " << platformName;
				return platforms[i];
			}
		}

        throw std::runtime_error( "Openclam error: Platform with name " + platformName + " not found." );
    }

    static cl_device_id getDeviceId( std::string platformName = "",
    		openclam::icontext::device_type dev_type = openclam::icontext::device_all )
    {
		cl_platform_id platform_id = getPlatformId(platformName);
		cl_device_id devices[32];
		cl_uint numDevices;

		std::cout << std::endl << "Loading Device for platform " << platformName;
		ERROR_HANDLER ( ERROR = ::clGetDeviceIDs ( platform_id, dev_type,
				32, devices, &numDevices ) );


		return devices[0];
    }

    virtual cl_int clGetProgramBuildInfo ( 	cl_program  program,
											cl_device_id  device,
											cl_program_build_info  param_name,
											size_t  param_value_size,
											void  *param_value,
											size_t  *param_value_size_ret) const
    {
    	return :: clGetProgramBuildInfo ( program,
    										device,
											param_name,
											param_value_size,
											param_value,
											param_value_size_ret);
    }

    virtual cl_uint getDeviceMaxComputeUnits ( cl_device_id dev_id ) const
    {
    	cl_uint intTmp;
    	ERROR_HANDLER ( ERROR = ::clGetDeviceInfo( dev_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof( cl_uint), &intTmp, NULL ) );
		return intTmp;
    }

	static void PrintInformation()
	{
		cl_platform_id platforms[10];
		cl_uint numPlatforms;
		char char_out[1024];
		size_t char_out_size = 1024;
		size_t char_out_final;


		ERROR_HANDLER ( ERROR = ::clGetPlatformIDs ( 10, platforms, &numPlatforms ) );

		std::cout << "OpenCL Platforms :: " << numPlatforms << " available" << std::endl;

		for ( unsigned int i = 0; i < numPlatforms; ++ i)
		{
			std::cout  << std::endl << "  Platform Id: " << platforms[i] << std::endl;
			::clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, char_out_size, &char_out, &char_out_final );
			std::cout << "  Platform Name: " << char_out << std::endl;
			::clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, char_out_size, &char_out, &char_out_final );
			std::cout << "  Platform Vendor: " << char_out << std::endl;
			::clGetPlatformInfo(platforms[i], CL_PLATFORM_PROFILE, char_out_size, &char_out, &char_out_final );
			std::cout << "  Platform Profile: " << char_out << std::endl;


			cl_device_id devices[1024];
			cl_uint numDevices;
			cl_uint intTmp;
			ERROR_HANDLER ( ERROR = ::clGetDeviceIDs ( platforms[i], CL_DEVICE_TYPE_ALL, 1024, devices, &numDevices ) );

			std::cout << std::endl << "     Devices = " << numDevices << std::endl;
			for ( size_t i_dev = 0; i_dev < numDevices; ++ i_dev )
			{
				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_NAME, char_out_size, &char_out, &char_out_final );
				std::cout << "     Devices Name: " << char_out << std::endl;
				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_VERSION, char_out_size, &char_out, &char_out_final );
				std::cout << "     Devices Version: " << char_out << std::endl;
				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_OPENCL_C_VERSION, char_out_size, &char_out, &char_out_final );
				std::cout << "     Devices OpenCL C Version: " << char_out << std::endl;
				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof( cl_uint), &intTmp, NULL );
				std::cout << "     Devices Max Compute Units: " << intTmp << std::endl;

				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof( cl_uint), &intTmp, NULL );
				std::cout << "     Devices Max Work Group Size: " << intTmp << std::endl;
				::clGetDeviceInfo( devices[i_dev], CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof( cl_uint), &intTmp, NULL );
				std::cout << "     Devices Max Work Item Size: " << intTmp << std::endl;

			}

			/*			std::string pName;
			std::string pVend;
			std::string pExt;
			std::string pVersion;
			std::string pProfile;

			p.getInfo ( CL_PLATFORM_NAME , &pName );
			p.getInfo ( CL_PLATFORM_VENDOR , &pVend );
			p.getInfo ( CL_PLATFORM_EXTENSIONS , &pExt );
			p.getInfo ( CL_PLATFORM_VERSION , &pVersion );
			p.getInfo ( CL_PLATFORM_PROFILE , &pProfile );

			std::cout << "Name: " << pName << "  Version: " << pVersion << std::endl;
			std::cout << "Vendor: " << pVend << std::endl;
			std::cout << "Profile: " << pProfile << std::endl;
			std::cout << "Extensions: " << pExt << std::endl;

			VECTOR_CLASS < cl::Device > devices;

			p.getDevices( CL_DEVICE_TYPE_ALL, & devices );

			std::cout<< std::endl << "Devices :: " << std::endl;

			for ( auto d : devices )
			{
				std::string dName, dProfile, dVersion, dVersionCL, dExt;

				d.getInfo( CL_DEVICE_NAME, &dName );
				d.getInfo( CL_DEVICE_PROFILE, &dProfile );
				d.getInfo( CL_DEVICE_VERSION, &dVersion);
				d.getInfo( CL_DEVICE_OPENCL_C_VERSION, &dVersionCL);
				d.getInfo ( CL_DEVICE_EXTENSIONS , &dExt );

				std::cout << "Device Name: " << dName << "  Version: " << dVersion << std::endl;
				std::cout << "Device Profile: " << dProfile << std::endl;
				std::cout << "Device OpenCL Version: " << dVersionCL << std::endl;
				std::cout << "Device Extensions: " << dExt << std::endl;
			}*/
		}
	}

};

}

#endif // #ifndef OPENCLAM_OPENCL_HPP_INCLUDED
