#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;


int main(void)
{
	//static_assert(�������ʽ����, "��ʾ���ַ���")
	static_assert(sizeof(void *) == 4, "64λϵͳ��֧��");
	cout << "hello C++\n";

	system("pause");
	return 0;
}


int main01(void)
{
	bool flag = false;

	//����ʱ������������������Ϊ�棬����ִ�У��������Ϊ�٣��жϣ���ʾ����
	//assert(flag == true); //����Ϊ�٣� �ж�
	assert(flag == false);//����Ϊ�棬����ִ��

	cout << "hello C++\n";


	system("pause");
	return 0;
}
