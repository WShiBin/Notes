#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	//ǿ����ö�٣� enum�������class��struct����
	enum class Status { Ok, Error };
	enum struct Status2 { Ok, Error };

	//Status flag = Ok; //err, ����ö�����͵�������
	Status flag = Status::Ok; //ok

	//ǿ����ö�٣�����ָ����Ա����������
	enum struct Status3: char { Ok, Error };
	cout << sizeof(Status3::Ok) << endl;

	enum struct Status4: long long { Ok, Error };
	cout << sizeof(Status4::Ok) << endl;

	system("pause");
	return 0;
}

int main01(void)
{
	enum Status {Ok, Error};
	// ��Ok��: �ض��壻��ǰ�Ķ����ǡ�ö������	
	//enum Status2 { Ok, Error };

	Status flag = Ok;

	cout << sizeof(Ok) << endl; //4


	system("pause");
	return 0;
}
