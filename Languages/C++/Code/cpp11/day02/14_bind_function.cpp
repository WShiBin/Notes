#include <iostream>
#include <functional> //std::bind
using namespace std;
using namespace std::placeholders;

class Test
{
public:
    void func(int x, int y)
    {//��Ա����
        cout << x << " " << y << endl;
    }

    int a; //��Ա����
};

int main()
{
    Test obj; //��������

    //�󶨳�Ա����
    function<void(int, int)> f1 = bind(&Test::func, &obj, _1, _2);
    f1(11, 22); //obj.func(11, 22)

    //�󶨳�Ա����
    function<int &()> f2 = bind(&Test::a, &obj);
    f2() = 111; //obj.a = 111;
    cout << "obj.a = " << obj.a << endl;

    return 0;
}


