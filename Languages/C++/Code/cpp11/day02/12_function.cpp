#include <iostream>
#include <functional> //std::function
using namespace std;

//1����ͨ����
void func()
{
    cout << __func__ << endl;
}

//2�����о�̬����
class Test
{
public:
    static int test_func(int a)
    {
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

//3�����еķº���
class MyFunctor
{
public:
    int operator()(int a)
    {
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

int main()
{
    //1������ͨ����
    function<void(void)> f1 = func;
    f1(); //�ȼ��� func()

    //2�������еľ�̬����
    function<int(int)> f2 = Test::test_func;
    cout << f2(10) << endl; // Test::test_func(10)

    //3�������еķº������󶨶���, �º�������obj()
    MyFunctor obj;
    function<int(int)> f3 = obj;
    cout << f3(22) << endl;


    return 0;
}

