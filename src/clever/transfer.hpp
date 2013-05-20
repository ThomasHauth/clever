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
			context const & ctx)
	{

		handle.set_mem(ctx.create_buffer(handle.value_entry_size * count));

	}

	template < class TObject >
	static void create(
			TObject & handle,
			std::vector < typename TObject::value_type > const& input,
			size_t count,
			context const & ctx)
	{
		// create buffer
		create ( handle, count, ctx );

		ctx.transfer_to_buffer(handle.get_mem(), &input.front(), handle.value_entry_size * count);
        //std::cout << "Buffer written" << std::endl;
	}

	template < class TObject >
	static void createScalar(
			TObject & handle,
			typename TObject::value_type const& initialValue,
			context const & ctx)
	{
		// create buffer
		create ( handle, 1, ctx );

		ctx.transfer_to_buffer(handle.get_mem(), &initialValue, handle.value_entry_size);

        //std::cout << "Buffer written" << std::endl;
	}

	// download from device
	template < class TObject >
	static void download( TObject const & handle,
			std::vector < typename TObject::value_type > & out,
			context const& ctx,
			bool synchronous = true)
	{
		assert ( ( out.size() / TObject::value_elements ) == handle.get_count() );

		ctx.transfer_from_buffer(handle.get_mem(), &out.front(), handle.value_entry_size * handle.get_count(), 0, NULL);
	}

	// download from device
	template < class TObject >
	static void downloadScalar( TObject const & handle,
			typename TObject::value_type & out,
			context const& ctx,
			bool synchronous = true,
			uint offset = 0,
			uint lengthWaitList = 0,
			const cl_event * waitList = NULL)
	{
		assert ( handle.get_count() >= offset );

		offset = offset * handle.value_entry_size;
		ctx.transfer_from_buffer(handle.get_mem(), &out, handle.value_entry_size, lengthWaitList, waitList, offset);
	}

	// upload to device
	template < class TObject >
	static void upload( TObject const & handle,
			std::vector < typename TObject::value_type > const& input,
			context const& ctx,
			bool synchronous = true)
	{
		assert ( ( input.size() / TObject::value_elements ) == handle.get_count() );

		ctx.transfer_to_buffer(handle.get_mem(), &input.front(), handle.value_entry_size * handle.get_count());
	}

	template < class TObject >
	static void uploadScalar( TObject const & handle,
			typename TObject::value_type const& input,
			context const& ctx,
			bool synchronous = true)
	{
		assert (   handle.get_count() == 1 );

		ctx.transfer_to_buffer(handle.get_mem(), &input, handle.value_entry_size);
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

