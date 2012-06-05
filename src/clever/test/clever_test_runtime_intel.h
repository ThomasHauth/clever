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

TEST( clever_runtime_intel, test_default_context  )
{
	clever::context_settings cs ( clever::opencl::PlatformNameIntel( ) );
	clever::context context( cs );
}


TEST( clever_runtime_intel, test_profile_context  )
{
	clever::context_settings cs ( clever::opencl::PlatformNameIntel( ) );
	cs.m_profile = true;

	clever::context context(  cs );

	ASSERT_TRUE(  context.is_profile() );
}


