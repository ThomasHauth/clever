#pragma once

#include <array>

#include <openclam/cl.hpp>
#include <openclam/types.hpp>
#include <vector>

#include <gtest/gtest.h>
#include <boost/assign.hpp>

#include <tech/matrix_ops.h>

/*
TEST( RT, test_openclam  )
{

	openclam::opencl::PrintInformation();
	openclam::opencl wrapper;
	openclam::context context( wrapper, openclam::icontext::all, "-cl-fast-relaxed-math" );



	KERNEL( Unary , context , float ,
			__kernel void Unary( __global float * a )
	{
		a[ get_global_id( 0 ) ] += 1;
	}
	);

    std::list< float > actual = boost::assign::list_of( 1.f ).repeat( 9, 1.f );
//    MOCK_EXPECT( context, execute ).once().with( mock::any, sizeof( float ) * actual.size(), mock::any );
    openclam::for_each( actual.begin(), actual.end(), Unary );

    for( auto v: actual)
    {
    	EXPECT_EQ( 2.0f, v );
    }

}
*/
TEST( RT, test_kernel_params2  )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "",  openclam::icontext::device_all, "-cl-fast-relaxed-math" );

	openclam::matrix<double,2> m1 ( wrapper, context );
/*
	openclam :: kernel_base2< cl_mem, double > k2 ( "k2", context,
			"__kernel void k2( __global  double * matrix, const double D2) { }"
			);
*/

	std::unique_ptr<openclam :: kernel_base2< cl_mem, double > > k2

	( new
		openclam :: kernel_base2< cl_mem, double > ( "k2", context,
				"__kernel void k2( __global  double * matrix, const double D2) { }"
				));

	double d2 = 23.0f;

	k2->run(m1.mem_, d2,
			m1.range() );
	//(*k2)();
/*	k2->operator ()(  m1.mem_, d2,
			m1.range() );*/
	/*
	k2 ( m1.mem_, d2,
		m1.range() );*/

}


TEST( RT, test_kernel_params2_define  )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all, "-cl-fast-relaxed-math" );

	std::vector < double > arr( 4, 1.0);
	openclam::matrix<double,2> m1 ( arr, 1, wrapper, context );
/*	double d2 = 23.0f;
	double d1 = 5.0f;


	KERNEL2_CLASS( add_val , context , const double , const double ,
			__kernel void add_val( const double a, const double b )
	{
		printf ( "adding (%f) to (%f) \n", a, b );
	}
	) ( context ) ;

	// run kernel
	add_val.run( d1, d2,
				openclam::range(23));*/
}

TEST( RT, test_kernel_matrix_linear  )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all, "-cl-fast-relaxed-math" );

	typedef openclam::matrix<double,10> Matrix;

	std::vector < double >  arr(Matrix::value_elements, 1.0);
	Matrix m1 ( arr, 1, wrapper, context );

	double d2 = 23.0f;

	KERNEL2_CLASS( add_val , cl_mem, double  ,
			__kernel void add_val( __global double * a, const double b )
	{
		unsigned int x = get_global_id( 0 );
		printf ( " adding (%f) to (%f) \n", b, a[ x ]  );

		a[ get_global_id( 0 ) ] += b;
	}) ( context );

	// run kernel
	add_val.run( m1.range_linear(), m1.mem_, d2 );

	// get result
	m1.to_array( arr, wrapper, context );

	for ( auto v : arr)
	{
		EXPECT_EQ( d2 + 1, v );
	}

}

TEST( OpenClam, test_limit_compute_unit )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all, "", 0, false, 1);
}

TEST( OpenClam, print_hardware_infos )
{
	openclam::opencl::PrintInformation();
}

TEST( RT, test_kernel_matrix_ops_scalar )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all, "-cl-fast-relaxed-math" );

	typedef openclam::matrix<double,10> Matrix;

	std::vector < double > arr( Matrix::value_elements, 1.0);
	Matrix m1 ( arr, 1, wrapper, context );

	double d2 = 23.0f;

	matrix_add_scalar add_scalar ( context );
	add_scalar.apply( m1, d2 );

	// get result
	m1.to_array( arr, wrapper, context );

	for ( auto v : arr)
	{
		EXPECT_EQ( d2 + 1, v );
	}

}


TEST( openclam, kernel_variable_parameters )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, "", openclam::icontext::device_all, "-cl-fast-relaxed-math" );

	openclam::kernel_base_var<int, int> kbase( "kbase", context,
			" __kernel void kbase ( const int i1, const int i2 ) {}" );

	int i2= 23;
	int i1= 24;
	kbase.run( openclam::range(20), i1, i2 );
}




/*
TEST( RT, test_kernel_matrix_mult_similarity )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper, openclam::icontext::all, "-cl-fast-relaxed-math" );

	typedef openclam::matrix<double,10> Matrix;
	std::array < double, Matrix::value_elements > arr; arr.fill(1.0);

	Matrix m1 ( arr, wrapper, context );
	Matrix m2 ( arr, wrapper, context );
	Matrix mtmp ( arr, wrapper, context );
	Matrix mres ( arr, wrapper, context );

	matrix_similarity::apply( m1, m2, mtmp, mres );

	// get result
	//mres.to_array( arr, wrapper, context );

}
*/
TEST( RT, test_kernel_matrix_square  )
{
	// todo
	/*
	openclam::opencl wrapper;
	openclam::context context( wrapper, openclam::icontext::all, "-cl-fast-relaxed-math" );

	typedef openclam::matrix<double,10> Matrix;

	std::array < double, Matrix::value_elements > arr; arr.fill(1.0);
	Matrix m1 ( arr, wrapper, context );

	double d2 = 23.0f;

	KERNEL2( add_val , context , cl_mem, double  ,
			__kernel void add_val( __global double * a, const double b )
	{
		unsigned int x = get_global_id( 0 );
		unsigned int y = get_global_id( 1 );
		printf ( " adding (%f) to (%f) \n", b, a[ x ]  );

		a[ get_global_id( 0 ) ] += b;
	}
	);

	// run kernel
	add_val( m1.mem_, d2,
			m1.range() );

	// get result
	m1.to_array( arr, wrapper, context );

	for ( auto v : arr)
	{
		EXPECT_EQ( d2 + 1, v );
	}
*/
}
