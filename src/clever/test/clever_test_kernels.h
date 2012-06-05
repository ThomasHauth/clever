//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <gtest/gtest.h>

#include "../clever.hpp"

class test_run_kernel
{
public:
	test_run_kernel( clever::context & ctext  )
		: add_val ( ctext )
	{
	}

	KERNEL2_CLASS( add_val,  cl_mem, double ,
			__kernel void add_val( __global double * a, const double b )
	{
		a[ get_global_id( 0 ) ] += b;
	});

};

TEST( clever_kernels, test_run_kernel_in_class )
{
	size_t vector_size = 10;
	clever::context context;

	typedef clever::vector<double,1> Vector;

	std::vector < double >  arr( vector_size , 1.0);
	Vector m1 ( arr, vector_size, context );

	double d2 = 23.0f;


	test_run_kernel kernel ( context );
	// run kernel
	kernel.add_val.run(m1.get_mem(), d2,  m1.range() );

	// get result
	m1.to_array( arr );

	for ( auto v : arr)
	{
		ASSERT_FLOAT_EQ( d2 + 1, v );
	}
}

TEST( clever_kernels, test_run_kernel_in_method )
{
	size_t vector_size = 10;
	clever::context context;

	typedef clever::vector<double,1> Vector;

	std::vector < double >  arr( vector_size , 1.0);
	Vector m1 ( arr, vector_size, context );

	double d2 = 23.0f;

	// will be defined as variable "add_val" method local
	KERNEL2_CLASS( add_val,  cl_mem, double ,
			__kernel void add_val( __global double * a, const double b )
	{
		a[ get_global_id( 0 ) ] += b;
	})
	(context);


	add_val.run(m1.get_mem(), d2,  m1.range() );

	// get result
	m1.to_array( arr );

	for ( auto v : arr)
	{
		ASSERT_FLOAT_EQ( d2 + 1, v );
	}
}
