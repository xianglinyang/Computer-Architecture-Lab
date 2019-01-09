#include<iostream>
#include<string>
using namespace std;
union number{//定义一个联合类number
	number(){}
	float float_type;
	int int_type;
};
bool number_type(string b) {//判断数据类型
	int i,j;
	i = b.length();
	for (j = 0; j < i; j++) {
		if (b[j] == '.') return true;//true表示类型为浮点数
	}
	return false;//false为16进制
}
int char_to_int(char x) {//把对应的十六进制字符传换成int类型
	if (x >= '0'&&x <= '9') return x - '0';
	else if (x >= 'a'&&x <= 'f') return x - 'a' + 10;
	else if (x >= 'A'&&x <= 'F') return x - 'A' + 10;
}
float string_to_float(string b) {//将输入的字符串转化为浮点数
	float result = 0;
	int i = 0;
	while (b[i] != '.') {//以小数点为分界点
		result = result * 10 + b[i] - '0';
		i += 1;
	}
	i = i + 1;
	double j = 0.1;
	while (b[i]) {
		result += (b[i] - '0')*j;
		j = j * 0.1;
		i = i + 1;
	}
	return result;
}
int string_to_int(string b) {//把十六进制字符串转为int类型
	int i, j;
	int result = 0;
	i = b.length();
	for (j = 0; j < i; j++) {
		result = result * 16 + char_to_int(b[j]);
	}
	return result;
}
int main() {
	union number data_number;
	string data;
	while (1) {//循环输入
		printf("请输入浮点数或十六进制数：");
		cin >> data;
		//判断输入字符是十六进制还是浮点数
		if (number_type(data)) {
			data_number.float_type = string_to_float(data);
			//cout << data_number.int_type << endl;
			printf("对应的十六进制数为：%X\n", data_number.int_type);//十六进制输出
		}
		else {
			data_number.int_type = string_to_int(data);
			printf("对应的浮点数为：%f\n", data_number.float_type);//浮点数输出
		}
	}
	return 0;

}
/*
1由于是32位的浮点数，所以用float，一开始用double，结果是错的
2 float x=0.1;是不符合规范的，在VS中，0.1默认是double类型
3 R进制转成十进制，十进制转R进制；小数点后的二进制转成十进制
4 %d %f %lf %x %X %s
*/

