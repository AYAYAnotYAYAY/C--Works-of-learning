#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#if 1
struct file//索引表类型
{
	int fileNameSize;//文件名长度
	int fileoff;//文件偏移
	int filesize;//文件大小
	char filename[40];//文件名
};

void main()
{//打包
	file filejpg[] = { {0,0,0,"SZDT-802.jpg"},{0,0,0,"SZDT-803.jpg"},{0,0,0,"SZDT-804.jpg"},{0,0,0,"SZDT-807.jpg" } };//索引表初始化
	fstream file[4];//文件类型数组
	int lsize = 0/*文件花名册内容的大小*/, lnum = 4/*文件数量*/;
	for (int i=0;i<lnum;++i)//循环4次，处理4个文件
	{
		filejpg[i].fileNameSize = strlen(filejpg[i].filename)+1;//索引表的文件每个名字长度，取名字加\0所以加1
		lsize += 4 + 4 + 4 + filejpg[i].fileNameSize;//文件名大小int4字节加文件大小int四字节加文件偏移int四字节加文件名长度，文件名长度上一句已经计算
		file[i].open(filejpg[i].filename, ios::in | ios::binary);//打开文件，二进制类型打开
		//计算大小
		file[i].seekg(0,ios::end);//文件的位置设置到结束
		filejpg[i].filesize = file[i].tellp();//文件大小等于取指针当前位置，因为移动到末尾，所以位置等于大小
		file[i].seekp(0, ios::beg);//重置位置移回文件开头
	}
	//写文件
	fstream newfile("fuck.nep",ios::out|ios::binary);//新建一个文件类型流，二进制输出
	newfile.write((char*)&lsize,4);//参数是char*，给lsize取地址int*强转成char*只是为了符合参数
	newfile.write((char*)&lnum, 4);//同理，文件数量
	//写索引表
	for (int i=0;i<lnum;i++)
	{
		//文件偏移量
		if (i == 0)//如果是第一个文件，初始文件有8个字符偏移是索引那2个的大小偏移
		{
			filejpg[i].fileoff = 8 + lsize;//前面8字节加花名册表全部大小,就是第一个文件的起始
		}
		else//如果不是第一个文件
		{
			filejpg[i].fileoff = filejpg[i - 1].fileoff + filejpg[i - 1].filesize;//下一个文件的起始等于上一个文件的偏移值加大小。
		}
		//写花名册的具体表
		newfile.write((char*)&filejpg[i].filesize,4);//文件大小4个字节
		newfile.write((char*)&filejpg[i].fileoff, 4);//文件偏移四个字节
		newfile.write((char*)&filejpg[i].fileNameSize, 4);//文件名长度四个字节
		newfile.write(filejpg[i].filename,filejpg[i].fileNameSize);//最后写文件名字
	}
	//写正式文件内容
	char temp;
	for (int i=0;i<lnum;i++)
	{
		while (temp=file[i].get(),!file[i].eof())//End Of File文件结束
		{
			newfile<<temp;//写入
		}
	}

	for (int i = 0; i<lnum; i++)
	{
		file[i].close();
	}

	for (int j = 0; j<4; j++)
	{
		cout << filejpg[j].filename << "   " << filejpg[j].fileNameSize << "   " << filejpg[j].fileoff << "   " << filejpg[j].filesize << endl;
	}
	system("pause");

}
#endif