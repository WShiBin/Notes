#include <iostream>
#include <functional> //std::bind
using namespace std;

void func(int x, int y)
{
    cout << x << " " << y << endl;
}

int main()
{
    bind(func, 11, 22)(); //���11 22

    //std::placeholders::_1, ��������ʱ������һ�������滻
    //std::placeholders::_2, ��������ʱ�����ڶ��������滻
    //���11 22
    bind(func, std::placeholders::_1, std::placeholders::_2)(11, 22);

    using namespace std::placeholders;
    bind(func, 11, _1)(22, 33, 44); //��� 11 22�� �����33�� 44û������

    bind(func, _2, _1)(11, 22); //��� 22 11

    //bind(func, _2, 22)(11); //err, û�е�2������
    bind(func, _2, 22)(11, 0);    //0 22
    bind(func, _3, 22)(11, 1, 3); //3 22



    return 0;
}

