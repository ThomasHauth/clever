//
//  Copyright Thomas Hauth
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_TYPES_HPP_INCLUDED
#define OPENCLAM_TYPES_HPP_INCLUDED

#include <boost/noncopyable.hpp>

#include "icontext.hpp"
#include "range.hpp"
#include "transfer.hpp"

namespace openclam {

class icontext;

// not one vector, but N vectors alligned in memory
template<class Type, unsigned int D>
class vector: private boost::noncopyable {
public:
	typedef Type value_type;

	static constexpr::size_t value_dim = D;
	static constexpr::size_t value_elements = D;
	static constexpr::size_t value_size = D * sizeof(value_type);

	typedef typename std::vector<Type> VectorType;

	explicit vector(iopencl const& wrapper, icontext & c, size_t count = 1) :
			_wrapper(wrapper), _count(count) {
		transfer::create(*this, count, c, wrapper);
	}

	explicit vector(VectorType const & input, // prototype
			size_t count, iopencl const& wrapper, icontext & c) :
			_wrapper(wrapper), _count(count) {
		transfer::create(*this, input, count, c, wrapper);
	}

	explicit vector( value_type intial_value, // prototype
			size_t count, iopencl const& wrapper, icontext & c) :
			_wrapper(wrapper), _count(count)
	{
		std::vector < value_type > vtmp( count * value_elements, intial_value );
		transfer::create(*this, vtmp, count, c, wrapper);
	}

	~vector() {
		// free memory
		// do expclicit
		_wrapper.clReleaseMemObject(mem_);
        std::cout << std::endl << "released buffer of size "
        		<< (value_size * _count) / 1000.0f << " kB";

	}

	// more interfacing here, for example smatrix
	void to_array(VectorType & arr, iopencl const& wrapper,
			icontext & c) const {
		transfer::download(*this, arr, c, wrapper);
	}

	// todo: make this with constexpr
	openclam::range range() const {
		return openclam::range( _count );
	}

	cl_mem mem_;

	iopencl const& _wrapper;
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

	explicit matrix(iopencl const& wrapper, icontext & c, size_t count = 1) :
			_wrapper(wrapper), _count(count) {
		transfer::create(*this, count, c, wrapper);
	}

	explicit matrix(VectorType const & input, size_t count,
			iopencl const& wrapper, icontext & c) :
			_wrapper(wrapper), _count(count) {
		transfer::create(*this, input, count, c, wrapper);
	}

	explicit matrix(value_type initial_value, size_t count,
			iopencl const& wrapper, icontext & c) :
			_wrapper(wrapper), _count(count) {
		std::vector < value_type > vtmp( count * value_elements , initial_value );
		transfer::create(*this, vtmp, count, c, wrapper);
	}
	~matrix() {
		// free memory
		// do expclicit
		_wrapper.clReleaseMemObject(mem_);
        std::cout << std::endl << "released buffer of size "
        		<< (value_size * _count) / 1000.0f << " kB";
	}

	// more interfacing here, for example smatrix
	void to_array(VectorType & arr, iopencl const& wrapper,
			icontext & c) const {
		transfer::download(*this, arr, c, wrapper);
	}

	// todo: make this with constexpr
	openclam::range range() const {
		//todo: fix this, must use _count !!
		assert( false );
		return openclam::range(value_dim, value_dim);
	}

	openclam::range range_linear() const {
		//todo: fix this, must use _count !!
		assert( false );

		return openclam::range(value_elements);
	}

	cl_mem mem_;

	iopencl const& _wrapper;
	size_t _count;
};

}

#endif // #ifndef OPENCLAM_TYPES_HPP_INCLUDED
