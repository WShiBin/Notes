#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void func01()
{
	throw 1;
}

//������������׳��κ��쳣
void func02() throw()
{

}

//������������׳��κ��쳣
//noexcept vs 2013��֧�֣�����qt�²���
void func03() noexcept
{

}

int main(void)
{

	system("pause");
	return 0;
}
