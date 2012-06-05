//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_IOPENCL_HPP_INCLUDED
#define OPENCLAM_IOPENCL_HPP_INCLUDED

#include "icontext.hpp"
#include <CL/cl.h>
#include <CL/cl_ext.h>
#include <boost/noncopyable.hpp>

namespace openclam
{

class iopencl : private boost::noncopyable
{
public:


             iopencl() {}
    virtual ~iopencl() {}

    virtual cl_uint getDeviceMaxComputeUnits ( cl_device_id dev_id ) const = 0;

    virtual cl_uint getPlatformDeviceMaxComputeUnits ( icontext::device_type type, std::string platformName = ""  ) const = 0;


    virtual cl_context createContext( icontext::device_type type, std::string platformName = "", int limitComputeUnits = -1 ) const = 0;

    virtual cl_int clGetContextInfo( cl_context context,
                                     cl_context_info param_name,
                                     ::size_t param_value_size,
                                     void* param_value,
                                     ::size_t* param_value_size_ret ) const = 0;

    virtual cl_command_queue clCreateCommandQueue( cl_context context,
                                                   cl_device_id device, 
                                                   cl_command_queue_properties properties,
                                                   cl_int* errcode_ret ) const = 0;

    virtual cl_int clReleaseCommandQueue( cl_command_queue command_queue ) const = 0;

    virtual cl_int clReleaseContext( cl_context context ) const = 0;

    virtual cl_program clCreateProgramWithSource( cl_context context,
                                                  cl_uint count,
                                                  const char** strings,
                                                  const ::size_t* lengths,
                                                  cl_int* errcode_ret ) const = 0;

    virtual cl_mem clCreateBuffer( cl_context context,
                                   cl_mem_flags flags,
                                   ::size_t size,
                                   void* host_ptr,
                                   cl_int* errcode_ret ) const = 0;

    virtual cl_int clSetKernelArg( cl_kernel kernel,
                                   cl_uint arg_index,
                                   ::size_t arg_size,
                                   const void* arg_value ) const = 0;

    virtual cl_int clEnqueueWriteBuffer( cl_command_queue command_queue, 
                                         cl_mem buffer, 
                                         cl_bool blocking_write, 
                                         ::size_t offset,
                                         ::size_t cb,
                                         const void* ptr, 
                                         cl_uint num_events_in_wait_list, 
                                         const cl_event* event_wait_list, 
                                         cl_event* event ) const = 0;

    virtual cl_int clEnqueueNDRangeKernel( cl_command_queue command_queue,
                                           cl_kernel kernel,
                                           cl_uint work_dim,
                                           const ::size_t* global_work_offset,
                                           const ::size_t* global_work_size,
                                           const ::size_t* local_work_size,
                                           cl_uint num_events_in_wait_list,
                                           const cl_event* event_wait_list,
                                           cl_event* event ) const = 0;

    virtual cl_int clEnqueueReadBuffer( cl_command_queue command_queue,
                                        cl_mem buffer,
                                        cl_bool blocking_read,
                                        ::size_t offset,
                                        ::size_t cb,
                                        void* ptr,
                                        cl_uint num_events_in_wait_list,
                                        const cl_event* event_wait_list,
                                        cl_event* event ) const = 0;

    virtual cl_int clReleaseMemObject( cl_mem memobj ) const = 0;

    virtual cl_int clGetEventProfilingInfo ( 	cl_event ev,
												cl_profiling_info param_name,
												size_t param_value_size,
												void *param_value,
												size_t *param_value_size_ret) const = 0;

    virtual cl_int clBuildProgram( cl_program program,
                                   cl_uint num_devices,
                                   const cl_device_id* device_list,
                                   const char* options, 
                                   void ( *pfn_notify )( cl_program program, void* user_data ),
                                   void* user_data ) const = 0;

    virtual cl_int clGetProgramBuildInfo ( 	cl_program  program,
											cl_device_id  device,
											cl_program_build_info  param_name,
											size_t  param_value_size,
											void  *param_value,
											size_t  *param_value_size_ret) const = 0;

    virtual cl_int clFinish ( 	cl_command_queue command_queue) const = 0;
    virtual cl_int clFlush ( 	cl_command_queue command_queue) const = 0;


    virtual cl_int clReleaseProgram( cl_program program ) const = 0;

    virtual cl_kernel clCreateKernel( cl_program program,
                                      const char* kernel_name,
                                      cl_int* errcode_ret ) const = 0;
    
    virtual cl_int clReleaseKernel( cl_kernel clKernel ) const = 0;
};

}

#endif // #ifndef OPENCLAM_IOPENCL_HPP_INCLUDED
