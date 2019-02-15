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
	std::array<std::vector<std::pair<K,V>>, MAX_SIZE> data;

};


template<typename K, typename V>
void HashMap<K, V>::insert(K key, V value)
{
	// int key_index = hash(key);
	int key_index = 0;
	this->data[key_index].push_back({ key, value });
}

template<typename K, typename V>
bool HashMap<K, V>::is_empty()
{
	return false;
}

template<typename K, typename V>
void HashMap<K, V>::print()
{
	/*for (auto vec : this->data)
	{
		lo
	}*/
}

template<typename K, typename V>
V HashMap<K, V>::get(K key)
{
	// int key_index = hash(key);
	// search for key in vector: this->data[key_index]
}
