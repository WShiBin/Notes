#include <iostream>
using namespace std;

class X
{
public:
    X() {} //��ͨ�޲�
    X(const X &)=delete; //��������, ��"=delete"���Σ��˺���������
    X & operator=(const X &)=delete; //��ֵ��������غ���, ��"=delete"���Σ��˺���������

    X(int) =delete; //��"=delete"���Σ��˺���������

    void *operator new(size_t) =delete;
    void *operator new[](size_t) =delete;
};


int main()
{
    X obj1; //��ͨ�޲�
    //X obj2 = obj1; //err, �������챻����

    //obj2 = obj1; //err, ��ֵ��������غ���������

    //X obj3(10); //err,

    //X *p = new X; //err
    //X *p = new X[10]; //err


    return 0;
}
