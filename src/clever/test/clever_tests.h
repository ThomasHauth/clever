//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

// generic tests, should run on all OpenCL platforms
#include "clever_test_runtime.h"
#include "clever_test_memory.h"
#include "clever_test_types.h"
#include "clever_test_kernels.h"

#include "serialize/test/clever_test_serialize.h"

// platform specific tests
#include "clever_test_runtime_intel.h"
