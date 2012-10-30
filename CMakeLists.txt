cmake_minimum_required (VERSION 2.6)

project (clever)

message ("Setting up folder ${clever_SOURCE_DIR}")

set (GTEST_BASE ${clever_SOURCE_DIR}/external/gtest) 
set (GTEST_INCLUDE ${GTEST_BASE}/include) 


include_directories (${GTEST_BASE}) 
include_directories (${GTEST_INCLUDE}) 
include_directories (${clever_SOURCE_DIR}/src/clever) 



add_executable(clever_test src/test/clever_test.cpp ${GTEST_BASE}/src/gtest-all.cc )

# open cl libs
target_link_libraries(clever_test "OpenCL")


## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-g -O3 -std=gnu++0x -fopenmp -Wall -Wfatal-errors -pedantic")

	# most common fallback
    #set(CMAKE_CXX_COMPILER "g++-4.6.3")
    set(CMAKE_CXX_COMPILER "/build/gcc/gcc-latest-bin/bin/g++")

endif()



