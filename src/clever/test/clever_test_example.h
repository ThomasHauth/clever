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

// define the user's data items that are needed
// all are double precision float, other data types are possible
namespace UserVector {
	struct ItemX: public clever::DoubleItem {};
	struct ItemY: public clever::DoubleItem {};
	struct ItemZ: public clever::DoubleItem {};
	struct ItemMag: public clever::DoubleItem {};
}

// create an OpenCL Collection which can hold the users values on the host
// side and transfer them to OpenCL devices
typedef clever::OpenCLCollection<
		UserVector::ItemX,
		UserVector::ItemY,
		UserVector::ItemZ,
		UserVector::ItemMag > OpenCLVector;

TEST( clever_example, kernel_run_on_data )
{
	const size_t elements = 10;

	// create the OpenCL Context, in this case, the first OpenCL device available will be used
	// more specific settings ( GPU or CPU ) are possible
	clever::context contx;

	// define the OpenCL kernel code and compile in for the concrete context
	// this code fragment will also be compiled and syntax & type checked by gcc on the host side
	// during compile time.
	// During runtime, it will be handed to the OpenCL runtime for compilation.
	KERNEL4_CLASS( computeMagnitude, cl_mem, cl_mem , cl_mem , cl_mem ,

			double square( double a )
			{
				return a * a;
			}

			__kernel void computeMagnitude(
					/* input parameters */
					__global const double * vX, __global const double * vY, __global double * vZ,
					/* output parameters */
					__global double * vMag)
			{
				size_t gid = get_global_id( 0 );
				vMag[gid] = sqrt( square( vX[ gid] ) + square( vX[ gid] ) + square( vX[ gid] ) );
			})
	(contx);

	// collection to hold the data items on the host side
	OpenCLVector::collection_type col;
	// collection to create and trasfer the OpenCL buffers to the device
	OpenCLVector::transfer_type clTrans;

	// fill some values
	for (size_t i = 0; i < elements; ++i)
	{
		col.addWithValue(double(i), double(i), double(i), 0.0f);
	}

	// create Buffers on OpenCL side
	clTrans.initBuffers(contx, col);
	// transfer Buffers to device
	clTrans.toDevice(contx, col);

	// execute the OpenCL kernel with the buffers as input
	computeMagnitude.run(clTrans.buffer(UserVector::ItemX()), clTrans.buffer(UserVector::ItemY()),
			clTrans.buffer(UserVector::ItemZ()), clTrans.buffer(UserVector::ItemMag()),
			clTrans.defaultRange());

	// make sure all OpenCL kernels are finished, before accessing their result
	contx.finish_default_queue();

	// transfer the OpenCL bufer content back to the device
	clTrans.fromDevice(contx, col);

	// output the result
	for ( auto const& entry : col )
	{
		std::cout << "Magnitude " << entry.getValue<UserVector::ItemMag>() << std::endl;
	}
}

