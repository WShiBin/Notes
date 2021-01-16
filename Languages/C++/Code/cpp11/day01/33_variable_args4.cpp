#include <iostream>
#include <typeinfo>
using namespace std;

//�̳з�ʽչ���ɱ����ģ����
//1���ɱ����ģ������
//2���ݹ�̳�ģ����
//3���߽�����

//1���ɱ����ģ������
template<class ...T> class Car {};

//2���ݹ�̳�ģ����
template<class Head, class ... Tail>
class Car<Head, Tail...>:public Car<Tail...>
{//�ݹ�̳б���
public:
    Car()
    {
        cout << "type = " << typeid(Head).name() << endl;
    }
};

//3���߽�����
template<> class Car<> {};


int main()
{
    Car<int, char *, double> bmw;


    return 0;
}
