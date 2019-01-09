#include<fstream>
#include<iostream>
#include"Cache.h"
using namespace std;
int main() {
	Cache cache;
	//work(cin, cache);
	string t_order, s_order, b_order, a_order;
	string name;
	int s, b, a, i;
	while (1) {
		cout << ">csim ";
	cin >> t_order >> name >> s_order >> s >> b_order >> b >> a_order >> a;
	cache.create(s, a, b, name);
	cache.read_from_file(name);
	cache.print_reslut();
	cache.clear();
	}
	system("Pause");
	return 0;
}