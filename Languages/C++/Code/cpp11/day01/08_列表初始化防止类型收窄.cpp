#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int a = 1024;
	char b = { a }; //����	1	error C2397: �ӡ�int��ת������char����Ҫ����ת��	

	system("pause");
	return 0;
}
