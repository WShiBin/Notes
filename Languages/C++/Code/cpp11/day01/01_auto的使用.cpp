#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

double foo()
{
	return 1.1;
}

struct Test
{
	int a;
};

void func(vector<int> &tmp)
{
	for (auto i = tmp.begin(); i != tmp.end(); ++i)
	{
		//����
	}
}

int main(void)
{
	int a = 1;

	auto b = 1; //b�����;���int

	auto c = foo(); //c�����;���double

	Test str = {0};
	auto d = str; //d�����;���struct Test

	printf("\n");
	system("pause");
	return 0;
}
