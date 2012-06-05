//
//  Authors: Thomas Hauth, Danilo Piparo 2012
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//



#pragma once

#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>

namespace clever
{
class timing{

public:
	typedef std::vector < std::string > Properties;
	typedef std::vector < std::string > Results;

	Timing( std::string reportName ) :
		m_reportName ( reportName )
	{
		m_timing_start = omp_get_wtime() ;
		m_timing_result = -1;
	}

	Timing( std::string reportName, Properties const& p ) :
		m_reportName ( reportName ),
		m_properties( p )
	{
		m_timing_start = omp_get_wtime() ;
		m_timing_result = -1;
	}

	void TakeEndTime()
	{
		m_timing_result = omp_get_wtime() - m_timing_start;
	}

	void EndWithReport( bool storeResultFile = true)
	{
		// time already taken ?
		if ( m_timing_result < 0.0f )
			m_timing_result = omp_get_wtime() - m_timing_start;

		std::cout << std::endl << m_reportName <<  " took " << ( m_timing_result ) << " s";

		// store to file ?!?
		if ( storeResultFile )
		{
			std::ofstream fout;
			fout.open( m_reportName + "_timing.log", std::ios::app );

			// write properties
			for( auto const& s : m_properties )
			{
				fout << s << ",";
			}
			fout << m_timing_result;

			// write more results properties
			for( auto const& s : m_results )
			{
				fout << "," << s;
			}

			fout << std::endl;

			fout.close();
		}
	}

	static void ResetLog( std::string const& reportName )
	{
		std::ofstream fout;
		fout.open( reportName + "_timing.log", std::ios::trunc );
		fout.close();
	}

	double GetRuntimePerIteration( size_t iteration )  // in ns
	{
		return m_timing_result  / iteration * 1000.0f * 1000.0f;
	}

	void ReportPerItem( size_t itemcount )
	{
		std::cout << std::endl << m_reportName <<  " took " << ( m_timing_result/itemcount ) * 1000.0f << " ms per item. With "
				<< itemcount << " iteration(s)" ;

	}

	template < class T >
	void AddProperty( T const& p)
	{
		std::stringstream ss;
		ss << p;
		m_properties.push_back( ss.str() );
	}

	template < class T >
	void AddResult( T const& p)
	{
		std::stringstream ss;
		ss << p;
		m_results.push_back( ss.str() );
	}

	double GetRuntime()
	{
		return m_timing_result;
	}

private:
	double m_timing_start;
	double m_timing_result;
	std::string m_reportName;

	Properties m_properties;
	Results m_results;
};


}

