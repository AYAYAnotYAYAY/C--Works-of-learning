#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#if 1
struct file//����������
{
	int fileNameSize;//�ļ�������
	int fileoff;//�ļ�ƫ��
	int filesize;//�ļ���С
	char filename[40];//�ļ���
};

void main()
{//���
	file filejpg[] = { {0,0,0,"SZDT-802.jpg"},{0,0,0,"SZDT-803.jpg"},{0,0,0,"SZDT-804.jpg"},{0,0,0,"SZDT-807.jpg" } };//�������ʼ��
	fstream file[4];//�ļ���������
	int lsize = 0/*�ļ����������ݵĴ�С*/, lnum = 4/*�ļ�����*/;
	for (int i=0;i<lnum;++i)//ѭ��4�Σ�����4���ļ�
	{
		filejpg[i].fileNameSize = strlen(filejpg[i].filename)+1;//��������ļ�ÿ�����ֳ��ȣ�ȡ���ּ�\0���Լ�1
		lsize += 4 + 4 + 4 + filejpg[i].fileNameSize;//�ļ�����Сint4�ֽڼ��ļ���Сint���ֽڼ��ļ�ƫ��int���ֽڼ��ļ������ȣ��ļ���������һ���Ѿ�����
		file[i].open(filejpg[i].filename, ios::in | ios::binary);//���ļ������������ʹ�
		//�����С
		file[i].seekg(0,ios::end);//�ļ���λ�����õ�����
		filejpg[i].filesize = file[i].tellp();//�ļ���С����ȡָ�뵱ǰλ�ã���Ϊ�ƶ���ĩβ������λ�õ��ڴ�С
		file[i].seekp(0, ios::beg);//����λ���ƻ��ļ���ͷ
	}
	//д�ļ�
	fstream newfile("fuck.nep",ios::out|ios::binary);//�½�һ���ļ������������������
	newfile.write((char*)&lsize,4);//������char*����lsizeȡ��ַint*ǿת��char*ֻ��Ϊ�˷��ϲ���
	newfile.write((char*)&lnum, 4);//ͬ���ļ�����
	//д������
	for (int i=0;i<lnum;i++)
	{
		//�ļ�ƫ����
		if (i == 0)//����ǵ�һ���ļ�����ʼ�ļ���8���ַ�ƫ����������2���Ĵ�Сƫ��
		{
			filejpg[i].fileoff = 8 + lsize;//ǰ��8�ֽڼӻ������ȫ����С,���ǵ�һ���ļ�����ʼ
		}
		else//������ǵ�һ���ļ�
		{
			filejpg[i].fileoff = filejpg[i - 1].fileoff + filejpg[i - 1].filesize;//��һ���ļ�����ʼ������һ���ļ���ƫ��ֵ�Ӵ�С��
		}
		//д������ľ����
		newfile.write((char*)&filejpg[i].filesize,4);//�ļ���С4���ֽ�
		newfile.write((char*)&filejpg[i].fileoff, 4);//�ļ�ƫ���ĸ��ֽ�
		newfile.write((char*)&filejpg[i].fileNameSize, 4);//�ļ��������ĸ��ֽ�
		newfile.write(filejpg[i].filename,filejpg[i].fileNameSize);//���д�ļ�����
	}
	//д��ʽ�ļ�����
	char temp;
	for (int i=0;i<lnum;i++)
	{
		while (temp=file[i].get(),!file[i].eof())//End Of File�ļ�����
		{
			newfile<<temp;//д��
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