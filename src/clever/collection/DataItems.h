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
class TypeToCLType<unsigned int>
{
public:
	typedef cl_uint cl_type;
	static std::string str()
	{
		return "uint";
	}
};

struct NullData
{
};

struct FloatItem
{
	typedef float data_type;
};

struct UIntItem
{
	typedef unsigned int data_type;
};

}
