//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <memory>
#include <string>
#include <boost/noncopyable.hpp>

#include "ikernel_proxy.hpp"
#include "range.hpp"


namespace clever
{


struct profile_info
{
	// all in ns
	cl_ulong submit;
	cl_ulong queued;
	cl_ulong start;
	cl_ulong end;

	cl_ulong runtime ()
	{
		return ( end - start );
	}

	cl_ulong timetostart ()
	{
		return ( start - submit );
	}

	void print()
	{

	std::cout << std::endl << "Queued: " << queued;
	std::cout << std::endl << "Submit: " << ( submit - queued )  << " ns";
	std::cout << std::endl << "Start: "  << ( start - queued )  << " ns";
	std::cout << std::endl << "End: "  << ( end - queued )  << " ns";
	std::cout << std::endl << "Runtime: "  << runtime()  << " ns" << std::endl;

	}
};

class icontext : private boost::noncopyable
{
public:



             icontext() {}
    virtual ~icontext() {}

    virtual std::unique_ptr< clever::ikernel_proxy > create( const std::string& name,
    		const std::string& sources ) const = 0;

    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		 const clever::ikernel_proxy& k,
    		 const clever::range & globalRange, const clever::range & localRange,
    		 const bool reverseParameters = false ) const = 0;

    virtual const cl_command_queue default_queue() const = 0;
    virtual const cl_context native_context() const = 0;
    virtual const cl_device_id native_device() const = 0;
    virtual void finish_default_queue() const = 0;

    virtual const cl_ulong getMaxAllocSize() const = 0;
    virtual const cl_ulong getGlobalMemSize() const = 0;
    virtual const cl_ulong getLocalMemSize() const = 0;


    virtual bool is_profile() const = 0;
    virtual profile_info report_profile( cl_event e) const = 0;


    // do all the memory management within the context ....

};
}

