#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void func(int a)
{
	cout << __LINE__ << endl;
}

void func(int* p)
{
	cout << __LINE__ << endl;
}

int main(void)
{
	int * p = NULL;
	int *p2 = 0;

	func(nullptr);

	//nullptr, ֻ�ܸ�ָ�븳ֵ
	p = NULL;
	p2 = nullptr;
	if (p == p2)
	{
		cout << "equal\n";
	}

	//���ܸ�һ����ͨ���ͱ�����ֵ��nullptr
	//�޷��ӡ�nullptr��ת��Ϊ��int��
	int tmp = nullptr; //err


	system("pause");
	return 0;
}
