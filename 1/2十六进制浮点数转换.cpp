#include<iostream>
#include<string>
using namespace std;
union number{//����һ��������number
	number(){}
	float float_type;
	int int_type;
};
bool number_type(string b) {//�ж���������
	int i,j;
	i = b.length();
	for (j = 0; j < i; j++) {
		if (b[j] == '.') return true;//true��ʾ����Ϊ������
	}
	return false;//falseΪ16����
}
int char_to_int(char x) {//�Ѷ�Ӧ��ʮ�������ַ�������int����
	if (x >= '0'&&x <= '9') return x - '0';
	else if (x >= 'a'&&x <= 'f') return x - 'a' + 10;
	else if (x >= 'A'&&x <= 'F') return x - 'A' + 10;
}
float string_to_float(string b) {//��������ַ���ת��Ϊ������
	float result = 0;
	int i = 0;
	while (b[i] != '.') {//��С����Ϊ�ֽ��
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
int string_to_int(string b) {//��ʮ�������ַ���תΪint����
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
	while (1) {//ѭ������
		printf("�����븡������ʮ����������");
		cin >> data;
		//�ж������ַ���ʮ�����ƻ��Ǹ�����
		if (number_type(data)) {
			data_number.float_type = string_to_float(data);
			//cout << data_number.int_type << endl;
			printf("��Ӧ��ʮ��������Ϊ��%X\n", data_number.int_type);//ʮ���������
		}
		else {
			data_number.int_type = string_to_int(data);
			printf("��Ӧ�ĸ�����Ϊ��%f\n", data_number.float_type);//���������
		}
	}
	return 0;

}
/*
1������32λ�ĸ�������������float��һ��ʼ��double������Ǵ��
2 float x=0.1;�ǲ����Ϲ淶�ģ���VS�У�0.1Ĭ����double����
3 R����ת��ʮ���ƣ�ʮ����תR���ƣ�С�����Ķ�����ת��ʮ����
4 %d %f %lf %x %X %s
*/

