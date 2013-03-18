//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <cstring>
#include <CL/cl.h>
#include <boost/noncopyable.hpp>
#include "kernel_parameter.hpp"
#include "range.hpp"

namespace clever
{

class ikernel_proxy : private boost::noncopyable
{
public:
             ikernel_proxy() {}
    virtual ~ikernel_proxy() {}

    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		cl_context context, cl_command_queue queue,
    		const clever::range & globalRange, const clever::range * localRange = NULL,
    		const bool reverseParameters = false) const = 0;

    virtual std::string const& getSource () const = 0;

    virtual cl_kernel native_kernel () const = 0;

};

}

