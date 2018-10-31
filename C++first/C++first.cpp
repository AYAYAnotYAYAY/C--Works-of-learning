
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;



#if 1  //构造函数
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
	//构造函数（对象创建自动调用且只调用一次）
	GirFriend(string name="无名氏 ", int age=15, string job="无业游民  ") : g_name(name), g_age(new int(age)), g_job(job)
	{
		cout << "构造函数触发！" << endl;
	}
};

void main()
{
	GirFriend yang;   //省略参数，构造函数使用缺省值
	yang.zwjs();
	GirFriend zhang("卢本伟",20,"开挂");//传参实例化对象
	zhang.zwjs();
	getchar();
}
#endif