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
			icontext & ctx)
	{
		// TODO : no write here!  write an empty vector for now
		std::vector < typename TObject::value_type > arr ( TObject::value_elements * count, 0 );
		create ( handle, arr, count, ctx );
	}

	template < class TObject >
	static void create(
			TObject & handle,
			std::vector < typename TObject::value_type > const& input,
			size_t count,
			icontext & ctx)
	{
		assert ( ( input.size() / TObject::value_elements ) == count );

        ERROR_HANDLER( handle.mem_ = opencl::clCreateBuffer( ctx.native_context(),
        		CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
        		handle.value_entry_size * count, NULL, &ERROR ) );

        std::cout << std::endl << "created buffer of size "
        		<< (handle.value_entry_size * count) / 1000.0f << " kB";

        ERROR_HANDLER( ERROR = opencl::clEnqueueWriteBuffer( ctx.default_queue(),
        		handle.mem_, CL_TRUE, 0, handle.value_entry_size * count, &input.front(), 0,
        		NULL, NULL ) );
	}

	// download from device
	template < class TObject >
	static void download( TObject const & handle,
			std::vector < typename TObject::value_type > & out,
			icontext & ctx,
			bool synchronous = true)
	{
		assert ( ( out.size() / TObject::value_elements ) == handle._count );

        ERROR_HANDLER( ERROR = opencl::clEnqueueReadBuffer(
        		ctx.default_queue(),
        		handle.mem_,
        		cl_syncmod( synchronous ), 0,
        		handle.value_entry_size * handle._count,
        		&out.front(),
        		0, NULL, NULL ) );
	}

	// upload to device
	template < class TObject >
	static void upload( TObject const & handle,
			std::vector < typename TObject::value_type > & input,
			icontext & ctx,
			bool synchronous = true)
	{
		assert ( ( input.size() / TObject::value_elements ) == handle._count );

		std::cout << std::endl << "Uploading value";
        ERROR_HANDLER( ERROR = opencl::clEnqueueWriteBuffer( ctx.default_queue(),
        		handle.mem_,
        		cl_syncmod( synchronous ),0,
        		handle.value_entry_size * handle._count,
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

