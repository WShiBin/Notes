#include <iostream>
using namespace std;

class X
{
public:
    X() =default; //�ñ������ṩһ��Ĭ�ϵĹ��캯����Ч�ʱ��û�д�ĸ�

    X(int i)
    {//д�˴��εĹ��캯���������������ṩ�޲εĹ��캯��
        a = i;
    }

    int a;
};

//defaultֻ����������Ĭ���ṩ�Ĺ���Ա�������޲ι��죬�������죬��ֵ��������أ�����������
#if 0
class X2
{
public:
    int f() = default;  //err
    X2(int a) = default;//err
};
#endif

class X3
{
public:
    X3(); //����
    X3(int i)
    {//д�˴��εĹ��캯���������������ṩ�޲εĹ��캯��
        a = i;
    }

    int a;
};

X3::X3() =default; //default���Է�������ⲿ

int main()
{
    X obj;


    return 0;
}
