#include<iostream>
#include<math.h>
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
int main(){
	float x,y;
	for(float i=1;i<101;i++){
		cout<<"i="<<i<<endl;
		x=1/sqrt(i);
		y=InvSqrt(i);
		cout<<"math.h:"<<x<<endl;
		cout<<"InvSqrt(float):"<<y<<endl;
	}
	return 0;
} 
