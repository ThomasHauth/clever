//
//  Copyright Thomas Hauth 2011
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_RANGE_HPP_INCLUDED
#define OPENCLAM_RANGE_HPP_INCLUDED

#include <cstring>
#include <array>
#include <CL/cl.h>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>

//#include "types.hpp"


namespace clever
{

class range// : private boost::noncopyable
{

public:

	//typedef std::array < ::size_t, 3 > sizes;


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

private:
	::size_t dimension_;
	std::array < ::size_t, 3 > size_;
};

static const range null_range;

}

#endif // #ifndef OPENCLAM_RANGE_HPP_INCLUDED
