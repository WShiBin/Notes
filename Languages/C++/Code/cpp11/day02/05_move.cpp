#include <iostream>
using namespace std;

int main()
{
    int a = 10; //aΪ��ֵ
    //int && b = a; //err, ��ֵ���ܰ󶨵���ֵ����

    int && c = std::move(a);    //std::move��һ����ֵת��Ϊ��ֵ
    cout << "c = " << c << endl;

    return 0;
}

