//Auto-generated file clever/src/clever/code_gen/gen_kernelfile.py
#pragma once
#include "builtin.hpp"
#include "kernel_base.hpp"
#include "icontext.hpp"
#include "error.hpp"
#include <string>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace clever
{

template< typename T1 >
class kernel_base1 : public clever::kernel_base
{
public:
    kernel_base1( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base1(){}
    cl_event run( T1 data1, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1, range const& r )
    {
        run ( data1, r );
    }
};


#define APPLY_DEFINES1_CLASS(  NAME, TYPE1 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base1< TYPE1 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base1< TYPE1  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL1_CLASS(  NAME,  TYPE1 , FUNCTION )                \
APPLY_DEFINES1_CLASS(  NAME,  TYPE1 , FUNCTION, #FUNCTION )


template< typename T1,typename T2 >
class kernel_base2 : public clever::kernel_base
{
public:
    kernel_base2( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base2(){}
    cl_event run( T1 data1,T2 data2, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2, range const& r )
    {
        run ( data1,data2, r );
    }
};


#define APPLY_DEFINES2_CLASS(  NAME, TYPE1,TYPE2 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base2< TYPE1,TYPE2 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base2< TYPE1,TYPE2  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION )                \
APPLY_DEFINES2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3 >
class kernel_base3 : public clever::kernel_base
{
public:
    kernel_base3( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base3(){}
    cl_event run( T1 data1,T2 data2,T3 data3, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3, range const& r )
    {
        run ( data1,data2,data3, r );
    }
};


#define APPLY_DEFINES3_CLASS(  NAME, TYPE1,TYPE2,TYPE3 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base3< TYPE1,TYPE2,TYPE3 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base3< TYPE1,TYPE2,TYPE3  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION )                \
APPLY_DEFINES3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4 >
class kernel_base4 : public clever::kernel_base
{
public:
    kernel_base4( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base4(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4, range const& r )
    {
        run ( data1,data2,data3,data4, r );
    }
};


#define APPLY_DEFINES4_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base4< TYPE1,TYPE2,TYPE3,TYPE4 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base4< TYPE1,TYPE2,TYPE3,TYPE4  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION )                \
APPLY_DEFINES4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5 >
class kernel_base5 : public clever::kernel_base
{
public:
    kernel_base5( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base5(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, range const& r )
    {
        run ( data1,data2,data3,data4,data5, r );
    }
};


#define APPLY_DEFINES5_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base5< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base5< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION )                \
APPLY_DEFINES5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6 >
class kernel_base6 : public clever::kernel_base
{
public:
    kernel_base6( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base6(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6, r );
    }
};


#define APPLY_DEFINES6_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base6< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base6< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION )                \
APPLY_DEFINES6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7 >
class kernel_base7 : public clever::kernel_base
{
public:
    kernel_base7( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base7(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7, r );
    }
};


#define APPLY_DEFINES7_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base7< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base7< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION )                \
APPLY_DEFINES7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8 >
class kernel_base8 : public clever::kernel_base
{
public:
    kernel_base8( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base8(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8, r );
    }
};


#define APPLY_DEFINES8_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base8< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base8< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION )                \
APPLY_DEFINES8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9 >
class kernel_base9 : public clever::kernel_base
{
public:
    kernel_base9( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base9(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9, r );
    }
};


#define APPLY_DEFINES9_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base9< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base9< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION )                \
APPLY_DEFINES9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10 >
class kernel_base10 : public clever::kernel_base
{
public:
    kernel_base10( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base10(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10, r );
    }
};


#define APPLY_DEFINES10_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base10< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base10< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION )                \
APPLY_DEFINES10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11 >
class kernel_base11 : public clever::kernel_base
{
public:
    kernel_base11( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base11(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11, r );
    }
};


#define APPLY_DEFINES11_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base11< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base11< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION )                \
APPLY_DEFINES11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12 >
class kernel_base12 : public clever::kernel_base
{
public:
    kernel_base12( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base12(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12, r );
    }
};


#define APPLY_DEFINES12_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base12< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base12< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION )                \
APPLY_DEFINES12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13 >
class kernel_base13 : public clever::kernel_base
{
public:
    kernel_base13( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base13(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13, r );
    }
};


#define APPLY_DEFINES13_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base13< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base13< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION )                \
APPLY_DEFINES13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14 >
class kernel_base14 : public clever::kernel_base
{
public:
    kernel_base14( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base14(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14, r );
    }
};


#define APPLY_DEFINES14_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base14< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base14< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION )                \
APPLY_DEFINES14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15 >
class kernel_base15 : public clever::kernel_base
{
public:
    kernel_base15( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base15(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15, r );
    }
};


#define APPLY_DEFINES15_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base15< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base15< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION )                \
APPLY_DEFINES15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16 >
class kernel_base16 : public clever::kernel_base
{
public:
    kernel_base16( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base16(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16, r );
    }
};


#define APPLY_DEFINES16_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base16< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base16< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION )                \
APPLY_DEFINES16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17 >
class kernel_base17 : public clever::kernel_base
{
public:
    kernel_base17( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base17(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17, r );
    }
};


#define APPLY_DEFINES17_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base17< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base17< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION )                \
APPLY_DEFINES17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18 >
class kernel_base18 : public clever::kernel_base
{
public:
    kernel_base18( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base18(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18, r );
    }
};


#define APPLY_DEFINES18_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base18< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base18< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION )                \
APPLY_DEFINES18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19 >
class kernel_base19 : public clever::kernel_base
{
public:
    kernel_base19( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base19(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19, r );
    }
};


#define APPLY_DEFINES19_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base19< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base19< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION )                \
APPLY_DEFINES19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20 >
class kernel_base20 : public clever::kernel_base
{
public:
    kernel_base20( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base20(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20, r );
    }
};


#define APPLY_DEFINES20_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base20< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base20< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION )                \
APPLY_DEFINES20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21 >
class kernel_base21 : public clever::kernel_base
{
public:
    kernel_base21( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base21(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21, r );
    }
};


#define APPLY_DEFINES21_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base21< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base21< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION )                \
APPLY_DEFINES21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22 >
class kernel_base22 : public clever::kernel_base
{
public:
    kernel_base22( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base22(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22, r );
    }
};


#define APPLY_DEFINES22_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base22< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base22< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION )                \
APPLY_DEFINES22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23 >
class kernel_base23 : public clever::kernel_base
{
public:
    kernel_base23( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base23(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23, r );
    }
};


#define APPLY_DEFINES23_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base23< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base23< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION )                \
APPLY_DEFINES23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24 >
class kernel_base24 : public clever::kernel_base
{
public:
    kernel_base24( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base24(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24, r );
    }
};


#define APPLY_DEFINES24_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base24< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base24< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION )                \
APPLY_DEFINES24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25 >
class kernel_base25 : public clever::kernel_base
{
public:
    kernel_base25( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base25(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25, r );
    }
};


#define APPLY_DEFINES25_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base25< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base25< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION )                \
APPLY_DEFINES25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26 >
class kernel_base26 : public clever::kernel_base
{
public:
    kernel_base26( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base26(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26, r );
    }
};


#define APPLY_DEFINES26_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base26< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base26< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION )                \
APPLY_DEFINES26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27 >
class kernel_base27 : public clever::kernel_base
{
public:
    kernel_base27( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base27(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27, r );
    }
};


#define APPLY_DEFINES27_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base27< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base27< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION )                \
APPLY_DEFINES27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28 >
class kernel_base28 : public clever::kernel_base
{
public:
    kernel_base28( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base28(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28, r );
    }
};


#define APPLY_DEFINES28_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base28< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base28< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION )                \
APPLY_DEFINES28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29 >
class kernel_base29 : public clever::kernel_base
{
public:
    kernel_base29( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base29(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29, r );
    }
};


#define APPLY_DEFINES29_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base29< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base29< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION )                \
APPLY_DEFINES29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30 >
class kernel_base30 : public clever::kernel_base
{
public:
    kernel_base30( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base30(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30, r );
    }
};


#define APPLY_DEFINES30_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base30< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base30< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION )                \
APPLY_DEFINES30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30,typename T31 >
class kernel_base31 : public clever::kernel_base
{
public:
    kernel_base31( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base31(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
plist.push_back( parameter_factory< T31>::parameter( data31 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31, r );
    }
};


#define APPLY_DEFINES31_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base31< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base31< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION )                \
APPLY_DEFINES31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, #FUNCTION )


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30,typename T31,typename T32 >
class kernel_base32 : public clever::kernel_base
{
public:
    kernel_base32( const std::string& name, const clever::icontext& context, const std::string& sources )
        : kernel_base(name, context, sources) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base32(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, range const& r ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
plist.push_back( parameter_factory< T31>::parameter( data31 ));
plist.push_back( parameter_factory< T32>::parameter( data32 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, r );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, range const& r )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31,data32, r );
    }
};


#define APPLY_DEFINES32_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_base32< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base32< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32  >( #NAME, context, SOURCES )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION )                \
APPLY_DEFINES32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, #FUNCTION )



}
