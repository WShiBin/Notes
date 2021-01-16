#include <iostream>
using namespace std;

#if 0
//�ݹ���ֹ����1
void debug()
{
    cout << "empty" << endl;
}
#endif

//�ݹ���ֹ����2
template <class T>
void debug(T tmp)
{
    cout << "tmp = " << tmp << endl;
}

//�ɱ������ģ�庯��
//������չ������
template <class T1, class... T2>
void debug(T1 first, T2... last)
{
    cout << first << endl;
    //�ݹ���ú�������
    debug(last...);
}

int main()
{
    debug(1, 2, 3, 4);
    /*
    �����ݹ���ù��̣�
    debug(1, 2, 3, 4);
    debug(2, 3, 4);
    debug(3, 4);
    debug(4);
     */

    return 0;
}

int main01()
{
    debug(1, 2, 3, 4);
    /*
    �����ݹ���ù��̣�
    debug(1, 2, 3, 4);
    debug(2, 3, 4);
    debug(3, 4);
    debug(4);
    debug();
     */

    debug(1, "mike", 3.11, 'a');

    return 0;
}
