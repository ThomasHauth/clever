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


template< typename TStorage >
class kernel_storage : protected clever::builtin
{
public:
	kernel_storage( const std::string& name, const clever::icontext& context,
			const std::string& sources, TStorage & storage  )
        : context_( context )

		, m_storage( storage )
    {
		std::stringstream kernelSignature;
		kernelSignature << " __kernel void " << name << " ( ";
		// generate the function header for this kernel
		size_t count = 0;
		for ( auto & p: m_storage.getBuffer()  )
		{
			// get
			kernelSignature << "__global " << p.second->clTypePtr() << p.first;

			count++;
			if ( count < storage.getBuffer().size())
			{
				kernelSignature << "," << std::endl;
			}
			else
			{
				kernelSignature << ")" << std::endl;
			}

		}

		kernelSignature << sources;

		kernel_ = std::unique_ptr< clever::ikernel_proxy >( context.create( name, kernelSignature.str() ) );
        assert ( kernel_ );
    }
    virtual ~kernel_storage(){}
    cl_event run( TStorage & storage , range const& r ) const
    {
        kernel_parameter_list plist;

		for ( auto & p: m_storage.getBuffer()  )
		{
			plist.push_back( parameter_factory< cl_mem >::parameter( p.second->getClBuffer() ));

			//plist.push_back( new kernel_parameter( p.second->getClBuffer(), sizeof ( cl_mem ), "cl_mem" ));
		}
        return context_.execute_params( plist ,  *kernel_, r );
    }

    virtual std::string const& getSource() const
    {
    	return kernel_->getSource();
    }

private:

    const clever::icontext& context_;

    TStorage & m_storage;
    std::unique_ptr< clever::ikernel_proxy > kernel_;
};

// todo: add the compilation of the function again
#define APPLY_KERNEL_STORAGE_CLASS(  NAME, STORAGE , FUNCTION, SOURCES ) \
class NAME##_CLASS : public clever::kernel_storage< STORAGE >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context, STORAGE storage )              \
                : clever::kernel_storage< STORAGE > ( #NAME, context, SOURCES, storage  )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
} NAME
#define KERNEL_STORAGE_CLASS(  NAME,  STORAGE , FUNCTION_BODY )                \
APPLY_KERNEL_STORAGE_CLASS(  NAME,  STORAGE , FUNCTION_BODY, #FUNCTION_BODY )
}
