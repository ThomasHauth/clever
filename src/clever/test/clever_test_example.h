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

struct ItemX: public clever::DoubleItem
{
};
struct ItemY: public clever::DoubleItem
{
};
struct ItemZ: public clever::DoubleItem
{
};

struct ItemMag: public clever::DoubleItem
{
};

#define VECTOR_COLLECTION_ITEMS ItemX, ItemY, ItemZ, ItemMag

typedef clever::Collection<VECTOR_COLLECTION_ITEMS> VectorCollection;

typedef clever::OpenCLTransfer<VECTOR_COLLECTION_ITEMS> VectorCollectionTransfer;

TEST( clever_example, kernel_run_on_data )
{
	clever::context contx;

	const size_t elements = 10;

	VectorCollection col;
	VectorCollectionTransfer clTrans;

	for (size_t i = 0; i < elements; ++i)
	{
		col.addWithValue(double(i), double(i), double(i), 0.0f);
	}

	clTrans.initBuffers(contx, col);
	clTrans.toDevice(contx, col);

	// will be defined as variable "add_val" method local
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

	computeMagnitude.run(clTrans.buffer(ItemX()), clTrans.buffer(ItemY()),
			clTrans.buffer(ItemZ()), clTrans.buffer(ItemMag()),
			clTrans.defaultRange());

	clTrans.fromDevice(contx, col);

	for ( auto const& entry : col )
	{
		std::cout << "Magnitude " << entry.getValue<ItemMag>() << std::endl;
	}
}

