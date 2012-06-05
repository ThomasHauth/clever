#pragma once

#include <gtest/gtest.h>


#include "../clever.hpp"

TEST( clever_runtime, test_default_context  )
{
	openclam::opencl wrapper;
	openclam::context context( wrapper );
}

