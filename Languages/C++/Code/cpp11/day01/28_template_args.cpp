#include <iostream>
using namespace std;

//1����ͨ������Ĭ�ϲ���
void func(int a = 3) {}

//2����ģ��֧��Ĭ�ϵ�ģ�����
template<class T, class T2=int> //��ģ���ģ����������Ǵ�������
class A
{

};

//3��C++11��֧�֣�����ģ���Ĭ�ϵ�ģ�����
//  ����ģ���ģ����������Ǵ�������Ҳ�����Ǵ�������
template<class T=int, class T2> void func2(T a, T2 b){}


int main()
{



    return 0;
}
