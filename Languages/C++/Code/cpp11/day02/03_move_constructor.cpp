#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
    MyString(const char *tmp = "abc")
    {//��ͨ���캯��
        len = strlen(tmp);  //����
        str = new char[len+1]; //��������ռ�
        strcpy(str, tmp); //��������

        cout << "��ͨ���캯�� str = " << str << endl;
    }

    MyString(const MyString &tmp)
    {//�������캯��
        len = tmp.len;
        str = new char[len + 1];
        strcpy(str, tmp.str);

        cout << "�������캯�� tmp.str = " << tmp.str << endl;
    }

    //�ƶ����캯��
    //�����Ƿ�const����ֵ����
    MyString(MyString && t)
    {
        str = t.str; //������ַ��û�����������ڴ�
        len = t.len;

        //ԭ��ָ���ÿ�
        t.str = NULL;
        cout << "�ƶ����캯��" << endl;
    }

    MyString &operator= (const MyString &tmp)
    {//��ֵ��������غ���
        if(&tmp == this)
        {
            return *this;
        }

        //���ͷ�ԭ�����ڴ�
        len = 0;
        delete []str;

        //������������
        len = tmp.len;
        str = new char[len + 1];
        strcpy(str, tmp.str);

         cout << "��ֵ��������غ��� tmp.str = " << tmp.str << endl;

        return *this;

    }

    ~MyString()
    {//��������
        cout << "��������: ";
        if(str != NULL)
        {
            cout << "�Ѳ���delete, str =  " << str;
            delete []str;
            str = NULL;
            len = 0;

        }
        cout << endl;
    }

private:
    char *str = NULL;
    int len = 0;
};

MyString func() //������ͨ���󣬲�������
{
    MyString obj("mike");

    return obj;
}

int main()
{
    MyString &&tmp = func(); //��ֵ���ý���

    return 0;
}
