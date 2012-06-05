#pragma once

#include <gtest/gtest.h>


#include "../clever.hpp"

TEST( clever_runtime_intel, test_default_context  )
{
	clever::context_settings cs ( clever::opencl::PlatformNameIntel( ) );
	clever::context context( cs );
}


TEST( clever_runtime_intel, test_profile_context  )
{
	clever::context_settings cs ( clever::opencl::PlatformNameIntel( ) );
	cs.profile = true;

	clever::context context(  cs );

	ASSERT_TRUE(  context.is_profile() );
}


