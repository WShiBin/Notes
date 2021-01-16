#include <iostream>
using namespace std;

template<class T> void func(const T &)
{
    cout << "const T &" << endl;
}

template<class T> void func(T &)
{
    cout << "T &" << endl;
}

template<class T> void func(T &&)
{
    cout << "T &&" << endl;
}


template<class T> void forward_val(T &&tmp) //����Ϊ��ֵ����
{
    //std::forward�����������ֵ����ֵ����
    func( std::forward<T>(tmp) ); //����
}

int main()
{
    int a = 0;
    const int &b = 1;

    //��Ҫ��forward_val()����2���汾�� const T &�� T &
    forward_val(a); //"T &"
    forward_val(b);//const T &
    forward_val(111);//T &&


    return 0;
}


