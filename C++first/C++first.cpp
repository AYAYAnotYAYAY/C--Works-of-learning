
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;



#if 1  //���캯��
class GirFriend
{
private:
	string g_name;
	int* g_age;
	string g_job;
public:
	void zwjs()
	{
		cout<<g_name<<"  "<<*(g_age)<<"   "<<g_job<<endl;
	}
	//���캯�������󴴽��Զ�������ֻ����һ�Σ�
	GirFriend(string name="������ ", int age=15, string job="��ҵ����  ") : g_name(name), g_age(new int(age)), g_job(job)
	{
		cout << "���캯��������" << endl;
	}
};

void main()
{
	GirFriend yang;   //ʡ�Բ��������캯��ʹ��ȱʡֵ
	yang.zwjs();
	GirFriend zhang("¬��ΰ",20,"����");//����ʵ��������
	zhang.zwjs();
	getchar();
}
#endif