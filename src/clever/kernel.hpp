//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_KERNEL_HPP_INCLUDED
#define OPENCLAM_KERNEL_HPP_INCLUDED

#include "builtin.hpp"
#include "icontext.hpp"
#include "error.hpp"
#include <string>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace openclam
{
template< typename T >
class kernel_base : protected openclam::builtin
{
public:
    kernel_base( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        // NOTHING
    }
    virtual ~kernel_base()
    {
        // NOTHING
    }
    void operator()( T* data, ::size_t size )
    {
        context_.execute( data, sizeof( T ) * size, *kernel_ );
    }
protected:
    boost::function< void( T* ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};


template < typename TParam >
int  param ( kernel_parameter_list & paramlist,  TParam  & p )
{
	//return parameter_factory< TParam >::parameter_obj ( p );
	/*std::cout << std::endl << "Transfering parameter ...  " << parameter_factory< TParam >::name();
	std::cout << std::endl << "Size double: " << sizeof ( double ) ;
	std::cout << std::endl << "Size: " << sizeof ( TParam ) ;*/
	paramlist.insert ( paramlist.begin(), parameter_factory< TParam >::parameter ( p ) );
	//paramlist.push_back( parameter_factory< TParam >::parameter ( p )  );
	return 0;
}

// yes, yes, yes, variadic templates ! This is the new shit !
template< typename... TArgs >
class kernel_base_var : protected openclam::builtin
{
public:
    kernel_base_var( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        // NOTHING
    }

    virtual ~kernel_base_var()
    {
        // NOTHING
    }

    void run ( range const& r, TArgs const... args ) const
    {
    	//run_kparam( r,  param(args)... );
    	//context_.execute_params_var( *kernel_, r,  param(args)... );
    	kernel_parameter_list paramlist;
    	paramlist.reserve(8);

    	// is it guarantee in which order param is called ??
    	// maybe use iterative templates to do this in a better way
    	wrapper ( param( paramlist,  args )... );

    	for ( kernel_parameter_list::const_iterator it = paramlist.begin();
    		  it != paramlist.end(); ++ it )
    	{
    		std::cout << "_X: " <<  it->size_ << " - " << it->typename_fordebug_ <<  std::endl;
    	}

    	context_.execute_params( paramlist, *kernel_, r, true );
    }

    void wrapper ( int const& r, ... ) const
    {

    }

protected:
    //boost::function< void( T* ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};




// still some problems with the boost :: bind stuff
#define APPLY_DEFINES2_CLASS(  NAME,  TYPE1, TYPE2,  FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base_var< TYPE1, TYPE2 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& context )              \
                : openclam::kernel_base_var< TYPE1, TYPE2 >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME

#define KERNEL2_CLASS(  NAME,  TYPE1, TYPE2, FUNCTION )            \
APPLY_DEFINES2_CLASS(  NAME,  TYPE1, TYPE2, FUNCTION, #FUNCTION )



template< typename T1, typename T2 >
class kernel_base2 : protected openclam::builtin
{
public:
    kernel_base2( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
    	assert ( kernel_ );
        // NOTHING
    }
    virtual ~kernel_base2()
    {
        // NOTHING
    }
    void just_a_test_call() const
    {
    	int i = 34;
    	i++;
    }

    void run( T1 data1, T2  data2, range const& r ) const
    {
    	kernel_parameter_list plist;

    	kernel_parameter * p1 = parameter_factory< T1 >::parameter( data1 );
    	kernel_parameter * p2 = parameter_factory< T2 >::parameter( data2 );
    	plist.push_back( p1 );
    	plist.push_back( p2 );

        //context_.
    	assert ( kernel_ );
    	context_.execute_params( plist ,  *kernel_, r );
    }

    void operator()( T1 data1, T2  data2, range const& r )
    {
    	run ( data1, data2, r );
    }
protected:
    //boost::function< void( T1 , T2 ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};

template< typename T1, typename T2,  typename T3 >
class kernel_base3 : protected openclam::builtin
{
public:
    kernel_base3( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        // NOTHING
    }
    virtual ~kernel_base3()
    {
        // NOTHING
    }
    void operator()( T1 data1, T2  data2, T3  data3, range const& r )
    {
    	kernel_parameter_list plist;

    	kernel_parameter * p1 = parameter_factory< T1 >::parameter( data1 );
    	kernel_parameter * p2 = parameter_factory< T2 >::parameter( data2 );
    	kernel_parameter * p3 = parameter_factory< T3 >::parameter( data3 );

    	plist.push_back( p1 );
    	plist.push_back( p2 );
    	plist.push_back( p3 );


        //context_.
    	context_.execute_params( plist ,  *kernel_, r );
    }
protected:
    //boost::function< void( T1 , T2 ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};



template< typename T1, typename T2,  typename T3, typename T4 >
class kernel_base4 : protected openclam::builtin
{
public:
    kernel_base4( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        // NOTHING
    }
    virtual ~kernel_base4()
    {
        // NOTHING
    }
    void run( T1 data1, T2  data2, T3  data3, T4 data4, range const& r ) const
    {
    	kernel_parameter_list plist;

    	kernel_parameter * p1 = parameter_factory< T1 >::parameter( data1 );
    	kernel_parameter * p2 = parameter_factory< T2 >::parameter( data2 );
    	kernel_parameter * p3 = parameter_factory< T3 >::parameter( data3 );
    	kernel_parameter * p4 = parameter_factory< T4 >::parameter( data4 );

    	plist.push_back( p1 );
    	plist.push_back( p2 );
    	plist.push_back( p3 );
    	plist.push_back( p4 );

        //context_.
    	context_.execute_params( plist ,  *kernel_, r );
    }

    void operator()(T1 data1, T2  data2, T3  data3, T4 data4,range const& r ) const
    {
    	run ( data1, data2, data3, data4, r );
    }
protected:
    //boost::function< void( T1 , T2 ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};


template< typename T1, typename T2,  typename T3, typename T4, typename T5 >
class kernel_base5 : protected openclam::builtin
{
public:
    kernel_base5( const std::string& name, const openclam::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        // NOTHING
    }
    virtual ~kernel_base5()
    {
        // NOTHING
    	std::cout << std::endl << "kernel5 dest called";
    }

    cl_event run ( T1 data1, T2  data2, T3  data3, T4 data4, T5 data5,range const& r ) const
    {
    	kernel_parameter_list plist;

    	kernel_parameter * p1 = parameter_factory< T1 >::parameter( data1 );
    	kernel_parameter * p2 = parameter_factory< T2 >::parameter( data2 );
    	kernel_parameter * p3 = parameter_factory< T3 >::parameter( data3 );
    	kernel_parameter * p4 = parameter_factory< T4 >::parameter( data4 );
    	kernel_parameter * p5 = parameter_factory< T4 >::parameter( data5 );

    	plist.push_back( p1 );
    	plist.push_back( p2 );
    	plist.push_back( p3 );
    	plist.push_back( p4 );
    	plist.push_back( p5 );

        //context_.
    	cl_event evt = context_.execute_params( plist ,  *kernel_, r );
/*
    	if ( context_.is_profiling() )
    		context_.add_profile_event( evt, this->name_ );
*/
    	return evt;
    }

    void operator()(T1 data1, T2  data2, T3  data3, T4 data4, T5 data5,range const& r ) const
    {
    	run ( data1, data2, data3, data4, data5, r );
    }
protected:
    //boost::function< void( T1 , T2 ) > f_;
private:
    const openclam::icontext& context_;
    std::unique_ptr< openclam::ikernel_proxy > kernel_;
};
}

#define __kernel
//dont use for now
//#define kernel

#define __local

#define __global
// dont use for now
//#define global

#define APPLY_DEFINES( NAME, CONTEXT, TYPE, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base< TYPE >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& CONTEXT )              \
                : openclam::kernel_base< TYPE >( #NAME, CONTEXT, SOURCES )  \
             {                                                              \
                type_check();                                               \
                f_ = boost::bind( &NAME##_CLASS :: NAME, this, _1 );        \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    void type_check(){ TYPE data; NAME( &data ); }                          \
    FUNCTION;                                                               \
} NAME( CONTEXT );

#define KERNEL( NAME, CONTEXT, TYPE, FUNCTION )            \
APPLY_DEFINES( NAME, CONTEXT, TYPE, FUNCTION, #FUNCTION );



/// K 3
#define APPLY_DEFINES3( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base3< TYPE1, TYPE2, TYPE3 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& CONTEXT )              \
                : openclam::kernel_base3< TYPE1, TYPE2, TYPE3 >( #NAME, CONTEXT, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION;                                                               \
} NAME( CONTEXT );

#define KERNEL3( NAME, CONTEXT, TYPE1, TYPE2, TYPE3,FUNCTION )            \
APPLY_DEFINES3( NAME, CONTEXT, TYPE1, TYPE2, TYPE3,FUNCTION, #FUNCTION );



#define APPLY_DEFINES4( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base4< TYPE1, TYPE2, TYPE3, TYPE4 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& CONTEXT )              \
                : openclam::kernel_base4< TYPE1, TYPE2, TYPE3, TYPE4 >( #NAME, CONTEXT, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION;                                                               \
} NAME( CONTEXT );

#define KERNEL4( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, FUNCTION )            \
APPLY_DEFINES4( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, FUNCTION, #FUNCTION );

// still some problems with the boost :: bind stuff
#define APPLY_DEFINES4_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base4< TYPE1, TYPE2,TYPE3,TYPE4 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& context )              \
                : openclam::kernel_base4< TYPE1, TYPE2,TYPE3,TYPE4 >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME

#define KERNEL4_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4, FUNCTION )            \
APPLY_DEFINES4_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4, FUNCTION, #FUNCTION )




/// 5 ////

#define APPLY_DEFINES5( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, TYPE5, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base5< TYPE1, TYPE2, TYPE3, TYPE4, TYPE5 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& CONTEXT )              \
                : openclam::kernel_base5< TYPE1, TYPE2, TYPE3, TYPE4, TYPE5 >( #NAME, CONTEXT, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION;                                                               \
} NAME( CONTEXT );

#define KERNEL5( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, TYPE5,FUNCTION )            \
APPLY_DEFINES5( NAME, CONTEXT, TYPE1, TYPE2, TYPE3, TYPE4, TYPE5, FUNCTION, #FUNCTION );



// still some problems with the boost :: bind stuff
#define APPLY_DEFINES5_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4,TYPE5, FUNCTION, SOURCES )             \
class NAME##_CLASS : public openclam::kernel_base5< TYPE1, TYPE2,TYPE3,TYPE4,TYPE5 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const openclam::icontext& context )              \
                : openclam::kernel_base5< TYPE1, TYPE2,TYPE3,TYPE4,TYPE5 >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}  											\
private:                                                                    \
    FUNCTION                                                               \
} NAME

#define KERNEL5_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4,TYPE5, FUNCTION )            \
APPLY_DEFINES5_CLASS(  NAME,  TYPE1, TYPE2,TYPE3,TYPE4,TYPE5, FUNCTION, #FUNCTION )







#endif // #ifndef OPENCLAM_KERNEL_HPP_INCLUDED
