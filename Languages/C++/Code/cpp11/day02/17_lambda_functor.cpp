#include <iostream>
using namespace std;

//�º���������operator()
class MyFunctor
{
public:
    MyFunctor(int i): r(i) {} //���캯��

    //�º���������operator()
    int operator() (int tmp)
    {
        return tmp+r;
    }

private:
    int r;
};

int main()
{
    int tmp = 10;

    //�º����ĵ���
    MyFunctor obj(tmp); //���ù��캯��

    //���÷º���
    cout << "result1 = " << obj(1) << endl;

    //�º����Ǳ�����ʵ��lambda��һ�ַ�ʽ
    //lambda���ʽ
    auto f = [&](int t)
        {
            return tmp+t;
        };
    cout << "result2 = " << f(1) << endl;


    return 0;
}
