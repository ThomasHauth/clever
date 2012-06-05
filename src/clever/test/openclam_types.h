#pragma once



TEST( openclam_types, allocate_vector )
{
	size_t count = 50;
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all );

	typedef openclam::vector<double,10> Vector;

	std::vector< double > m1_out( count * Vector::value_elements );
	Vector m1( wrapper, context, count );


	ASSERT_EQ( m1.range().dimension(), (size_t)1 );
	ASSERT_EQ( m1.range().sizes()[0], (size_t) count );
	ASSERT_EQ( m1._count, (size_t)count );
	ASSERT_TRUE(m1.mem_ != NULL );

	m1.to_array( m1_out, wrapper, context );
	// can't check m1_out, we did not set any initial value

	// set initial value here
	std::vector< double > m2_out( count * Vector::value_elements );
	Vector m2( (double)1.0f, count, wrapper, context );

	ASSERT_EQ( m2._count, (size_t)count );
	ASSERT_TRUE(m2.mem_ != NULL );

	m2.to_array( m2_out, wrapper, context );
	// check the output
	for ( auto const& v: m2_out )
	{
		ASSERT_EQ( v, 1.0f );
	}

	// set initial value here
	std::vector< double > m3_out( count * Vector::value_elements );
	std::vector< double > m3_in( count * Vector::value_elements );


	for ( size_t i = 0; i < m3_in.size(); ++ i )
	{
		m3_in[ i ] = (double)i;
	}

	Vector m3( m3_in, count, wrapper, context );

	ASSERT_EQ( m3._count, (size_t)count );
	ASSERT_TRUE(m3.mem_ != NULL );

	m3.to_array( m3_out, wrapper, context );
	// check the output
	for ( size_t i = 0; i < m3_out.size(); ++ i )
	{
		ASSERT_EQ ( (double) i, m3_out[i] );
	}
}

TEST( openclam_types, allocate_matrix )
{
	size_t count = 50;
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all );

	typedef openclam::matrix<double,10> Matrix;

	std::vector< double > m1_out( count * Matrix::value_elements );
	Matrix m1( wrapper, context, count );

	ASSERT_EQ( m1._count, (size_t)count );
	ASSERT_TRUE(m1.mem_ != NULL );

	m1.to_array( m1_out, wrapper, context );
	// can't check m1_out, we did not set any initial value

	// set initial value here
	std::vector< double > m2_out( count * Matrix::value_elements );
	Matrix m2( (double)1.0f, count, wrapper, context );

	ASSERT_EQ( m2._count, (size_t)count );
	ASSERT_TRUE(m2.mem_ != NULL );

	m2.to_array( m2_out, wrapper, context );
	// check the output
	for ( auto const& v: m2_out )
	{
		ASSERT_EQ( v, 1.0f );
	}

	// set initial value here
	std::vector< double > m3_out( count * Matrix::value_elements );
	std::vector< double > m3_in( count * Matrix::value_elements );


	for ( size_t i = 0; i < m3_in.size(); ++ i )
	{
		m3_in[ i ] = (double)i;
	}

	Matrix m3( m3_in, count, wrapper, context );

	ASSERT_EQ( m3._count, (size_t)count );
	ASSERT_TRUE(m3.mem_ != NULL );

	m3.to_array( m3_out, wrapper, context );
	// check the output
	for ( size_t i = 0; i < m3_out.size(); ++ i )
	{
		ASSERT_EQ ( (double) i, m3_out[i] );
	}
}

