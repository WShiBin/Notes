#include <iostream>
using namespace std;

//final��ֹ��Ľ�һ���������麯���Ľ�һ����д

#if 0
class A1 final //����final��ָ��A1��������
{
    int a;
};

class A2: public A1 //err�� ���಻����������
{

};
#endif

//����
class B1
{
public:
    virtual void func() final {} //�������հ汾���麯������������д

};

//��������д������麯��
class B2: public B1
{
public:
    //virtual void func() {} //err, �����е��麯�������հ汾����������д
};



int main()
{



    return 0;
}
