#pragma once

#include "DataItems.h"
#include "CollectionView.h"

namespace clever
{

/*
 The Collection class serves as a container for a set of related data arrays, like x,y,z position in space
 The handling is very close to a class with x,y,z member variables but continious std::vectors are used
 in the backend to store the data. All read/write to the data by the user via the CollectionView class.

 Furthermore, the conntent of the Collection class can be easily transfered to OpenCL buffer without the need
 to modify or adapt the memory layout of the stored data.

 Please have a look at the test cases in clever_test_collection.h to get an idea of the usage modes.
 */
template<typename THead = NullData, typename ... TTail>
class Collection: public Collection<TTail ...>
{
public:

	typedef Collection<THead, TTail ...> own_type;
	typedef CollectionIterator<own_type> iterator_type;
	typedef CollectionView<own_type> view_type;
	typedef Collection<TTail ...> inherited;

	typedef THead key_type;
	typedef typename THead::data_type data_type;

	template <typename T>
	using internal_collection = std::vector< T >;

	typedef unsigned int index_type;

	// necessary to unhide the set/get methods of the base classes
	using inherited::setValue;
	using inherited::getValue;

	Collection()
	{
	}

	Collection(index_type initialSize) :
			inherited(initialSize)
	{
		m_data.resize(initialSize);
	}

	template<class TDataHead, class ... TDataTail>
	index_type addWithValue(TDataHead thisValue, TDataTail ... tail)
	{
		inherited::addWithValue(tail...);
		m_data.push_back(thisValue);
		return (m_data.size() - 1);
	}

	//template < class TItemHead
	index_type addEntry()
	{
		inherited::addEntry();
		m_data.push_back(data_type());
		return (m_data.size() - 1);
	}

	index_type size() const
	{
		return m_data.size();
	}

	//data_type getValue ( key_type ) const

	/*
	 template <key_type, data_type>
	 data_type getValue ( ) const
	 {
	 return m_data;
	 }
	 */
	data_type getValue(key_type, index_type i) const
	{
		return m_data[i];
	}

	iterator_type begin()
	{
		return iterator_type(*this, 0);
	}

	iterator_type end()
	{
		return iterator_type(*this, size());
	}

	// todo: no copy ...
	/*
	iterator_type getIterator()
	{
		return iterator_type(*this, index_type(0));
	}*/

	void setValue(key_type, index_type i, data_type const& v)
	{
		m_data[i] = v;
	}

	internal_collection<data_type> & getRawBuffer()
	{
		return m_data;
	}

	internal_collection<data_type> const& getRawBuffer() const
	{
		return m_data;
	}

private:
	key_type m_key;
	internal_collection<data_type> m_data;
};

// terminate the inheritance scheme
template<>
class Collection<> : private boost::noncopyable
{
public:
	typedef int index_type;
	Collection()
	{
	}

	Collection(index_type initialSize)
	{
	}

	void setValue();

	index_type addEntry()
	{
		return 0;
	}

	index_type addWithValue()
	{
		return 0;
	}

	/*template < class Key, class Data >
	 Data getValue() const;*/
	void getValue() const;
};
/*
template<class TCol>
typename TCol::iterator_type begin(TCol & col)
{
	return col.getIterator();
}*/
/* todo
template<class TCol>
typename TCol::iterator_type end(TCol & col)
{
	// todo::
	return col.getIterator();
}
*/

}
