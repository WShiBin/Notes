#include <iostream>
using namespace std;

//�Զ���������������Ҫ�� operator"" xxx
double operator"" _mm(long double x)
{
    return x/1000;
}

double operator"" _m(long double x)
{
    return x;
}

double operator"" _km(long double x)
{
    return x*1000;
}

int main()
{
    cout << operator"" _mm(1.0) << endl; //��ͳ�ĵ��÷�ʽ�����Ƽ�
    cout << 1.0_mm << endl;
    cout << 1.0_m << endl;
    cout << 1.0_km << endl;

    return 0;
}
