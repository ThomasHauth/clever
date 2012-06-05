#pragma once

#include <gtest/gtest.h>


#include "../clever.hpp"



TEST( clever_memory, test_create_destroy_buffer  )
{
	const size_t elements = 10000;
	const float val = 12.3f;

	clever::context context;

	std::vector <float> float_in ( elements, val );


	cl_mem buffer = context.create_buffer ( sizeof(cl_float) * elements );
	context.release_buffer(buffer);
}



TEST( clever_memory, test_transfer_data  )
{
	const size_t elements = 10000;
	const float val = 12.3f;

	clever::context context;

	std::vector <float> float_in ( elements, val );
	std::vector <float> float_out ( elements, 0.0f );


	cl_mem buffer = context.create_buffer (  sizeof(cl_float) * elements );

	context.transfer_from_buffer  ( buffer, &float_in.front(),  sizeof(cl_float) * elements );
	context.transfer_to_buffer  ( buffer, &float_out.front(),  sizeof(cl_float) * elements );
	context.release_buffer(buffer);

	ASSERT_EQ( float_in, float_out);
}


