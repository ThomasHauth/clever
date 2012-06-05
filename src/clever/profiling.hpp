//
//  Copyright Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/noncopyable.hpp>
#include <stdexcept>

#include "iopencl.hpp"
#include "error.hpp"


namespace clever
{

class profiling : public boost::noncopyable
{
public:
	profiling( size_t run_count = 0 )
	{
		m_evts.reserve( run_count );
	}

	void add_run( cl_event const& e )
	{
		m_evts.push_back( e );
	}

	double get_mean_runtime( icontext const& context )
	{
		clever::profile_info pinfo;
		double m = 0.0f;
		for ( auto & e: m_evts )
		{
			context.report_profile( e, pinfo);
			m += pinfo.runtime();
		}
		return ( m / m_evts.size() );
	}

	double get_mean_timetostart( icontext const& context )
	{
		clever::profile_info pinfo;
		double m = 0.0f;
		for ( auto & e: m_evts )
		{
			context.report_profile( e, pinfo);
			m += pinfo.timetostart();
		}
		return ( m / m_evts.size() );
	}


private:
	std::vector< cl_event> m_evts;

			clever::profile_info pinfo;






};

}
