#include <iostream>
#include <functional>
using namespace std;


int main()
{
    int a = 10;

    function<int(int)> f1 = [](int a){ return a+1; };
    cout << f1(9) << endl;

    function<int(int)> f2 = bind(
        [](int a){ return a+1; },
        std::placeholders::_1
    );
    cout << f2(9) << endl;

    auto f4 = [](int x, int y) -> int { return x + y; };
    cout << f4(1, 2) << endl;

    decltype (f4) tmp = f4;
    cout << tmp(2, 2) << endl;

    //����һ������ָ������
    typedef int (*PFUC)(int, int);
    PFUC p1 = f4; //lambda���ʽת��Ϊ����ָ�룬 ok�� lambda���ʽ���������ⲿ����
    cout << p1(10, 10) << endl;

    //decltype (f4) = p1; //����ָ��ת��Ϊlambda���ʽ�����ǲ����Ե�




    return 0;
}
