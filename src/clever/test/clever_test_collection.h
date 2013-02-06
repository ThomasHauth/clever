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

struct TestFloat1: public clever::FloatItem
{
};
struct TestFloat2: public clever::FloatItem
{
};
struct TestUInt1: public clever::UIntItem
{
};

#define TEST_COLLECTION_ITEMS TestFloat1, TestFloat2, TestUInt1

typedef clever::Collection<TEST_COLLECTION_ITEMS> TestCollectiontems;

class TestCollection: public TestCollectiontems
{
public:
	TestCollection()
	{

	}

	TestCollection(int items) :
			clever::Collection<TEST_COLLECTION_ITEMS>(items)
	{

	}
};

typedef clever::OpenCLTransfer<TEST_COLLECTION_ITEMS> TestCollectionTransfer;

TEST( clever_collection, collection_create )
{
	const size_t elements = 10000;
	TestCollection col(elements);

	GTEST_ASSERT_EQ( col.size(), elements);

	const float f1 = 23.0f;
	const float f2 = 5.0f;
	const unsigned int uint1 = 345;

	auto it = col.begin();

	it->setValue<TestFloat1>(f1);
	it->setValue<TestFloat2>(f2);
	it->setValue<TestUInt1>(uint1);

	GTEST_ASSERT_EQ( it->getValue<TestFloat1>( ), f1);
	GTEST_ASSERT_EQ( it->getValue<TestFloat2>( ), f2);
	GTEST_ASSERT_EQ( it->getValue<TestUInt1>( ), uint1);
}

TEST( clever_collection, collection_add )
{
	TestCollection col;
	GTEST_ASSERT_EQ( col.size(), (unsigned int) 0);

	const float f1 = 23.0f;
	const float f2 = 5.0f;
	const unsigned int uint1 = 345;

	const unsigned int newIndex = col.addWithValue(f1, f2, uint1);

	// the index of the new element is 0
	GTEST_ASSERT_EQ( newIndex, (unsigned int) 0);
	// the size of the collection is now 1
	GTEST_ASSERT_EQ( col.size(), (unsigned int) 1);

	auto it = col.begin();

	it->setValue<TestFloat1>(f1);
	it->setValue<TestFloat2>(f2);
	it->setValue<TestUInt1>(uint1);

	GTEST_ASSERT_EQ( it->getValue<TestFloat1>( ), f1);
	GTEST_ASSERT_EQ( it->getValue<TestFloat2>( ), f2);
	GTEST_ASSERT_EQ( it->getValue<TestUInt1>( ), uint1);
}

TEST( clever_collection, OpenCLTransfer )
{
	clever::context context;

	TestCollection col;
	GTEST_ASSERT_EQ( col.size(), (unsigned int) 0);

	const float f1 = 23.0f;
	const float f2 = 5.0f;
	const unsigned int uint1 = 345;

	const unsigned int newIndex = col.addWithValue(f1, f2, uint1);

	// the index of the new element is 0
	GTEST_ASSERT_EQ( newIndex, (unsigned int) 0);
	// the size of the collection is now 1
	GTEST_ASSERT_EQ( col.size(), (unsigned int) 1);

	auto it = col.begin();

	it->setValue<TestFloat1>(f1);
	it->setValue<TestFloat2>(f2);
	it->setValue<TestUInt1>(uint1);

	TestCollectionTransfer clTrans;

	clTrans.initBuffers(context, col);

	clTrans.toDevice(context, col);
	clTrans.fromDevice(context, col);

	auto it_new = col.begin();

	GTEST_ASSERT_EQ( it_new->getValue<TestFloat1>( ), f1);
	GTEST_ASSERT_EQ( it_new->getValue<TestFloat2>( ), f2);
	GTEST_ASSERT_EQ( it_new->getValue<TestUInt1>( ), uint1);
}

TEST( clever_collection, OpenCLTransfer_large )
{
	TestCollection ht(400000);
	clever::context contx;

	TestCollectionTransfer clTrans;

	clTrans.initBuffers(contx, ht);

	clTrans.toDevice(contx, ht);
	clTrans.fromDevice(contx, ht);
}

