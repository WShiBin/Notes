#include <iostream>
using namespace std;

int tmp = 1;

class Test
{
public:
    int i = 0;

    void func()
    {
        int a = 10;
        //err, []Ϊ�գ�û�в����κα���
        //auto f1 = [](){ cout << i << endl; };

        auto f1 = [=]() {
            cout << i << endl;
            cout << tmp << endl;
        };
        auto f2 = [&]() { cout << i << endl; };

        //ֻ�ǲ������Ա������ȫ�ֱ����� ���ܲ���ֲ�����
        auto f3 = [this]() {
            cout << i << endl;
            cout << tmp << endl;
            //cout << a << endl; //err
        };
    }
};

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    auto f1 = []() {};
    //a, b��ֵ���ݷ�ʽ
    auto f2 = [a, b]() { cout << a << ", " << b << endl; };
    auto f3 = [a, b](int x, int y) {
        cout << a << ", " << b << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    };
    //f3(10, 20);

    //��ֵ���ݷ�ʽ����lambda���ʽ
    auto f4 = [=] { cout << a << ", " << b << endl; };

    //�����÷�ʽ�����ⲿ�ı���
    auto f5 = [&] { cout << a << ", " << b << endl; };

    //a��ֵ���ݣ� ���������÷�ʽ����
    auto f6 = [&, a] { cout << a << ", " << b << endl; };

    //a�����ô��ݣ�����ֵ����
    auto f7 = [=, &a] { cout << a << ", " << b << endl; };

    //Ĭ������£�lambda��������const���κ����壬 ֵ�����޷��޸ģ� ���޸ļ�mutable
    auto f8 = [=]() mutable {
        a++;
        cout << tmp << endl;
    };

    return 0;
}
