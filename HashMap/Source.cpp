#include <iostream>
#include <string>
#include "hash_map.h"


int main(void)
{
	HashMap<std::string, int> map;
	map.insert("one", 1);
	//cout << map.get(1) << endl; // 2
	map.print();
}