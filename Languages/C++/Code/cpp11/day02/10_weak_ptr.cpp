#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> p1(new int(11));
    shared_ptr<int> p2 = p1; //��2������󶨶�������

    weak_ptr<int> wp = p1;

    cout << "num = " << p1.use_count() << endl; //��ӡ������
    cout << "num = " << wp.use_count() << endl; //��ӡ������

    //weak_ptr��Ȼ���Ͷ����ռ�󶨣�����ͨ��lock������ȡshared_ptr<int>����
    shared_ptr<int> p3 = wp.lock(); //��3������󶨶�������
    cout << "num2 = " << p1.use_count() << endl; //��ӡ������
    cout << "num2 = " << wp.use_count() << endl; //��ӡ������

    cout << *p1 << ", " << *p2 << ", " << *p3 << endl;
    //cout << *wp << endl; //err, û������ * �� ->
    p1.reset();
    p2.reset();
    p3.reset();
    cout << "num3 = " << p1.use_count() << endl; //��ӡ������
    cout << "num3 = " << wp.use_count() << endl; //��ӡ������

    //�������ռ��ͷź�wp.lock()��ȡ�ķ���ֵΪnullptr
    shared_ptr<int> tmp = wp.lock();
    if(tmp == nullptr)
    {
        cout << "�����ռ��Ѿ��ͷ�\n";
    }


    return 0;
}

