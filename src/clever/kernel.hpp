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
    void fill_kernel_parameter_list(kernel_parameter_list &plist, T data, Args_...args) const {
	plist.push_back( parameter_factory<T>::parameter(data));
        fill_kernel_parameter_list(plist, args...);
    }
    
    template<typename T>
    void fill_kernel_parameter_list(kernel_parameter_list &plist, T data) const {
        //base case for fill_kernel_parameter_list template recursion.
	plist.push_back( parameter_factory<T>::parameter(data));
    }
};

#define APPLY_DEFINES_CLASS( NAME, FUNCTION, SOURCES, PREPROCESSOR, ... )  \
class NAME##_CLASS : public clever::kernel_baseN< __VA_ARGS__ >            \
{                                                                          \
public:                                                                    \
    explicit NAME##_CLASS( const clever::icontext& context )               \
                : clever::kernel_baseN< __VA_ARGS__  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                             \
             }                                                             \
    virtual ~NAME##_CLASS() {}                                             \
private:                                                                   \
    FUNCTION                                                               \
} NAME

#define KERNEL_CLASS( NAME, FUNCTION, ... ) APPLY_DEFINES_CLASS(  NAME, FUNCTION, #FUNCTION, "", __VA_ARGS__ ) 
#define KERNEL_CLASSP( NAME, PREPROCESSOR, FUNCTION, ... ) APPLY_DEFINES_CLASS(  NAME, FUNCTION, #FUNCTION, PREPROCESSOR, __VA_ARGS__ ) 

}

