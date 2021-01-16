#include <iostream>
using namespace std;

//1���䳤ģ������
//2���䳤ģ���ඨ��
//3���߽�����

//1���䳤ģ������
template<int ... last>
class Test
{

};

//2���䳤ģ���ඨ��
template<int first, int ... last>
class Test<first, last...>
{
public:
    static const int val = first * Test<last...>::val;
};

//3���߽�����
template<>
class Test<>
{
public:
    static const int val = 1;
};


int main()
{
    cout << Test<2, 3, 4, 5>::val << endl;


    return 0;
}
