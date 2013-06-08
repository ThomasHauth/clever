//
//  Copyright Thomas Hauth 2011
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <cstring>
#include <CL/cl.h>
#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/static_assert.hpp>

//#include "types.hpp"
namespace clever
{

class kernel_parameter //: private boost::noncopyable
{
public:
	explicit kernel_parameter( const void * buffer, ::size_t size, std::string stypename = "") :
		buffer_( buffer ),
		size_( size ),
		typename_fordebug_ ( stypename )
	{
	}

	const void * buffer_;
	::size_t size_;
	std::string typename_fordebug_;

};

struct local_param {
	size_t sizePerEntry;
	size_t nEntries;

	local_param(size_t sizePerEntry_, size_t nEntries_)
		: sizePerEntry( sizePerEntry_), nEntries( nEntries_ )
	{ }

	local_param operator+(const local_param & a) const {
		local_param r(*this);

		if(r.sizePerEntry == a.sizePerEntry){
			r.nEntries += a.nEntries;
		} else {
			r.sizePerEntry = r.sizePerEntry * r.nEntries + a.sizePerEntry * a.nEntries;
			r.nEntries = 1;
		}

		return r;
	}

	local_param operator*(const uint a) const {
		local_param r(*this);
		r.nEntries *= a;

		return r;
	}

	bool operator<(size_t bytes) const{
		return this->sizePerEntry * this->nEntries < bytes;
	}

	bool operator<=(size_t bytes) const{
		return this->sizePerEntry * this->nEntries <= bytes;
	}

	bool operator==(size_t bytes) const{
		return this->sizePerEntry * this->nEntries == bytes;
	}

	bool operator>=(size_t bytes) const{
		return this->sizePerEntry * this->nEntries >= bytes;
	}

	bool operator>(size_t bytes) const{
		return this->sizePerEntry * this->nEntries > bytes;
	}
};

template < class  T >
class parameter_factory
{
public:
	// Must use a vaule-by-reference as the pointer which is extracted and
	// give to OpenCL must be valid outside of the scope of this function
	inline static kernel_parameter * parameter( T & input);
/*	{
		//return new kernel_parameter( &input, sizeof ( T ) );
		// use template specilization to support data types
		assert ( false );
	}*/

	inline static std::string name ()
	{
		return "- name not set -";
	}

};

template <>
inline kernel_parameter *parameter_factory < const float >::parameter( float const& input)
{
	return new kernel_parameter( &input, sizeof ( cl_float ), "float" );
}

template <>
inline kernel_parameter *parameter_factory <  float >::parameter(  float & input)
{
	return new kernel_parameter( &input, sizeof ( cl_float ), "float"  );
}

template <>
inline kernel_parameter *parameter_factory < const double >::parameter( double const& input)
{
	return new kernel_parameter( &input, sizeof ( cl_double ), "double" );
}

template <>
inline kernel_parameter *parameter_factory <  double >::parameter(  double & input)
{
	return new kernel_parameter( &input, sizeof ( cl_double ), "double"  );
}


template <>
inline kernel_parameter *parameter_factory <  const cl_mem >::parameter( cl_mem const& input)
{
	return new kernel_parameter( &input, sizeof ( cl_mem ), "cl_mem"  );
}


template <>
inline kernel_parameter *parameter_factory <  cl_mem >::parameter( cl_mem &  input)
{
	return new kernel_parameter( &input, sizeof ( cl_mem ), "cl_mem" );
}



template <>
inline kernel_parameter *parameter_factory <  const int >::parameter( const int & input)
{
	return new kernel_parameter( &input, sizeof ( cl_int ), "cl_int"  );
}


template <>
inline kernel_parameter *parameter_factory < int >::parameter( int & input)
{
	return new kernel_parameter( &input, sizeof ( cl_int ), "cl_int"  );
}

template <>
inline kernel_parameter *parameter_factory <  const uint >::parameter( const uint & input)
{
	return new kernel_parameter( &input, sizeof ( cl_uint ), "cl_uint"  );
}


template <>
inline kernel_parameter *parameter_factory < uint >::parameter( uint & input)
{
	return new kernel_parameter( &input, sizeof ( cl_uint ), "cl_uint"  );
}

template <>
inline kernel_parameter *parameter_factory < local_param >::parameter( local_param & input)
{
	return new kernel_parameter( NULL, input.nEntries * input.sizePerEntry, "__local"  );
}


template <>
inline std::string parameter_factory < cl_mem >::name()
{
	return "cl_mem";
}

template <>
inline std::string parameter_factory < float >::name()
{
	return "float";
}

template <>
inline std::string parameter_factory < double >::name()
{
	return "double";
}

template <>
inline std::string parameter_factory < uint >::name()
{
	return "uint";
}

/*
template <>
kernel_parameter *parameter_factory < unsigned int const& >::parameter( unsigned int const& input)
{
	return new kernel_parameter( & const_cast< unsigned int &> ( input ), sizeof ( cl_uint ) );
}*/
/*
template <>
kernel_parameter *parameter_factory < cl_mem & >::parameter( cl_mem & input)
{
	return new kernel_parameter( &input, sizeof ( cl_mem ) );
}*/


typedef boost::ptr_vector < kernel_parameter > kernel_parameter_list ;


}
