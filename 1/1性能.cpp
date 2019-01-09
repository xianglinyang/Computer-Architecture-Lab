#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;
float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x*(1.5f - xhalf*x*x);
	return x;
}
int main() {
	float x, y;
	clock_t sqrt_start, sqrt_finish, InvSqrt_start, InvSqrt_finish;
	double sqrt_totaltime, InvSqrt_totaltime;
	sqrt_start = clock();
	for (float i = 1; i < 100; i++) {//ÊäÈë1~100
		x = 1 / sqrt(i);
		cout << x;
	}
	sqrt_finish = clock();
	sqrt_totaltime = (double)(sqrt_finish - sqrt_start) / CLOCKS_PER_SEC;
	InvSqrt_start = clock();
	for (float i = 1; i < 100; i++) {//ÊäÈë1~100
		y = InvSqrt(i);
		cout << y;
	}
	InvSqrt_finish = clock();
	InvSqrt_totaltime = (double)(InvSqrt_finish - InvSqrt_start) / CLOCKS_PER_SEC;
	cout << endl<< "sqrt_totaltime=" << sqrt_totaltime << endl;
	cout << "InvSqrt_totaltime=" << InvSqrt_totaltime << endl;
	return 0;
}
