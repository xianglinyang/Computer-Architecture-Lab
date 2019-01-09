#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;
//һֱ���Ҳ�����ʶ���Ĵ���Ϊû����ǰ����
//1.��ǰ������Ҫ��class�ں��棬����ǰ���õ���
//2.����ṹ����Ҫ�Ĳ���ʲô����д
//3.����Ҫһ����һ����д����д�߼�飬����ȫ�������ü��
//4.��ʱ��Ҫ̫�ż�
//5.����Ҳ������д�ģ�bugҲ����
int random(int i) {
	//����0~i֮��������
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
	int content;//������� size*1024/block_size 4~2048
	long cache_hit;
	long cache_miss;
	long total_lds;
	double cache_miss_rate;
	double time;
	string name;
	item *contents; //Ŀ¼��

};

void Cache::create(int s, int a, int b, string n) {
	size = s;
	associativity = a;
	block_size = b;
	name = n;

	//�½�һ��Ŀ¼
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
		tmp = ea / block_size;//��ȥ����λ��
		index_temp = tmp % (size * 1024 / block_size / associativity);//���㵱ǰ����
		tag_temp = tmp;// (size * 1024 / block_size / associativity);//��ǰtag,������
									   //���
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
	cout << "total_lds:" << total_lds << "��" << endl;
	cout << "cache_hits:" << cache_hit << "��" << endl;
	cout << "cache_misses:" << cache_miss << "��" << endl;
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
