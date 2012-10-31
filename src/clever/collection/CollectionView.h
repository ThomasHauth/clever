#pragma once

namespace clever
{

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

	// add entry
	CollectionView(TCollection & collection) :
			m_col(collection)
	{
		m_index = m_col.addEntry();
	}

	/*	typedef typename TCollection::key_type key_type;
	 typedef typename TCollection::data_type data_type;
	 */
	template<class TDataClass>
	typename TDataClass::data_type getValue() const
	{
		return m_col.getValue(TDataClass(), m_index);
	}

	template<class TDataClass>
	void setValue(typename TDataClass::data_type const& v)
	{
		m_col.setValue(TDataClass(), m_index, v);
	}

	// iterator implementation, not done yet
	// pre op
	CollectionView& operator++()
	{
		m_index++;
		return *this;
	}

	// post op
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

}
