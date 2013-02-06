#pragma once

namespace clever
{

template<class TType>
class TypeToCLType
{
public:
	static std::string str();
};

template<>
class TypeToCLType<float>
{
public:
	typedef cl_float cl_type;
	static std::string str()
	{
		return "float";
	}
};

template<>
class TypeToCLType<double>
{
public:
	typedef cl_double cl_type;
	static std::string str()
	{
		return "double";
	}
};

template<>
class TypeToCLType<unsigned int>
{
public:
	typedef cl_uint cl_type;
	static std::string str()
	{
		return "uint";
	}
};

template<>
class TypeToCLType<unsigned char>
{
public:
	typedef cl_uchar cl_type;
	static std::string str()
	{
		return "uchar";
	}
};

typedef unsigned char uchar;
typedef unsigned short ushort;

// only used as a implementation detail.
// TODO: hide better
struct NullData
{
};

struct FloatItem
{
	typedef float data_type;
};

struct DoubleItem
{
	typedef double data_type;
};

struct UIntItem
{
	typedef unsigned int data_type;
};

struct UCharDictionaryItem
{
	typedef uchar data_type;
};

}
