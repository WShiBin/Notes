#include <iostream>
using namespace std;

class Test
{
public:
    //ί�й��죬һ��Ҫͨ����ʼ���б�ʽ
    Test():Test(1, 'a')
    {

    }

    Test(int x): Test(x, 'b')
    {

    }

    Test(char x): Test(11, x)
    {

    }

    int a;
    char b;

private:
    Test(int x, char y): a(x), b(y)
    {

    }



};


int main()
{
    //Test obj; //    Test():Test(1, 'a')
    Test obj('z');
    cout << obj.a << endl;
    cout << obj.b << endl;


    return 0;
}
