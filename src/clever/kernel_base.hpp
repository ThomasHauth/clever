//Auto-generated file clever/src/clever/code_gen/gen_kernelfile.py
#pragma once
#include "builtin.hpp"
#include "icontext.hpp"
#include "error.hpp"
#include <string>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#define __kernel
#define __local
#define __global

namespace clever
{

class kernel_base : protected clever::builtin
{
public:
    kernel_base( const std::string& name, const clever::icontext& context, const std::string& sources )
        : context_( context )
        , kernel_ ( context.create( name, sources ) )
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base(){}

protected:
    const clever::icontext& context_;
    std::unique_ptr< clever::ikernel_proxy > kernel_;
};
}
