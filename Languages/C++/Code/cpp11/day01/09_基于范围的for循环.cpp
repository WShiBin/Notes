#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void func(int a[]) //�β��е����鲻�����飬��ָ��������޷�ȷ��Ԫ�ظ���
{
	//���ڷ�Χ��for, �����ΧҪȷ���󣬲���ʹ��
	for (int & tmp: a) //err
	{
		cout << tmp << endl;
	}
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(*a); //Ԫ�ظ���

	for (int i = 0; i < n; ++i)
	{
		int tmp = a[i];
		cout << tmp << ", ";
	}
	cout << endl;

	for (int tmp : a)
	{
		cout << tmp << ", ";
	}
	cout << endl;


	for (int i = 0; i < n; ++i)
	{
		int &tmp = a[i];
		tmp = 2 * tmp;
		cout << tmp << ", ";
	}
	cout << endl;

	for (int &tmp : a)
	{
		tmp = 2 * tmp;
		cout << tmp << ", ";
	}
	cout << endl;

	func(a); //���ú���



	system("pause");
	return 0;
}
