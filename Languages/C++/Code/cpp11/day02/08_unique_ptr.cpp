#include <iostream>
#include <memory> //����ָ��ͷ�ļ�
using namespace std;

class Test
{
public:
    ~Test()
    {
        cout << "����\n";
    }
};

int main04()
{
    unique_ptr<int> up1(new int(11));

    //�ͷſ���Ȩ�����ͷŶ����ڴ�
    int * p = up1.release();
    cout << *p << endl;
    //cout << *up1 << endl; //err

    delete p;


    return 0;
}

int main03()
{
    unique_ptr<int> up1(new int(11));

    //up1.reset(); //������޲Σ���������ʽ�ͷŶ�������

    //����в��������ͷ�ԭ���������ݣ����¸�up1��һ���µĶ�������
    up1.reset(new int(22));
    cout << *up1 << endl;

    return 0;
}

int main02()
{
    unique_ptr<int> up1(new int(11)); //��������ָ�����, up1��Ψһʹ����
    //unique_ptr<int> up2 = up1; //���ÿ������죬 err

    //��up1��ʹ��Ȩ��ת���up2, up1�����ٲ��������ռ�
    unique_ptr<int> up2 = std::move(up1);
    cout << "*up2 = " << *up2 << endl;
    //cout << "*up1 = " << *up1 << endl; //err

    return 0;
}

int main()
{
    unique_ptr<int> up1(new int(11)); //��������ָ�����
    cout << "*up1 = " << *up1 << endl; //������operator *()

    {
        unique_ptr<Test> up2(new Test); //�����ͷţ��Զ��ͷ�

        //��Ϊָ���ͷŶ����ռ�
        up2 = nullptr;  //1
        up2 = NULL;     //2
        up2.reset();
        up2.reset();

        cout << "111111111\n";


    }
    cout << "-----------------\n";

    return 0;
}

