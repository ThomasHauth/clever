#include "gtest/gtest.h"

#include "test/clever_tests.h"


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);


	auto res =  RUN_ALL_TESTS();

	return res;
}
