#pragma once

#include <cassert>
#include <boost/iterator/iterator_facade.hpp>


namespace clever
{

/*
	The CollectionView class provides an iterator to go over the elements contained in
	a Colletion class. This view allows to access the content in a struct-like fashion
	without caring about the underlying arrays.
*/
template<class TCollection>
class CollectionView
{
public:
	typedef typename TCollection::index_type index_type;

	// point to somewhere
	CollectionView(TCollection & collection, index_type i) :
			m_col(collection), m_index(i)
	{

	}

	// point to somewhere (readonly)
	CollectionView(const TCollection & collection, index_type i) :
		m_col(const_cast<TCollection &>(collection)), m_index(i)
	{

	}

	// add entry for this View.
	// TODO: is this a good interface
	CollectionView(TCollection & collection) :
			m_col(collection)
	{
		m_index = m_col.addEntry();
	}

	// return a value of the collection, identified by the respective
	// DataType class
	template<class TDataClass>
	typename TDataClass::data_type getValue() const
	{
		return m_col.getValue(TDataClass(), m_index);
	}

	// set a value of the collection, identified by the respective
	// DataType class
	template<class TDataClass>
	void setValue(typename TDataClass::data_type const& v)
	{
		m_col.setValue(TDataClass(), m_index, v);
	}

	bool operator==(const CollectionView &other) const
	{
		return (other.m_index == this->m_index);
	}

	bool operator!=(const CollectionView &other) const
	{
		return !(*this == other);
	}

	// TODO: iterator implementation, not done yet
	// pre op
	CollectionView& operator++()
	{
		m_index++;
		return *this;
	}

	// TODO: post op
	CollectionView operator++(int)
	{
		CollectionView tmp(*this); //Kopier-Konstruktor
		++(*this); //Inkrement
		return tmp; //alten Wert zurueckgeben
	}

protected:
	TCollection & m_col;
	index_type m_index;
};

template<class TCollection>
class CollectionIterator: public boost::iterator_facade<
                CollectionIterator<TCollection>, typename TCollection::view_type,
                boost::forward_traversal_tag>
{
public:

        typedef typename TCollection::view_type view_type;

        CollectionIterator(TCollection & collection, size_t initialPosition = 0) :
                        m_view( collection, initialPosition)
        {
        }


        explicit CollectionIterator( view_type * view)
        {
                // not implemented
                assert ( false );
        }

private:
        friend class boost::iterator_core_access;

        void increment()
        {
                m_view++;
        }

        bool equal(CollectionIterator const& other) const
        {
                // when using pointers
                //return this->m_view->operator==(*other.m_view);
                return this->m_view == other.m_view;
        }

        view_type& dereference() const
        {
                return m_view;
        }

        mutable view_type   m_view;
};


}
