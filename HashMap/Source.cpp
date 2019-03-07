#include <iostream>
#include <string>
#include "hash_map.h"


int main(void)
{
	HashMap<std::string, int> map;
	map.insert("one", 1);
	map.insert("two", 2);
	map.insert("three", 3);
	map.insert("four", 4);

	std::cout << map.get("one") << std::endl; // 2
	map.print();
}