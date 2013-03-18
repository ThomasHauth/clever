//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "opencl.hpp"
#include "ikernel_proxy.hpp"
#include "kernel_parameter.hpp"
#include "range.hpp"

namespace clever
{

class kernel_proxy : public clever::ikernel_proxy
{
public:
    kernel_proxy( const std::string& name,  cl_program program, const std::string & program_soure )
       : program_( program )
    	, _kernel_name( name )
    	, m_kernelSource ( program_soure)

    {
        ERROR_HANDLER( kernel_ = opencl::clCreateKernel( program_, name.c_str(), &ERROR ) );
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


    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		cl_context context, cl_command_queue queue,
    		const clever::range & globalRange, const clever::range & localRange,
    		const bool reverseParameters = false) const
    {
    	// pass parameter
    	unsigned int parameter_number = 0;
    	//for ( auto const& kp: parameter)
    	for ( kernel_parameter_list::const_iterator it = parameter.begin();
    		  it != parameter.end(); ++ it )
    	{
    		ERROR_HANDLER( ERROR =
    		opencl::clSetKernelArg( kernel_,
    				parameter_number,
    				it->size_,
    				it->buffer_ )
    				);

			++ parameter_number;
    	}

    	cl_event evt = 0;
    	// enque kernel
    	ERROR_HANDLER( ERROR = opencl::clEnqueueNDRangeKernel( queue, kernel_,
    			globalRange.dimension(), //  work_dim
    			NULL, // global_work_offset
    			globalRange.sizes(), // global_work_size
    			localRange.sizes() , // local_work_size
    			0, // num_events_in_wait_list
    			NULL, // event_wait_list
    			&evt) // event
    			);

    	return evt;
    }

    virtual std::string const& getSource() const
    {
    	return m_kernelSource;
    }

    virtual cl_kernel native_kernel() const {
    	return kernel_;
    }

    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const clever::range & r,
    		kernel_parameter const& kp1 )
    {

    }


private:
    cl_program program_;
    cl_kernel kernel_;
    std::string _kernel_name;
    std::string m_kernelSource;
};
}
