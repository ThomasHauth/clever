//
//  Authors: Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//


#pragma once

#include <cstring>
#include <array>
#include <CL/cl.h>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>

namespace clever
{

class range
{

public:
	explicit range ()
		: dimension_ ( 0)
	{

	}

	range ( ::size_t size0 )
	: dimension_ ( 1 )
	{
		size_[0] = size0;
	}

	range ( ::size_t size0, ::size_t size1 )
	: dimension_ ( 2 )
	{
		size_[0] = size0;
		size_[1] = size1;

	}

	range ( ::size_t size0, ::size_t size1, ::size_t size2 )
	: dimension_ ( 3 )
	{
		size_[0] = size0;
		size_[1] = size1;
		size_[2] = size2;

	}

    const ::size_t* sizes() const { return &size_.front(); }
    const ::size_t dimension() const { return dimension_; }

    ::size_t getSize( ::size_t dimension = 0 )
    {
    	return size_[dimension];
    }

private:
	::size_t dimension_;
	std::array < ::size_t, 3 > size_;
};

static const range null_range;

}
