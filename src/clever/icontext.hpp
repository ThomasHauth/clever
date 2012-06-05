//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_ICONTEXT_HPP_INCLUDED
#define OPENCLAM_ICONTEXT_HPP_INCLUDED

#include <memory>
#include <string>
#include <boost/noncopyable.hpp>

#include "ikernel_proxy.hpp"
#include "range.hpp"


namespace openclam
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
    enum device_type
    {
        default_    = CL_DEVICE_TYPE_DEFAULT,
        cpu         = CL_DEVICE_TYPE_CPU,
        gpu         = CL_DEVICE_TYPE_GPU,
        accelerator = CL_DEVICE_TYPE_ACCELERATOR,
        device_all         = CL_DEVICE_TYPE_ALL
    };

             icontext() {}
    virtual ~icontext() {}

    virtual std::auto_ptr< openclam::ikernel_proxy > create( const std::string& name,
    		const std::string& sources ) const = 0;

    virtual void execute( void* data, ::size_t size, const openclam::ikernel_proxy& k ) const = 0;

    virtual cl_event execute_params( kernel_parameter_list const& parameter,
    		 const openclam::ikernel_proxy& k,
    		 const openclam::range & r,
    		 const bool reverseParameters = false ) const = 0;

/*
    virtual void execute_params_var(
    		 const openclam::ikernel_proxy& k,
    		 const openclam::range & r,
    		 kernel_parameter const& kp1) const = 0;

    virtual void execute_params_var(
    		 const openclam::ikernel_proxy& k,
    		 const openclam::range & r,
    		 kernel_parameter const& kp1,
    		 kernel_parameter const& kp2) const = 0;*/
/*
    virtual void execute_params_var(
    		 const openclam::ikernel_proxy& k,
    		 const openclam::range & r,
    		 kernel_parameter const& kp1,
    		 kernel_parameter const& kp2,
    		 kernel_parameter const& kp3) const = 0;*/

    virtual const cl_command_queue default_queue() const = 0;
    virtual const cl_context native_context() const = 0;
    virtual void finish_default_queue() const = 0;

    virtual void add_profile_event( cl_event evt, std::string evt_name ) = 0;
    virtual bool is_profile() const = 0;
    virtual void report_profile( cl_event e, profile_info & pinfo) const = 0;


    // do all the memory management within the context ....

};
}

#endif // #ifndef OPENCLAM_ICONTEXT_HPP_INCLUDED
