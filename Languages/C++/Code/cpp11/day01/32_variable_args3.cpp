#include <iostream>
using namespace std;

template<class T>
void print(T tmp)
{
    cout << tmp << endl;
}

//�ɱ������ģ�庯��
template<class ... T>
void expand(T ... args)
{
    //���������
    //��ʼ���б�
    int a[] = {(print(args), 0)...};
}

int main()
{
    expand(1, 2, 3, 4);


    return 0;
}
