#include <iostream>
using namespace std;

//�ɱ������ģ�庯��
template<class ... T> //T��ģ�������
void func(T... args)//args�к���������
{

}

int main()
{
    func<int>(10);
    func<int, int>(10, 20);
    func<char, int>(10, 'a');
    func<char, char *, int>('a', "abc", 250);

    return 0;
}
