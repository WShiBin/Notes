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
    MyFunctor obj(10); //���ù��캯��

    //���÷º���
    cout << "result = " << obj(1) << endl;

    return 0;
}

