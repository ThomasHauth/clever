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

struct NullData
{
};

struct FloatItem
{
	typedef float data_type;
};

}
