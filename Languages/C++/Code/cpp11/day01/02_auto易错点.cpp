#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//2��vs2013��֧�֣������β���auto����, qtȷʵ����
void func(auto a)
{

}

//3��auto����������Ϊ�Զ������͵ĳ�Ա����
struct  Test
{
	int a;
	auto b = 10;
};

int main(void)
{
	//1���������ʱ�������ʼ��
	auto a;
	a = 10;

	auto b[3] = { 1, 2, 3 }; //4��������auto����

	//5��ģ��ʵ�������Ͳ�����auto����
	vector<int> a;
	vector<auto> b = { 1 };


	system("pause");
	return 0;
}
