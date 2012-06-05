//
//  Copyright Thomas Hauth
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_TRANSFER_HPP_INCLUDED
#define OPENCLAM_TRANSFER_HPP_INCLUDED

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
		// write an empty vector for now
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
        		handle.value_size * count, NULL, &ERROR ) );

        std::cout << std::endl << "created buffer of size "
        		<< (handle.value_size * count) / 1000.0f << " kB";

        ERROR_HANDLER( ERROR = opencl::clEnqueueWriteBuffer( ctx.default_queue(),
        		handle.mem_, CL_TRUE, 0, handle.value_size * count, &input.front(), 0,
        		NULL, NULL ) );
	}

	template < class TObject >
	static void download( TObject const & handle,
			std::vector < typename TObject::value_type > & out,
			icontext & ctx )
	{
		assert ( ( out.size() / TObject::value_elements ) == handle._count );

        ERROR_HANDLER( ERROR = opencl::clEnqueueReadBuffer(
        		ctx.default_queue(),
        		handle.mem_,
        		CL_TRUE, 0,
        		handle.value_size * handle._count,
        		&out.front(),
        		0, NULL, NULL ) );
	}

};




}

#endif // #ifndef OPENCLAM_TRANSFER_HPP_INCLUDED
