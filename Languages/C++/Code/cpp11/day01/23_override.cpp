#include <iostream>
using namespace std;

class A1
{
public:
    //���ǵ�һ���麯����û����д��������override����
    virtual int func(int a)
    {

    }
};

class A2:public A1
{
public:
    //����д�麯���ط�������override, Ҫ����д���麯���ͻ���һģһ��
    virtual int func(int b) override
    {

    }
};


int main()
{



    return 0;
}
