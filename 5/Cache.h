#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;
//一直报找不到标识符的错，因为没有提前声明
//1.提前声明，要是class在后面，但是前面用到了
//2.理清结构，需要的参数什么的先写
//3.程序要一部分一部分写，边写边检查，否则全部都不好检查
//4.有时候不要太着急
//5.程序也都是人写的，bug也正常
int random(int i) {
	//返回0~i之间的随机数
	srand((unsigned)time(NULL));
	return rand() % i;
}
struct item {
	long tag = 0;
	int in_use = 0;

};
class Cache {
public:
	Cache() {
		size = 0;
		associativity = 0;
		block_size = 0;
		cache_hit = 0;
		cache_miss = 0;
		total_lds = 0;
		cache_miss_rate = 0;
		time = 0;
	}
	~Cache() {}
	void create(int s, int a, int b, string n);
	void clear();
	int read_from_file(string name);
	void print_reslut();
private:
	int size;//Cache size,1KB~64KB(1024B~64*1024B)
	int associativity;//1,2,...,all
	int block_size;//32B,64B,128B,256B
	int content;//表的项数 size*1024/block_size 4~2048
	long cache_hit;
	long cache_miss;
	long total_lds;
	double cache_miss_rate;
	double time;
	string name;
	item *contents; //目录表

};

void Cache::create(int s, int a, int b, string n) {
	size = s;
	associativity = a;
	block_size = b;
	name = n;

	//新建一个目录
	item i;
	i.tag = 0;
	i.in_use = 0;
	int j = s * 1024 / b ;//16
	contents = new item[j];
	for (j=j-1; j >= 0; j--)
		contents[j] = i;


}
int Cache::read_from_file(string name) {

	long diff;
	unsigned long ea = 0;
	long index_temp, tag_temp, tmp;
	int i, random_temp;
	item temp;

	clock_t start, finish;
	start = clock();

	ifstream in;
	string filename;
	filename = name + ".txt";
	in.open(filename);

	while (in >> diff) {
		total_lds++;

		ea = ea + diff;
		tmp = ea / block_size;//除去块内位移
		index_temp = tmp % (size * 1024 / block_size / associativity);//计算当前索引
		tag_temp = tmp;// (size * 1024 / block_size / associativity);//当前tag,不除了
									   //查表
		for (i = index_temp * associativity ; i < (index_temp + 1)*associativity; i++) {
			//hit
			if (contents[i].tag == tag_temp && contents[i].in_use == 1) {
				cache_hit++;
				break;
			}
		}
		//miss
		if (i == (index_temp + 1)*associativity) {
			cache_miss++;
			temp.tag = tag_temp;
			temp.in_use = 1;
			for (i = index_temp * associativity; i < (index_temp + 1)*associativity; i++) {
				if (contents[i].in_use == 0) {
					contents[i] = temp;
					break;
				}
			}
			if (i == (index_temp + 1)*associativity) {
				random_temp = random(associativity);
				contents[index_temp*associativity + random_temp] = temp;
			}
		}
	}

	in.close();

	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	cache_miss_rate = double(cache_miss) / total_lds;
	return 0;

}
void Cache::print_reslut() {
	cout << "program_name:" << name << endl;
	cout << "cache_size:" << size << "KB" << endl;
	cout << "block_size:" << block_size << "B" << endl;
	cout << "associativity:" << associativity << endl;
	cout << "total_lds:" << total_lds << "次" << endl;
	cout << "cache_hits:" << cache_hit << "次" << endl;
	cout << "cache_misses:" << cache_miss << "次" << endl;
	cout << "cache_miss_rate:" << cache_miss_rate << endl;
	cout << "time:" << time << endl;

}
void Cache::clear() {
	size = 0;
	associativity = 0;
	block_size = 0;
	cache_hit = 0;
	cache_miss = 0;
	total_lds = 0;
	cache_miss_rate = 0;
	time = 0;
	delete[] contents;
}
