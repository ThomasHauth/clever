//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_IKERNEL_PROXY_HPP_INCLUDED
#define OPENCLAM_IKERNEL_PROXY_HPP_INCLUDED

#include <cstring>
#include <CL/cl.h>
#include <boost/noncopyable.hpp>
#include "kernel_parameter.hpp"
#include "range.hpp"

namespace openclam
{

class ikernel_proxy : private boost::noncopyable
{
public:
             ikernel_proxy() {}
    virtual ~ikernel_proxy() {}

    virtual void execute( void* data, ::size_t size, cl_context context, cl_command_queue queue ) const = 0;
    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		const bool reverseParameters = false) const = 0;
/*
    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		kernel_parameter const& kp1) const = 0;

    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		kernel_parameter const& kp1,
    		kernel_parameter const& kp2) const = 0;

    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		kernel_parameter const& kp1,
    		kernel_parameter const& kp2,
    		kernel_parameter const& kp3
    		) const = 0;

    virtual void execute_params_var(
    		cl_context context, cl_command_queue queue,
    		const openclam::range & r,
    		kernel_parameter const& kp1,
    		kernel_parameter const& kp2,
    		kernel_parameter const& kp3,
    		kernel_parameter const& kp4) const = 0;
*/
};

}

#endif // #ifndef OPENCLAM_IKERNEL_PROXY_HPP_INCLUDED
