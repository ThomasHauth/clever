//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/noncopyable.hpp>

#include "opencl.hpp"
#include "context.hpp"

namespace clever
{



class transfer
{
public:
	// create empty matrix
	template < class TObject >
	static void create(
			TObject & handle,
			size_t count,
			icontext const & ctx)
	{
		ERROR_HANDLER( handle.set_mem ( opencl::clCreateBuffer( ctx.native_context(),
        		CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
        		handle.value_entry_size * count, NULL, &ERROR )) );
	}

	template < class TObject >
	static void create(
			TObject & handle,
			std::vector < typename TObject::value_type > const& input,
			size_t count,
			icontext const & ctx)
	{
		// create buffer
		create ( handle, count, ctx );

		// copy content
        ERROR_HANDLER( ERROR = opencl::clEnqueueWriteBuffer( ctx.default_queue(),
        		handle.get_mem() , CL_TRUE, 0, handle.value_entry_size * count, &input.front(), 0,
        		NULL, NULL ) );
	}

	// download from device
	template < class TObject >
	static void download( TObject const & handle,
			std::vector < typename TObject::value_type > & out,
			icontext const& ctx,
			bool synchronous = true)
	{
		assert ( ( out.size() / TObject::value_elements ) == handle.get_count() );

        ERROR_HANDLER( ERROR = opencl::clEnqueueReadBuffer(
        		ctx.default_queue(),
        		handle.get_mem(),
        		cl_syncmod( synchronous ), 0,
        		handle.value_entry_size * handle.get_count(),
        		&out.front(),
        		0, NULL, NULL ) );
	}

	// upload to device
	template < class TObject >
	static void upload( TObject const & handle,
			std::vector < typename TObject::value_type > const& input,
			icontext const& ctx,
			bool synchronous = true)
	{
		assert ( ( input.size() / TObject::value_elements ) == handle.get_count() );

        ERROR_HANDLER( ERROR = opencl::clEnqueueWriteBuffer( ctx.default_queue(),
        		handle.get_mem(),
        		cl_syncmod( synchronous ),0,
        		handle.value_entry_size * handle.get_count(),
        		&input.front(),
        		0, NULL, NULL ) );
	}


	static cl_bool cl_syncmod( bool synchronous )
	{
		if ( synchronous )
			return CL_TRUE;
		else
			return CL_FALSE;
	}
};


}

