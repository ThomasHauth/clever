#pragma once

#include "Collection.hpp"
#include "OpenCLTransfer.h"

namespace clever
{

template<class ... TItems>
class OpenCLCollection
{
public:
	typedef clever::Collection<TItems...> collection_type;
	typedef clever::OpenCLTransfer<TItems...> transfer_type;
};

}
