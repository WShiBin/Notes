#include <iostream>
using namespace std;

template<int i> class X {};
template<class T> class Y {};

int main()
{
    Y<X<10>> obj1; //C++11֮ǰ��2���Ҽ�����֮������пո�


    return 0;
}
