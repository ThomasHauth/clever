#pragma once

#include <gtest/gtest.h>

#include "../clever.hpp"

TEST( clever_types, test_vector_type )
{
	const size_t count = 50;

	clever::context context;

	typedef clever::vector<double, 10> Vector;

	std::vector<double> m1_out(count * Vector::value_elements);
	Vector m1(context, count);

	ASSERT_EQ( m1.range().dimension(), (size_t)1);
	ASSERT_EQ( m1.range().sizes()[0], (size_t) count);
	ASSERT_EQ( m1._count, (size_t)count);
	ASSERT_TRUE(m1.mem_ != NULL);

	m1.to_array(m1_out, context);
	// can't check m1_out, we did not set any initial value

	// set initial value here
	std::vector<double> m2_out(count * Vector::value_elements);
	Vector m2((double) 1.0f, count, context);

	ASSERT_EQ( m2._count, (size_t)count);
	ASSERT_TRUE(m2.mem_ != NULL);

	m2.to_array(m2_out, context);
	// check the output
	for (auto const& v : m2_out)
	{
		ASSERT_EQ( v, 1.0f);
	}

	// set initial value here
	std::vector<double> m3_out(count * Vector::value_elements);
	std::vector<double> m3_in(count * Vector::value_elements);

	for (size_t i = 0; i < m3_in.size(); ++i)
	{
		m3_in[i] = (double) i;
	}

	Vector m3(m3_in, count, context);

	ASSERT_EQ( m3._count, (size_t)count);
	ASSERT_TRUE(m3.mem_ != NULL);

	m3.to_array(m3_out, context);
	// check the output
	for (size_t i = 0; i < m3_out.size(); ++i)
	{
		ASSERT_EQ( (double) i, m3_out[i]);
	}
}

TEST( clever_types, test_matrix_type )
{
	size_t count = 50;
	clever::context context;

	typedef clever::matrix<double, 10> Matrix;

	std::vector<double> m1_out(count * Matrix::value_elements);
	Matrix m1( context, count);

	ASSERT_EQ( m1._count, (size_t)count);
	ASSERT_TRUE(m1.mem_ != NULL);

	m1.to_array(m1_out, context);
	// can't check m1_out, we did not set any initial value

	// set initial value here
	std::vector<double> m2_out(count * Matrix::value_elements);
	Matrix m2((double) 1.0f, count,  context);

	ASSERT_EQ( m2._count, (size_t)count);
	ASSERT_TRUE(m2.mem_ != NULL);

	m2.to_array(m2_out,  context);
	// check the output
	for (auto const& v : m2_out)
	{
		ASSERT_EQ( v, 1.0f);
	}

	// set initial value here
	std::vector<double> m3_out(count * Matrix::value_elements);
	std::vector<double> m3_in(count * Matrix::value_elements);

	for (size_t i = 0; i < m3_in.size(); ++i)
	{
		m3_in[i] = (double) i;
	}

	Matrix m3(m3_in, count,  context);

	ASSERT_EQ( m3._count, (size_t)count);
	ASSERT_TRUE(m3.mem_ != NULL);

	m3.to_array(m3_out,  context);
	// check the output
	for (size_t i = 0; i < m3_out.size(); ++i)
	{
		ASSERT_EQ( (double) i, m3_out[i]);
	}
}

