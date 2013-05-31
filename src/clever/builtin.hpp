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

#define CLK_LOCAL_MEM_FENCE 1

#define MAXFLOAT CL_MAXFLOAT

class vectorN {
public:
	template <typename T>
	T operator-(const T & rhs) const { //binary minus operator
		return T();
	}

};

template <typename T>
T operator-(const T & lhs) { //unary minus operator
		return T();
	}

template <typename T>
class vector2 : public vectorN{
public:
	T x;
	T y;

	vector2(T _x = 0, T _y = 0) {
		x = _x;
		y = _y;
	}
};

template <typename T>
class vector3 : public vectorN{
public:
	T x;
	T y;
	T z;

	vector3(T _x = 0, T _y = 0, T _z = 0) {
		x = _x;
		y = _y;
		z = _z;
	}
};

template <typename T>
class vector4 : public vectorN{
public:
	T x;
	T y;
	T z;
	T w;

	vector4(T _x = 0, T _y = 0, T _z = 0, T _w = 0) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
};

template <typename T>
class vector8 : public vectorN{
public:
	T i0;
	T i1;
	T i2;
	T i3;
	T i4;
	T i5;
	T i6;
	T i7;

	vector8(T _0 = 0,T _1 = 0, T _2 = 0, T _3 = 0, T _4 = 0, T _5 = 0, T _6 = 0, T _7 = 0) {
		i0 = _0;
		i1 = _1;
		i2 = _2;
		i3 = _3;
		i4 = _4;
		i5 = _5;
		i6 = _6;
		i7 = _7;
	}
};

template <typename T>
class vector16 : public vectorN{
public:
	T i0;
	T i1;
	T i2;
	T i3;
	T i4;
	T i5;
	T i6;
	T i7;
	T i8;
	T i9;
	T iA;
	T iB;
	T iC;
	T iD;
	T iE;
	T iF;

	vector16(T _0 = 0, T _1 = 0, T _2 = 0, T _3 = 0, T _4 = 0, T _5 = 0, T _6 = 0, T _7 = 0,
			  T _8 = 0, T _9 = 0, T _a = 0, T _b = 0, T _c = 0, T _d = 0, T _e = 0, T _f = 0) {

		i0 = _0;
		i1 = _1;
		i2 = _2;
		i3 = _3;
		i4 = _4;
		i5 = _5;
		i6 = _6;
		i7 = _7;
		i8 = _8;
		i9 = _9;
		iA = _a;
		iB = _b;
		iC = _c;
		iD = _d;
		iE = _e;
		iF = _f;
		}
};

typedef vector2<float> float2;
typedef vector3<float> float3;
typedef vector4<float> float4;
typedef vector8<float> float8;
typedef vector16<float> float16;

typedef vector2<double> double2;
typedef vector3<double> double3;
typedef vector4<double> double4;
typedef vector8<double> double8;
typedef vector16<double> double16;

typedef vector2<int> int2;
typedef vector3<int> int3;
typedef vector4<int> int4;
typedef vector8<int> int8;
typedef vector16<int> int16;

typedef vector2<uint> uint2;
typedef vector3<uint> uint3;
typedef vector4<uint> uint4;
typedef vector8<uint> uint8;
typedef vector16<uint> uint16;

typedef size_t event_t;

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

    unsigned int get_group_id( unsigned int ){ return 0; }
    unsigned int get_num_groups( unsigned int ){ return 0; }

    unsigned int atomic_or(unsigned int * x, unsigned int a) { return (*x) ^ a; }

    unsigned int mul24(unsigned int a, unsigned int b){return a*b;}
    unsigned int popcount(unsigned int a) { return 0; }

    void barrier(uint i) { };

    template <class TType >
    TType atomic_inc( TType * p ) { return TType(); }
    template <class TType >
    TType atomic_add( TType * p, TType v ) { return TType(); }

    double native_sqrt( double d ){ return 0.0; }
    double native_log( double d ){ return 0.0; }

    double sign(double x) { return x > 0 ? 1 : -1; }

    event_t async_work_group_copy(void * dst, void * src, size_t num_gentypes, event_t event) { return (event_t) 0; }

    template <typename T>
    T cross(T a, T b) { return T(); }

    template <typename T>
    T normalize(T a) { return T(); }
};

}

