#pragma once

#include <gtest/gtest.h>


#include "../clever.hpp"



TEST( clever_runtime, print_information )
{
	clever::opencl::PrintInformation();
}


TEST( clever_runtime, test_default_context  )
{
	clever::context context( );
}


TEST( clever_runtime, test_profile_context  )
{
	clever::context_settings cs;
	cs.profile = true;

	clever::context context( cs );

	ASSERT_TRUE( context.is_profile() );
}


