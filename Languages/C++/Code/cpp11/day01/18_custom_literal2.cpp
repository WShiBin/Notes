#include <iostream>
using namespace std;

/*
    char const *
    unsigned long long
    long double
    char const *, size_t
    wchar_t const *, size_t
    char16_t const *, size_t
    char32_t const *, size_t

*/

//�Զ���������������Ҫ�� operator"" xxx
//ֻ�����һ���������Σ��ڶ��������Զ����㣬���һ�������ĳ��ȣ����ڶ���������ֵ
size_t operator"" _len(char const *str, size_t n)
{
    return  n;
}

char const * operator"" _str(char const *buf, size_t n)
{
    return  buf;
}

char const * operator"" _test(char const *tmp)
{
    return tmp;
}

int main()
{
    cout << "abc"_len << endl;
    cout << "abc"_str << endl;
    cout << 123_test << endl;


    return 0;
}

