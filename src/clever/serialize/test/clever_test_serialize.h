//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <string>
#include <map>

#include <gtest/gtest.h>

#include "../../clever.hpp"

struct CustomVector3 {

	float m_x;
	float m_y;
	float m_z;

	// free space to fit into a
	//float m_a;

	template<class Store>
	void serialize(Store & st) {

	}
};

class MyResultClass {

	// number of the found particle
	template<class Store>
	void serialize(Store & st) {
		// allow to set read/write stuff here
		st.transfer("m_x", m_x);
		st.transfer("m_y", m_y);
		st.transfer("m_z", m_z);

		///st.transfer ("m_position", m_position);
	}
};

class MyDataClass {
public:

	// todo: can we also store x/y/z in a float3 directly ?

	float m_x;
	float m_y;
	float m_z;
	CustomVector3 m_position;

	template<class Store>
	void serialize(Store & st) {
		// allow to set read/write stuff here
		st.transfer("m_x", m_x);
		st.transfer("m_y", m_y);
		st.transfer("m_z", m_z);

		///st.transfer ("m_position", m_position);
	}
};

class store_extract_info {
public:
	template<class T>
	void transfer(std::string const& field_name, T const& val) {
		std::cout << "field_name: " << field_name << std::endl;
	}
};

template<class TType>
class TypeToString {
public:
	static std::string str();
};

template<class TType>
class TypeToCLType {
public:
	static std::string str();
};

template<>
std::string TypeToString<float>::str() {
	return "float";
}

template<>
std::string TypeToString<CustomVector3>::str() {
	return "CustomVector3";
}

template<>
std::string TypeToCLType<float>::str() {
	return "float";
}

template<>
std::string TypeToCLType<CustomVector3>::str() {
	return "float3";
}


class DataVectorBase : public  boost::noncopyable
{
public:
	DataVectorBase( clever::context & con) :
	m_context ( con ) {}

	virtual ~DataVectorBase( ) {}

	virtual void transferToDevice () = 0;

	virtual std::string clType () const = 0;
	virtual std::string clTypePtr () const = 0;

	virtual cl_mem & getClBuffer() = 0;

	clever::context & m_context;
};

template < class TType >
class DataVector : public DataVectorBase
{
public:
	DataVector ( clever::context & con, size_t size ) :
		DataVectorBase( con ),
		vect( size )
	{
	}

	virtual void transferToDevice () override
	{
		m_clBuffer = new clever::vector< TType , 1 > ( vect, m_context );
	}

	// might use a constexpr here !
	virtual std::string clType () const override
			{
		return TypeToCLType< TType >::str();
			}

	virtual std::string clTypePtr () const override
			{
		return clType() + " *";
			}

	virtual cl_mem & getClBuffer() override
			{
		assert( m_clBuffer );
		return m_clBuffer->get_mem_ref();
			}

	std::vector < TType > vect;
	clever::vector< TType , 1 > * m_clBuffer = nullptr;
};


class Storage
{
public:
	Storage (  )
	{

	}


	typedef std::map<std::string, DataVectorBase *> BufferType;
	BufferType m_buffer;

	BufferType & getBuffer()
	{
		return m_buffer;
	}
};

class store_write_buffer {
public:
	store_write_buffer( clever::context & con, Storage & stor) :
			m_position(0), m_context ( con ), m_storage ( stor ) {
	}

	~store_write_buffer ()
	{

	}

	template<class TVector >
	void initialize( TVector const& vec)
	{
		m_position = 0;
		m_vectorSize = vec.size();
	}

	template<class T>
	void transfer(std::string const& field_name, T const& val) {
		DataVector< T > * dataVector = 0;
		//std::cout << "field_name: " << field_name << std::endl;
		if (getBuffers().find(field_name) == getBuffers().end())
		{
			std::cout << "Creating buffer for field " << field_name
					<< " of size " << sizeof(T) << " and type "
					<< TypeToString<T>::str() << std::endl;
			std::cout << "Buffer will have " << m_vectorSize << " entries" << std::endl;

			dataVector =  new DataVector< T >( m_context,  m_vectorSize );
			getBuffers()[field_name] = dataVector;
		}
		else
		{
			dataVector = static_cast < DataVector< T > * > ( getBuffers()[field_name] );
		}

		assert ( dataVector != 0 );

		std::cout << "Filling buffer for field " << field_name
				<< " at location " << m_position << std::endl;

		dataVector->vect[ m_position ] = val;
	}

	void finalize()
	{
		// create the buffers on OpenCL and copy values
		for ( auto & p: getBuffers()  )
		{
			std::cout << "Creating & Transfering Buffer "  << p.first << std::endl;
			p.second->transferToDevice () ;
		}
	}

	Storage::BufferType & getBuffers()
	{
		return m_storage.m_buffer;
	}

	int m_vectorSize;
	int m_position;
	clever::context & m_context;
	// how to hold the vectors of various numbers ?

	Storage & m_storage;
};


class generate_kernel_frame
{
public:
	static	std::string getFrame(store_write_buffer & wbuffer, std::string const& kernel_name)
	{
		std::stringstream strAccess;
		std::stringstream strKernel;

		// create access
		// skip it, the code to use this is to verbose
		/*
		for ( auto & p: wbuffer.m_buffer  )
		{
			// get
			strAccess << p.second->clType() << " get_" << p.first << " ( __global " <<  p.second->clTypePtr() << " buffer " <<
					", int index ) " << std::endl;
			strAccess << "{" << std::endl;
			strAccess << "   return buffer [ index ];" << std::endl;
			strAccess << "}" << std::endl;

			// set
			strAccess << "void set_" << p.first << " ( __global " <<  p.second->clTypePtr() << " buffer " <<
					", int index, " << p.second->clType() << " newVal ) " << std::endl;
			strAccess << "{" << std::endl;
			strAccess << "   buffer [ index ] = newVal;" << std::endl;
			strAccess << "}" << std::endl;
		}*/
		/*
		 *
		 * __kernel void add_val( const double a, const double b ) { }
		 */
		strKernel << "__kernel void " << kernel_name << "(" ;
		size_t count = 0;
		for ( auto & p: wbuffer.getBuffers()  )
		{
			// todo: use full path here
			strKernel << "__global " << p.second->clTypePtr() << p.first ;

			count++;
			if ( count < wbuffer.getBuffers().size())
				{
				strKernel << "," << std::endl;
				}
/*			std::cout << "Creating & Transfering Buffer "  << p.first << std::endl;
			p.second->transferToDevice () ;*/
		}
		strKernel << " ) {}";
		return strAccess.str() +  strKernel.str ();
	}
};

TEST( clever_serialize, transfer ) {
	clever::context context;
	std::vector<MyDataClass *> myVector;
	const size_t maxElements = 5 ;

	for (size_t i = 0; i < maxElements; ++i) {
		MyDataClass * dClass = new MyDataClass();
		dClass->m_x = log( i + 1 );
		myVector.push_back(dClass);
	}

	// can transfer only one data type > class
	Storage storage;
	store_write_buffer store_write ( context, storage );
	store_write.initialize( myVector );

	for (auto elem : myVector) {
		store_write.m_position++;
		elem->serialize(store_write);
	}
	store_write.finalize();

	// will be defined as variable "add_val" method local
	KERNEL_STORAGE_CLASS( add_val,  Storage ,
	{
			int i_x = get_global_id( 0 );
			float my_mx = m_x[ i_x ];
			printf ( "kernel test output: m_x = %f\n", my_mx);
	})
	(context, storage);

	add_val.run( storage, clever::range( maxElements ) );

	std::cout << "Source: " << std::endl <<add_val.getSource () << std::endl;
	std::cout << "Kernel Frame: " << std::endl << generate_kernel_frame::getFrame( store_write, "blah_kernel" ) << std::endl;

	//add_val.run( 23.0, 24.0,  clever::null_range );
	// todo: delete vector

}
