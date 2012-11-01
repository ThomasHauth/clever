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

TEST( clever_types, test_vector_type )
{
	const size_t count = 50;

	clever::context context;

	typedef clever::vector<double, 10> TestVector;

	std::vector<double> m1_out(count * TestVector::value_elements, -1.0f);
	std::vector<double> m1_in(count * TestVector::value_elements, 2.0f);


	// create clever vector, no initial values given
	TestVector m1(context, count);

	ASSERT_EQ( m1.range().dimension(), (size_t)1);
	ASSERT_EQ( m1.range().sizes()[0], (size_t) count);
	ASSERT_EQ( m1.get_count(), (size_t)count);
	ASSERT_TRUE(m1.get_mem() != NULL);

	// download values to device
	m1.from_array( m1_in );

	// upload again and check the values
	m1.to_array( m1_out );

	for (auto const& v : m1_out)
	{
		ASSERT_EQ( v, 2.0f);
	}

	// set initial value here
	std::vector<double> m2_out(count * TestVector::value_elements, -1.0f);

	TestVector m2((double) 23.0f, count, context);

	ASSERT_EQ( m2.get_count(), (size_t)count);
	ASSERT_TRUE(m2.get_mem() != NULL);

	// get the values from OpenCL
	m2.to_array( m2_out );
	context.finish_default_queue();

	// check the output
	for (auto const& v : m2_out)
	{
		ASSERT_EQ( v, 23.0f);
	}

	// set initial value via passing a std::vector
	std::vector<double> m3_out(count * TestVector::value_elements, 0.0f);
	std::vector<double> m3_in(count * TestVector::value_elements, 0.0f);

	for (size_t i = 0; i < m3_in.size(); ++i)
	{
		m3_in[i] = (double) i;
	}

	TestVector m3(m3_in, count, context);

	ASSERT_EQ( m3.get_count(), (size_t)count);
	ASSERT_TRUE(m3.get_mem() != NULL);

	m3.to_array(m3_out );
	// check the output
	for (size_t i = 0; i < m3_out.size(); ++i)
	{
		ASSERT_EQ( (double) i, m3_out[i]);
	}
}


TEST( clever_types, test_scalar )
{
	clever::context context;

	typedef clever::scalar <unsigned int> TestScalar;


	// create clever vector, no initial values given
	TestScalar m1(context, 23);

	unsigned int myLocalInt = 5;
	m1.toVariable( myLocalInt );

	ASSERT_EQ( (unsigned int) 23, myLocalInt);


	// create clever vector, no initial values given
	TestScalar m2(context);

	myLocalInt = 223;
	unsigned int myOtherLocalInt = 0;

	m1.fromVariable( myLocalInt );
	m1.toVariable( myOtherLocalInt );

	ASSERT_EQ( (unsigned int) 223, myOtherLocalInt);
}

TEST( clever_types, test_matrix_type )
{
	size_t count = 50;
	clever::context context;

	// define 10x10 matrix
	typedef clever::matrix<double, 10> TestMatrix;

	std::vector<double> m1_in(count * TestMatrix::value_elements, 23.0f);
	std::vector<double> m1_out(count * TestMatrix::value_elements);

	// don't set initial value but download it later on
	TestMatrix m1( context, count);

	ASSERT_EQ( m1.get_count(), (size_t)count);
	ASSERT_TRUE(m1.get_mem() != NULL);

	// download values to device
	m1.from_array(m1_in );

	// upload again and check the values
	m1.to_array( m1_out );
	for (auto const& v : m1_out)
	{
		ASSERT_EQ( v, 23.0f);
	}

	// set initial value here
	std::vector<double> m2_out(count * TestMatrix::value_elements);
	TestMatrix m2((double) 1.0f, count,  context);

	ASSERT_EQ( m2.get_count(), (size_t)count);
	ASSERT_TRUE(m2.get_mem() != NULL);

	m2.to_array(m2_out );
	// check the output
	for (auto const& v : m2_out)
	{
		ASSERT_EQ( v, 1.0f);
	}

	// set initial value here, via std::vector
	std::vector<double> m3_out(count * TestMatrix::value_elements);
	std::vector<double> m3_in(count * TestMatrix::value_elements);

	for (size_t i = 0; i < m3_in.size(); ++i)
	{
		m3_in[i] = (double) i;
	}

	TestMatrix m3(m3_in, count,  context);

	ASSERT_EQ( m3.get_count(), (size_t)count);
	ASSERT_TRUE(m3.get_mem() != NULL);

	m3.to_array(m3_out );
	// check the output
	for (size_t i = 0; i < m3_out.size(); ++i)
	{
		ASSERT_EQ( (double) i, m3_out[i]);
	}
}

