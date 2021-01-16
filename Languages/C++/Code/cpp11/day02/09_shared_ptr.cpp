#include <iostream>
#include <memory> //����ָ��ͷ�ļ�
using namespace std;

int main()
{
    shared_ptr<int> sp1(new int(11));
    shared_ptr<int> sp2 = sp1; //�������죬 ��2������Ͷ����ռ��

    cout << "num = " << sp2.use_count() << endl; //��ӡ������

    //�ͷ�sp1�� ֻ�Ǽ�������ȥ1�� �����ռ�û���ͷ�
    sp1.reset();
    cout << "num = " << sp2.use_count() << endl; //��ӡ������

    cout << *sp2 << endl;
    //cout << *sp1 << endl;//err�� �ͷ�sp1�Ͷ����ռ�İ󶨣��޷�ͨ��sp1������������

    //�ͷ�sp2�� ֻ�Ǽ�������ȥ1�� ����������ֵΪ0�� �����ռ�����ͷ�
    sp2.reset();
    cout << "num = " << sp2.use_count() << endl; //��ӡ������

    return 0;
}
