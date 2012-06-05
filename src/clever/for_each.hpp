//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef OPENCLAM_FOR_EACH_HPP_INCLUDED
#define OPENCLAM_FOR_EACH_HPP_INCLUDED

#include <memory>

namespace openclam
{
namespace detail
{
    template< class RandomAccessIterator, class Kernel >
    void for_each_dispatch( RandomAccessIterator& first, RandomAccessIterator& last, Kernel& k, std::random_access_iterator_tag )
    {
        k( &*first, std::distance( first, last ) );
    }

    template< class InputIterator, class Kernel >
    void for_each_dispatch( InputIterator& first, InputIterator& last, Kernel& k, std::input_iterator_tag )
    {
    	typedef typename InputIterator::value_type* itValPointer;
    	typedef typename InputIterator::value_type itVal;

        std::vector< itValPointer > data_references;
        std::vector< itVal > data;
        for( ; first != last; ++first )
        {
            data.push_back( *first );
            data_references.push_back( &*first );
        }
        k( &data[ 0 ], data.size() );
        for( unsigned int i = 0; i < data.size(); ++i )
            *data_references[ i ] = data[ i ];
    }
}

    template< class InputIterator, class Kernel >
    void for_each( InputIterator first, InputIterator last, Kernel& k )
    {
        typename std::iterator_traits< InputIterator >::iterator_category category;
        detail::for_each_dispatch( first, last, k, category );
    }
}

#endif // #ifndef OPENCLAM_CONTEXT_HPP_INCLUDED
