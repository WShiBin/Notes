#include <iostream>
using namespace std;


int & func()
{
    static int tmp;

    return tmp;
}

int func02()
{
    return 10;
}

void test(int &tmp)
{
    cout << "��ֵ = " << tmp << endl;
}

void test(int && tmp)
{
    cout << "��ֵ = " << tmp << endl;
}

int main()
{
    int a = 10;
    test(a);    //��ֵ����

    test(111);  //��ֵ����

    return 0;
}

int main03()
{
    //��ֵ����
    int && a = 10;
    int && b = func02();

    int i = 10;
    int j = 20;
    int && c = i+j;

    int k = 10;
    //int && d = k; //err, ��һ����ֵ��ֵ��һ����ֵ����

    return 0;
}


int main02()
{
    //���ã���һ���ڴ���һ������������ʱ�����ʼ��
    //��ֵ����
    int a;
    int &b = a; //ok
    //int &c = 1; //err
    const int &d = a; //ok
    const int &e = 1; //ok
    const int &f = func();  //ok
    const int tmp = 10;
    const int &g = tmp;

    //const int & ��������

    return 0;
}


int main01()
{
    //��ֵ����ߣ���ֵ���ұ�
    //��ֵ����&�� ��ֵ����&
    int a = 10;

    //��ֵ�����������������صķ����ñ���

    return 0;
}
