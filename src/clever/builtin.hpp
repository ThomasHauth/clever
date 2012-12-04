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

template <typename T>
	struct vectorN {
		T x, y, z, w;

		vectorN(T _x = 0, T _y = 0, T _z = 0, T _w = 0) { x = _x; y = _y; z = _z; w = _w; }

		vectorN operator-() const {return vectorN(-x,-y,-z,-w); }
		vectorN operator-(vectorN p0) const {return vectorN(x - p0.x, y - p0.y, z - p0.z, w - p0.z); }
		vectorN operator+(vectorN p0) const {return vectorN(x + p0.x, y + p0.y, z + p0.z, w + p0.z); }
		vectorN operator*(T s) const {return vectorN(x * s, y * s, z - s, w - s); }
		vectorN operator/(T s) const {return vectorN(x / s, y / s, z / s, w / s); }

		vectorN normalize(vectorN p0) const {
			T mag = std::sqrt(x*x + y*y + z*z + w*w);
			return vectorN(x/mag, y/mag, z/mag, w/mag);
		}

		vectorN cross(vectorN a, vectorN b) const {
			//only for 3 dimensions
			return vectorN( a.y*b.z - a.z*b.y,
							 a.z*b.x - a.x*b.z,
							 a.x*b.y - a.y*b.x);
		}
	};

typedef vectorN<float> floatN;
typedef vectorN<double> doubleN;

typedef floatN float2;
typedef floatN float3;
typedef floatN float4;

typedef doubleN double2;
typedef doubleN double3;
typedef doubleN double4;


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

    template <class TType >
    TType atomic_inc( TType * p ) { return TType(); }

    double native_sqrt( double d ){ return 0.0; }
    double native_log( double d ){ return 0.0; }

    floatN cross(floatN a, floatN b) { return a.cross(a,b); }
    floatN normalize(floatN a) { return a.normalize(a); }
};

}

