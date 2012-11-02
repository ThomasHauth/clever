
max_params = 32

file_header = "//Auto-generated file clever/src/clever/code_gen/gen_kernelfile.py\n\
#pragma once\n\
#include \"builtin.hpp\"\n\
#include \"icontext.hpp\"\n\
#include \"error.hpp\"\n\
#include <string>\n\
#include <algorithm>\n\
#include <boost/function.hpp>\n\
#include <boost/bind.hpp>\n\
\n\
#define __kernel\n\
#define __local\n\
#define __global\n\
\n\
namespace clever\n\
{\n"

file_footer = "\n}"


#   #paramnumber#
#   #paramlist#
#   #paramtemplate#
#   #parammethod#
#   #paramcall#
kernel_class_template="template< #paramtemplate# >\n\
class kernel_base#paramnumber# : protected clever::builtin\n\
{\n\
public:\n\
    kernel_base#paramnumber#( const std::string& name, const clever::icontext& context, const std::string& sources )\n\
        : context_( context )\n\
        , kernel_ ( context.create( name, sources ) )\n\
    {\n\
        assert ( kernel_ );\n\
    }\n\
    virtual ~kernel_base#paramnumber#(){}\n\
    cl_event run( #parammethod# range const& r ) const\n\
    {\n\
        kernel_parameter_list plist;\n\
        #paramlist# \n\
        assert ( kernel_ );\n\
        return context_.execute_params( plist ,  *kernel_, r );\n\
    }\n\
    void operator()( #parammethod# range const& r )\n\
    {\n\
        run ( #paramcall# r );\n\
    }\n\
private:\n\
    const clever::icontext& context_;\n\
    std::unique_ptr< clever::ikernel_proxy > kernel_;\n\
};\n\n"

kernel_defines = "#define APPLY_DEFINES#paramnumber#_CLASS(  NAME, #paramtypes# , FUNCTION, SOURCES ) \\\n\
class NAME##_CLASS : public clever::kernel_base#paramnumber#< #paramtypes# >                   \\\n\
{                                                                           \\\n\
public:                                                                     \\\n\
    explicit NAME##_CLASS( const clever::icontext& context )              \\\n\
                : clever::kernel_base#paramnumber#< #paramtypes#  >( #NAME, context, SOURCES )  \\\n\
             {                                                              \\\n\
             }                                                              \\\n\
    virtual ~NAME##_CLASS() {}                                              \\\n\
private:                                                                    \\\n\
    FUNCTION                                                               \\\n\
} NAME                                                                      \n\
#define KERNEL#paramnumber#_CLASS(  NAME,  #paramtypes# , FUNCTION )                \\\n\
APPLY_DEFINES#paramnumber#_CLASS(  NAME,  #paramtypes# , FUNCTION, #FUNCTION )\n\n"

print file_header

for i in range (1, max_params + 1):
    template_class = kernel_class_template
    template_defines = kernel_defines
    
    template_class = template_class.replace( "#paramnumber#", str(i))

    paramlist = ""
    paramtemplate = ""
    paramcall = ""
    parammethod = ""
    paramtypes = ""
    
    for local_i in range ( 1, i + 1 ):        
        paramlist += "plist.push_back( parameter_factory< T" + str(local_i) + ">::parameter( data" + str(local_i) + " ));\n"
        paramtemplate += "typename T" + str(local_i) + ","
        parammethod += "T" + str(local_i) + " data" + str(local_i) + ","
        paramcall += "data" + str(local_i) + ","
        paramtypes += "TYPE" + str(local_i) + ","

    #drop last ","
    paramtypes = paramtypes[:-1]

    template_class = template_class.replace( "#parammethod#", parammethod)

    template_class = template_class.replace( "#paramcall#", paramcall)
    template_class = template_class.replace( "#paramlist#", paramlist)
    
    paramtemplate = paramtemplate[:-1]
    template_class = template_class.replace( "#paramtemplate#", paramtemplate)


    template_defines = template_defines.replace("#paramnumber#", str(i))
    template_defines = template_defines.replace("#paramtypes#", paramtypes )
    
    #print "Generating class for " + str(i) + " parameter(s)"
    
    print template_class
    print template_defines

print file_footer

    