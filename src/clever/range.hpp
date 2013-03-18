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
#include <iostream>

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

	virtual ~range() { }

    virtual const ::size_t* sizes() const { return &size_.front(); }
    virtual const ::size_t dimension() const { return dimension_; }

    virtual ::size_t getSize( ::size_t dimension = 0 )
    {
    	return size_[dimension];
    }

private:
	::size_t dimension_;
	std::array < ::size_t, 3 > size_;
};

class null_range : public range {

public:
	virtual const ::size_t* sizes() const { return NULL; }
	virtual const ::size_t dimension() const { return 0; }

	virtual ::size_t getSize( ::size_t dimension = 0 )
	{
		return 0;
	}
};

}
