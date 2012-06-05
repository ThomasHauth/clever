//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <memory>

#include <boost/algorithm/string.hpp>

#include "opencl.hpp"
#include "context.hpp"


namespace clever
{
/*

-- not in production yet --

class context_factory_base: public boost::noncopyable
{

};

class context_factory_partitioned
{

};

class context_factory : public context_factory_base
{
public:
	static std::shared_ptr < context > create ( std::string platformName, opencl::device_type dev_type )
		{

			std::shared_ptr pContext (
					new context( platformName, dev_type)
			);

			return pContext;
		}
};
*/
}

