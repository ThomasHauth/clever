//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//


#pragma once

#include <boost/noncopyable.hpp>

#include "context.hpp"
#include "range.hpp"
#include "transfer.hpp"

namespace clever
{

// not one vector, but N vectors aligned in memory
template<class Type, unsigned int D>
class vector: private boost::noncopyable
{
public:
	typedef Type value_type;

	static constexpr::size_t value_dim = D;
	static constexpr::size_t value_elements = D;
	static constexpr::size_t value_size = D * sizeof(value_type);

	typedef typename std::vector<Type> VectorType;

	explicit vector(  icontext & c, size_t count = 1) :
			 _count(count)
	{
		transfer::create(*this, count, c );
	}

	explicit vector(VectorType const & input, // prototype
			size_t count, icontext & c) :
			  _count(count)
	{
		transfer::create(*this, input, count, c );
	}

	explicit vector(value_type intial_value, // prototype
			size_t count,  icontext & c) :
			  _count(count)
	{
		std::vector<value_type> vtmp(count * value_elements, intial_value);
		transfer::create(*this, vtmp, count, c );
	}

	~vector()
	{
		// free memory
		// do explicit
		opencl::clReleaseMemObject(mem_);
	}

	// TODO: more interfacing here, for example smatrix
	void to_array(VectorType & arr, icontext & c) const
	{
		transfer::download(*this, arr, c );
	}

	void from_array(VectorType & arr, icontext & c) const
	{
		transfer::upload(*this, arr, c );
	}

	// todo: make this with constexpr
	clever::range range() const
	{
		return clever::range(_count);
	}

	cl_mem mem_;
	size_t _count;
};

template<class Type, unsigned int D>
class matrix: private boost::noncopyable // can essentially be copied, trying to keep the non-copy sematic as long as possible
{
public:
	typedef Type value_type;

	static constexpr::size_t value_dim = D;
	static constexpr::size_t value_elements = D * D;
	static constexpr::size_t value_size = D * D * sizeof(value_type);

	typedef typename std::vector<Type> VectorType;

	explicit matrix( icontext & c, size_t count = 1) :
			_count(count)
	{
		transfer::create(*this, count, c );
	}

	explicit matrix(VectorType const & input, size_t count,
			icontext & c) :
			 _count(count)
	{
		transfer::create(*this, input, count, c );
	}

	explicit matrix(value_type initial_value, size_t count,
			icontext & c) :
			_count(count)
	{
		std::vector<value_type> vtmp(count * value_elements, initial_value);
		transfer::create(*this, vtmp, count, c );
	}
	~matrix()
	{
		// free memory
		// do explicit
		opencl::clReleaseMemObject(mem_);
	}

	// more interfacing here, for example smatrix
	void to_array(VectorType & arr, icontext & c) const
	{
		transfer::download(*this, arr, c );
	}

	// more interfacing here, for example smatrix
	void from_array(VectorType & arr, icontext & c) const
	{
		transfer::upload(*this, arr, c );
	}

	// todo: make this with constexpr
	clever::range range() const
	{
		//todo: fix this, must use _count !!
		assert( false);
		return clever::range(value_dim, value_dim);
	}

	clever::range range_linear() const
	{
		//todo: fix this, must use _count !!
		assert( false);

		return clever::range(value_elements);
	}

	cl_mem mem_;
	size_t _count;
};

}

