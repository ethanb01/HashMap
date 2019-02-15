#include "hash_map.h"
using namespace std;

int main(void)
{
	HashMap<int, int> map;
	map.insert(1, 2);
	cout << map.get(1) << endl; // 2
	map.print();
}