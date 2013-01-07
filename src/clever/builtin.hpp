//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/noncopyable.hpp>

namespace clever
{

class vectorN {

};

template <typename T>
class vector2 : public vectorN{
public:
	T x;
	T y;

	vector2(T _x, T _y) {
		x = _x;
		y = _y;
	}
};

template <typename T>
class vector3 : public vectorN{
	T x;
	T y;
	T z;

	vector3(T _x, T _y, T _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};

template <typename T>
class vector4 : public vectorN{
	T x;
	T y;
	T z;
	T w;

	vector4(T _x, T _y, T _z, T _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
};

typedef vector2<float> float2;
typedef vector3<float> float3;
typedef vector4<float> float4;

typedef vector2<double> double2;
typedef vector3<double> double3;
typedef vector4<double> double4;

typedef vector2<int> int2;
typedef vector3<int> int3;
typedef vector4<int> int4;

typedef vector2<uint> uint2;
typedef vector3<uint> uint3;
typedef vector4<uint> uint4;


class builtin : private boost::noncopyable
{
public:
             builtin() {}
    virtual ~builtin() {}
protected:
    unsigned int get_global_id( unsigned int ){ return 0; }
    unsigned int get_global_size( unsigned int ){ return 0; }

    unsigned int get_local_id( unsigned int ){ return 0; }
    unsigned int get_local_size( unsigned int ){ return 0; }

    unsigned int atomic_or(unsigned int * x, unsigned int a) { return (*x) ^ a; }

    template <class TType >
    TType atomic_inc( TType * p ) { return TType(); }

    double native_sqrt( double d ){ return 0.0; }
    double native_log( double d ){ return 0.0; }

    //vectorN cross(vectorN a, vectorN b) { return a.cross(b); }
    //floatN normalize(floatN a) { return a.normalize(); }
};

}

