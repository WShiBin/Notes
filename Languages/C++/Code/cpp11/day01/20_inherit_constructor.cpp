#include <iostream>
using namespace std;

//����
class A
{
public:
    A(int x, int y)
    {
        a = x;
        b = y;
    }

protected:
    int a;
    int b;
};

//������
class B:public A
{
public:
#if 0
    //ͨ�������б�����๹�캯������
    B(int x, int y): A(x, y)
    {

    }
#endif
    //�̳й���
    using A::A;

    void display()
    {
        cout << "a = " << a << ", b = " << b << endl;
    }

    //û�������µĳ�Ա����
    int tmp;
};

int main()
{
    //���������
    B obj(10, 20);
    obj.display();



    return 0;
}
