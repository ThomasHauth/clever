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

class datatype_base: private boost::noncopyable
{
public:
	datatype_base(context & context, size_t count) :
			m_context(context), m_count(count)
	{

	}

	size_t get_count() const
	{
		return m_count;
	}

	context const& get_context() const
	{
		return m_context;
	}

	cl_mem get_mem() const
	{
		return m_mem;
	}
	cl_mem & get_mem_ref()
	{
		return m_mem;
	}

	void set_mem(cl_mem new_mem)
	{
		m_mem = new_mem;
	}

	~datatype_base()
	{
		// free memory
		// do explicit
		m_context.release_buffer(get_mem());
	}

private:
	context & m_context;
	size_t m_count;

	cl_mem m_mem;
};

// not one vector, but N vectors aligned in memory
template<class Type, unsigned int D>
class vector: public datatype_base
{
public:
	typedef Type value_type;
	typedef typename std::vector<Type> stdvector_type;

	static constexpr::size_t value_dim = D;
	static constexpr::size_t value_elements = D;

	// size of one entry ( > one vector ) in bytes
	static constexpr::size_t value_entry_size = D * sizeof(value_type);

	explicit vector(context & c, size_t array_count = 1) :
			datatype_base(c, array_count)
	{
		transfer::create(*this, array_count, c);
	}

	explicit vector(stdvector_type const & input, size_t array_count,
			context & c) :
			datatype_base(c, array_count)
	{
		transfer::create(*this, input, array_count, c);
	}

	explicit vector(stdvector_type const & input, context & c) :
			datatype_base(c, input.size())
	{
		transfer::create(*this, input, input.size(), c);
	}

	explicit vector(value_type intial_value, size_t array_count, context & c) :
			datatype_base(c, array_count)
	{
		// TODO: could be improved, we have to use this temporary std::vector here
		std::vector<value_type> vtmp(array_count * value_elements,
				intial_value);
		transfer::create(*this, vtmp, array_count, c);
	}

	// TODO: more interfacing here, for example smatrix
	void to_array(stdvector_type & arr) const
	{
		transfer::download(*this, arr, get_context());
	}

	void from_array(stdvector_type const& arr) const
	{
		transfer::upload(*this, arr, get_context());
	}

	// todo: make this with constexpr
	clever::range range() const
	{
		return clever::range(get_count());
	}

};

template<class Type, unsigned int D>
class matrix: public datatype_base
{
public:
	typedef Type value_type;

	static constexpr::size_t value_dim = D;
	static constexpr::size_t value_elements = D * D;
	// size of one entry ( > one matrix ) in bytes
	static constexpr::size_t value_entry_size = value_elements
			* sizeof(value_type);

	typedef typename std::vector<Type> VectorType;

	explicit matrix(context & c, size_t count = 1) :
			datatype_base(c, count)
	{
		transfer::create(*this, count, get_context());
	}

	explicit matrix(VectorType const & input, size_t count, context & c) :
			datatype_base(c, count)
	{
		transfer::create(*this, input, count, get_context());
	}

	explicit matrix(value_type initial_value, size_t count, context & c) :
			datatype_base(c, count)
	{
		std::vector<value_type> vtmp(count * value_elements, initial_value);
		transfer::create(*this, vtmp, count, get_context());
	}

	// more interfacing here, for example smatrix
	void to_array(VectorType & arr) const
	{
		transfer::download(*this, arr, get_context());
	}

	// more interfacing here, for example smatrix
	void from_array(VectorType const& arr) const
	{
		transfer::upload(*this, arr, get_context());
	}

	clever::range range_linear() const
	{
		return clever::range(get_count());
	}

};

// not one vector, but N vectors aligned in memory
template<class Type>
class object: public datatype_base
{
public:
	typedef Type value_type;
	typedef typename std::vector<Type> stdvector_type;

	// size of one entry ( > here the object ) in bytes
	static constexpr::size_t value_entry_size = sizeof(value_type);

	explicit object(stdvector_type const& input_objects, context & c) :
			datatype_base(c, input_objects.size())
	{
		transfer::create(*this, input_objects, input_objects.size(), c);
	}

	// TODO: more interfacing here, for example smatrix
	void to_array(stdvector_type & arr) const
	{
		transfer::download(*this, arr, get_context());
	}

	void from_array(stdvector_type const& arr) const
	{
		transfer::upload(*this, arr, get_context());
	}

	// todo: make this with constexpr
	clever::range range() const
	{
		return clever::range(get_count());
	}

};

// not a vector of elements, but a buffer which can only hold one value
// useful for configuration and index purposes
template<class Type>
class scalar: public datatype_base
{
public:
	typedef Type value_type;

	// size of one entry ( > here the object ) in bytes
	static constexpr::size_t value_entry_size = sizeof(value_type);

	explicit scalar(context & c,value_type const& initiaValue = value_type()) :
			datatype_base(c, 1)
	{
		transfer::createScalar(*this, initiaValue, c);
	}

	// TODO: more interfacing here, for example smatrix
	void toVariable(value_type & arr) const
	{
		transfer::downloadScalar(*this, arr, get_context());
	}

	void fromVariable(value_type const& arr) const
	{
		transfer::uploadScalar(*this, arr, get_context());
	}

	Type getValue() const
	{
		Type tVal;
		toVariable ( tVal );
		return tVal;
	}

	// todo: make this with constexpr
	clever::range range() const
	{
		return clever::range(get_count());
	}

};

}

