//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_KERNEL_PROXY_HPP_INCLUDED
#define OPENCLAM_KERNEL_PROXY_HPP_INCLUDED

#include "ikernel_proxy.hpp"
#include "iopencl.hpp"
#include "kernel_parameter.hpp"
#include "range.hpp"

namespace openclam
{

class kernel_proxy : public openclam::ikernel_proxy
{
public:
    kernel_proxy( const std::string& name, const openclam::iopencl& wrapper, cl_program program )
       : wrapper_( wrapper )
       , program_( program )
    	, _kernel_name( name )

    {
        ERROR_HANDLER( kernel_ = wrapper_.clCreateKernel( program_, name.c_str(), &ERROR ) );
    }
    virtual ~kernel_proxy()
    {
    	/*ERROR_HANDLER( ERROR = wrapper_.clReleaseKernel( kernel_ ) );

    	std::cout << std::endl << "Kernel " << _kernel_name << " released";*/
   /*
    * // produced crash, commented for now,
    * The only point where this line becomes problematic is when running the binary
    * with Intels VTune
    * ERROR_HANDLER( ERROR = wrapper_.clReleaseProgram( program_ )); // $$$$ 28-02-2010 SILVIN: check error code?
    	std::cout << std::endl << "Program " << _kernel_name << " released";*/
    }

    virtual void execute( void* data, ::size_t size, cl_context context, cl_command_queue queue ) const
    {/*
        cl_mem arg;
        ERROR_HANDLER( arg = wrapper_.clCreateBuffer( context, CL_MEM_READ_WRITE, size, NULL, &ERROR ) );
        ERROR_HANDLER( ERROR = wrapper_.clSetKernelArg( kernel_, 0, sizeof( cl_mem ), &arg ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueWriteBuffer( queue, arg, CL_TRUE, 0, size, data, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueNDRangeKernel( queue, kernel_, 1, NULL, &size, NULL, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueReadBuffer( queue, arg, CL_TRUE, 0, size, data, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clReleaseMemObject( arg ) );*/
    	assert ( false ); // old code
    }


    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		const bool reverseParameters = false) const
    {
    	// pass parameter
    	unsigned int parameter_number = 0;
    	//for ( auto const& kp: parameter)
    	for ( kernel_parameter_list::const_iterator it = parameter.begin();
    		  it != parameter.end(); ++ it )
    	{
    		ERROR_HANDLER( ERROR =
    		wrapper_.clSetKernelArg( kernel_,
    				parameter_number,
    				it->size_,
    				it->buffer_ )
    				);

			++ parameter_number;
    	}

    	cl_event evt;

    	// enque kernel
    	ERROR_HANDLER( ERROR = wrapper_.clEnqueueNDRangeKernel( queue, kernel_,
    			r.dimension(), //  work_dim
    			NULL, // global_work_offset
    			r.sizes(), // global_work_size
    			NULL , // local_work_size
    			0, // num_events_in_wait_list
    			NULL, // event_wait_list
    			&evt) // event
    			);

    	return evt;
/*        cl_mem arg;
        ERROR_HANDLER( arg = wrapper_.clCreateBuffer( context, CL_MEM_READ_WRITE, size, NULL, &ERROR ) );
        ERROR_HANDLER( ERROR = wrapper_.clSetKernelArg( kernel_, 0, sizeof( cl_mem ), &arg ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueWriteBuffer( queue, arg, CL_TRUE, 0, size, data, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueNDRangeKernel( queue, kernel_, 1, NULL, &size, NULL, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clEnqueueReadBuffer( queue, arg, CL_TRUE, 0, size, data, 0, NULL, NULL ) );
        ERROR_HANDLER( ERROR = wrapper_.clReleaseMemObject( arg ) );*/
    }


    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		kernel_parameter const& kp1 )
    {

    }


private:
    const openclam::iopencl& wrapper_;
    cl_program program_;
    cl_kernel kernel_;
    std::string _kernel_name;
};
}

#endif // #ifndef OPENCLAM_CONTEXT_HPP_INCLUDED
