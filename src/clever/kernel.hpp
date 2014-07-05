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

template<typename... Args>
class kernel_baseN : public clever::kernel_base
{

public:

    kernel_baseN(const std::string &name, const clever::icontext &context, const std::string &sources, const std::string &preprocessor)
    : kernel_base(name, context, sources, preprocessor) 
    {
        assert (kernel_);
    }

    virtual ~kernel_baseN(){}   

    cl_event run(Args... args, const clever::range &globalRange, const clever::range &localRange) const
    {
        kernel_parameter_list plist;

        fill_kernel_parameter_list(plist, args...);

        assert (kernel_);

        return context_.execute_params(plist, *kernel_, globalRange, localRange);
    }

    cl_event run(Args... args, const clever::range &globalRange) const
    {
        return run(args..., globalRange, null_range());
    }
    
    void operator()(Args... args, range const &globalRange, range const &localRange)
    {
        run (args..., globalRange, localRange);
    }
    
    void operator()(Args... args, range const &globalRange )
    {
        run (args..., globalRange);
    }


private:

    template<typename T, typename...Args_>
    void fill_kernel_parameter_list(kernel_parameter_list &plist, T data, Args_...args) const
    {
        plist.push_back( parameter_factory<T>::parameter(data));
        fill_kernel_parameter_list(plist, args...);
    }

    template<typename T>
    void fill_kernel_parameter_list(kernel_parameter_list &plist, T data) const
    {
        //base case for fill_kernel_parameter_list template recursion.
        plist.push_back( parameter_factory<T>::parameter(data));
    }
};


#define APPLY_DEFINES1_CLASS(  NAME, TYPE1 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL1_CLASS(  NAME,  TYPE1 , FUNCTION ) APPLY_DEFINES1_CLASS(  NAME,  TYPE1 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL1_CLASSP(  NAME,  TYPE1 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES1_CLASS(  NAME,  TYPE1 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES2_CLASS(  NAME, TYPE1,TYPE2 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION ) APPLY_DEFINES2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL2_CLASSP(  NAME,  TYPE1,TYPE2 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION, #FUNCTION, PREPROCESSOR ) 



#define APPLY_DEFINES3_CLASS(  NAME, TYPE1,TYPE2,TYPE3 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION ) APPLY_DEFINES3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL3_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES4_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION ) APPLY_DEFINES4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL4_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES5_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION ) APPLY_DEFINES5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL5_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES6_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION ) APPLY_DEFINES6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL6_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES7_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION ) APPLY_DEFINES7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL7_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES8_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION ) APPLY_DEFINES8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL8_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES9_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION ) APPLY_DEFINES9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL9_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES10_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION ) APPLY_DEFINES10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL10_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES11_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION ) APPLY_DEFINES11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL11_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES12_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION ) APPLY_DEFINES12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL12_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES13_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION ) APPLY_DEFINES13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL13_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES14_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION ) APPLY_DEFINES14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL14_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES15_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION ) APPLY_DEFINES15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL15_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES16_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION ) APPLY_DEFINES16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL16_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES17_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION ) APPLY_DEFINES17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL17_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES18_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION ) APPLY_DEFINES18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL18_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES19_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION ) APPLY_DEFINES19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL19_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES20_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION ) APPLY_DEFINES20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL20_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES21_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION ) APPLY_DEFINES21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL21_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES22_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION ) APPLY_DEFINES22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL22_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES23_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION ) APPLY_DEFINES23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL23_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES24_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION ) APPLY_DEFINES24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL24_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES25_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION ) APPLY_DEFINES25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL25_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES26_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION ) APPLY_DEFINES26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL26_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES27_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION ) APPLY_DEFINES27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL27_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES28_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION ) APPLY_DEFINES28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL28_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES29_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION ) APPLY_DEFINES29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL29_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES30_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION ) APPLY_DEFINES30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL30_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES31_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION ) APPLY_DEFINES31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL31_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


#define APPLY_DEFINES32_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_baseN< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION ) APPLY_DEFINES32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL32_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, #FUNCTION, PREPROCESSOR ) 

}

