#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename K, typename V>
class HashMap
{
public:
	HashMap()
	{
		log("constructor");
	}

	~HashMap()
	{
		log("destructor");
	}

	HashMap(const HashMap& other)
		: m_size(other.m_size))
	{
		log("copy constructor");
		for (size_t i = 0; i < m_size; ++i)
			m_data[i] = other.m_data[i];
	}

	Intvec& operator=(const Intvec& other)
	{
		log("copy assignment operator");
		Intvec tmp(other);
		std::swap(m_size, tmp.m_size);
		std::swap(m_data, tmp.m_data);
		return *this;
	}
private:
	void log(const char* msg)
	{
		cout << "[" << this << "] " << msg << "\n";
	}

	K key;
	V value;

};

int main(int argc, char** argv)
{
	Intvec v1(10); // [1,5,2,3,6]
	Intvec v2;
	v2 = v1;
	//Intvec sorted = sort(v1);
}

// sort the vector
