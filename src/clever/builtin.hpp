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

#define  M_E_F           2.71828174591064f
#define  M_LOG2E_F       1.44269502162933f
#define  M_LOG10E_F      0.43429449200630f
#define  M_LN2_F         0.69314718246460f
#define  M_LN10_F        2.30258512496948f
#define  M_PI_F          3.14159274101257f
#define  M_PI_2_F        1.57079637050629f
#define  M_PI_4_F        0.78539818525314f
#define  M_1_PI_F        0.31830987334251f
#define  M_2_PI_F        0.63661974668503f
#define  M_2_SQRTPI_F    1.12837922573090f
#define  M_SQRT2_F       1.41421353816986f
#define  M_SQRT1_2_F     0.70710676908493f

class vectorN {

};

template <typename T>
class vector2 : public vectorN{
public:
	T x;
	T y;

	vector2() {
		x = 0;
		y = 0;
	}

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

	vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

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

	vector4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

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

