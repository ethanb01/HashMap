#pragma once
#include <string>
#include <array>
#include <vector>
#include <iostream>
const int MAX_SIZE = 128;

template <typename K, typename V>
class HashMap
{
public:
	HashMap()
	{
		size_map = 0;
		//count = 0;
		log("constructor");
	}
	~HashMap()
	{
		log("destructor");
	}

	void insert(K key, V value);
	bool is_empty();
	void print();
	V get(K key);



// implement best hashing

/*
	HashMap(const HashMap& other)
		: m_size(other.m_size))
	{
	log("copy constructor");
	for (size_t i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];
	}

	HashMap& operator=(const Intvec& other)
	{
		log("copy assignment operator");
		Intvec tmp(other);
		std::swap(m_size, tmp.m_size);
		std::swap(m_data, tmp.m_data);
		return *this;
	}*/
private:
	void log(const char* msg)
	{
		std::cout << "[" << this << "] " << msg << std::endl;
	}
	int size_map;
	std::array<std::vector<std::pair<K,V>>, MAX_SIZE> data;
	//std::array<std::vector<std::tuple<K, V,int>>, MAX_SIZE> data;
};

std::string to_string(const std::string& val)
{
	return val;
}

template <typename K>
int hash_function(K key)
{
	std::string keyToStr = to_string(key);
	int number_hash = 0;
	for (int i = 0; i < keyToStr.length(); i++) 
	{
		number_hash = number_hash + (int)keyToStr[i];
	}
	int index = number_hash % MAX_SIZE;
	return index;
}

template<typename K, typename V>
void HashMap<K, V>::insert(K key, V value)
{
	int hop = 0;
	int key_index = hash_function(key);
	//int copy_key_index = key_index;
	this->data[key_index].push_back({ key, value });
	/*while (this->data[copy_key_index].size() > 0)
	{
		copy_key_index++;;
		hop++
		if (copy_key_index == 127)
			copy_key_index = 0;
	}
	this->data[copy_key_index].push_back({ key, value,hop });*/
	

	this->size_map++;
}

template<typename K, typename V>
bool HashMap<K, V>::is_empty()
{
	return size_map == 0;
}


template<typename K, typename V>
void HashMap<K, V>::print()
{
	std::string to_print = "{";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			to_print += "\'";
			to_print += to_string(data[i][j].first);
			to_print += "\'";
			to_print += ": ";
			to_print += std::to_string((int)(data[i][j].second));
			to_print += ", ";
		}
	}
	to_print = to_print.substr(0, to_print.size() - 2);
	to_print += "}";
	std::cout << to_print << std::endl;
}



template<typename K, typename V>
V HashMap<K, V>::get(K key)
{
	int key_index = hash_function(key);
	// search for key in vector: this->data[key_index]
	//V value;
	for (int i = 0; i < data[key_index].size(); i++)
		if (data[key_index][i].first == key)
			return data[key_index][i].second;
	return NULL;
}
