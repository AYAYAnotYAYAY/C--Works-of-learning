#include <iostream>
#include <Windows.h>
#pragma comment( lib,"winmm.lib" )
using namespace std;
#define ARRLEN 16000

void xuanzepaixu(int arr[], int len)//ѡ������
{
	int j, temp;
	for (int i=0;i<len-1;i++)
	{
		for (j=i+1;j<len;j++)
		{
			if (arr[i]<arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void maopaopaixu(int arr[], int len)//ð������
{
	int j, temp;
	for (int i = 0; i<len - 1; i++)
	{
		for ( j = 0; j < len; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void charupaixu(int arr[], int len)//��������
{
	int j, temp;
	for (int i = 1; i<len; i++)
	{
		temp = arr[i];
		j = i - 1;
		while ( j >= 0&& arr[j] < temp)
		{
				arr[j + 1] = arr[j];
				j--;
		}
		arr[j + 1] = temp;
	}
}

void shellpaixu(int arr[], int len)//ϣ������
{
	int j, temp;
	int jump=len>>1;
	while (jump != 0)
	{
		for (int i = jump; i<len; i++)
		{
			temp = arr[i];
			j =i- jump;
			while (j >= 0 && arr[j] < temp)
			{
				arr[j + jump] = arr[j];
				j-=jump;
			}
			arr[j + jump] = temp;
		}
		jump=jump >> 1;

	}
	
}
void _merge_in_arr(int arr[], int left, int mid, int right)
{
	int length = right - left + 1;
	int *pData = new int[length];//׼��һ���������飬����Ϊ�������Ԫ�ظ���
	memset(pData,0,sizeof(int)*length);
	int low = left;//����һ��������Ϊ��ߵ��±꣬��ֹ��Ϊleft��ֵ
	int hig = mid + 1;
	int index = 0;//����������±�
	while (hig <= right)//�ұ�û�кϲ����
	{
		//�����ߵ�ֵС���ұߣ������û��Խ��
		while (arr[low] <= arr[hig] && low <= mid)
		{
			pData[index] = arr[low];//����ߵ�ֵ�Ž���������
			low++;//��ߵ��±�����++
			index++;
		}
		if (low > mid)//֤����߷����ˣ���ߵ�����û����
		{
			break;
		}
		/*------------------------------------------------------------------*/
		//�����ߵ�ֵ�����ұߣ����ұ�û��Խ��
		while (arr[low] > arr[hig] && hig <= right)
		{
			pData[index] = arr[hig];//���ұߵ�ֵ�Ž���������
			hig++;//�ұߵ��±�����++
			index++;
		}
		
	}
	if (low <= mid)//֤�����û�з���
		memmove(&pData[index], &arr[low], sizeof(int)*(mid - low + 1));
	if (hig <= right)//֤�����û�з���
		memmove(&pData[index], &arr[hig], sizeof(int)*(right - hig + 1));
	//����һ�������������ݶ���������ڸ�����������
	memmove(&arr[left], pData, sizeof(int)*length);
	delete[]pData;
}
void _merge(int arr[], int left, int right)
{
	if(left>=right)
	{
		return;
	}
	int mid = (right + left)>>1;
	_merge(arr,left,mid);//�ݹ�������
	_merge(arr,mid+1,right);//�ݹ�������
	_merge_in_arr(arr,left,mid,right);//������
}

void  _guibingpaixu(int arr[], int len)//�鲢����
{
	_merge(arr, 0, len - 1);
}

void tongpaixu(int arr[], int len)//Ͱ����
{
	for (int n=1;n<10000;n*=10)
	{
		int temp[10][ARRLEN] = {};//���帨������
		for (int m=0;m<10;++m)//���������ʼ��
		{
			for (int u=0;u<ARRLEN;++u)
			{
				temp[m][u] = -1;
			}
		}
		//�����������Ž���������
		for (int i = 0; i < len; ++i)
		{
			int index = (arr[i] / n) % 10;
			temp[index][i] = arr[i];
		}
		//�Ѹ���������������·Ż�������
		int k = 0;
		for (int m = 0; m<10; ++m)
		{
			for (int u = 0; u<ARRLEN; ++u)
			{
				if (temp[m][u] != -1)
				{
					arr[k++] = temp[m][u];
				}
			}
		}
	}
}
void main()
{
	srand(timeGetTime());
	int arr1[ARRLEN],arr2[ARRLEN], arr3[ARRLEN], arr4[ARRLEN], arr5[ARRLEN], arr6[ARRLEN];
	for (int i=0;i<ARRLEN;i++)
	{
		arr1[i] = rand()%1000;
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
	}
	float beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	xuanzepaixu(arr1,ARRLEN);
	float endinTimer = timeGetTime() / 1000.0f;
	cout << "ѡ��������ʱ:" <<( endinTimer-beginTimer)<<"ms"<<endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	maopaopaixu(arr2, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "ð��������ʱ:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	charupaixu(arr3, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "����������ʱ:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	shellpaixu(arr4, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "ϣ��������ʱ:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	_guibingpaixu(arr5, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "�鲢������ʱ:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "����������������������������������������������������" << endl;
	tongpaixu(arr6, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "Ͱ������ʱ:" << (endinTimer - beginTimer) << "ms" << endl;
	system("pause");
}