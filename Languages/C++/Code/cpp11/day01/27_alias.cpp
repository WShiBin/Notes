#include <iostream>
using namespace std;
#include <type_traits> //is_same<>����ͷ�ļ�


//ͨ��typedef��һ������������������½�����
typedef int int32;
using my_int=int;   //C++11��ʽ

int main()
{
    //is_same�ж�2�������Ƿ�һ�£�����Ƿ����棬���򷵻ؼ�
    cout << is_same<int32, my_int>::value << endl;

    return 0;
}
