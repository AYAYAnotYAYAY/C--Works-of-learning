#include <iostream>
#include <Windows.h>
#pragma comment( lib,"winmm.lib" )
using namespace std;
#define ARRLEN 16000

void xuanzepaixu(int arr[], int len)//选择排序
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

void maopaopaixu(int arr[], int len)//冒泡排序
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

void charupaixu(int arr[], int len)//插入排序
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

void shellpaixu(int arr[], int len)//希尔排序
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
	int *pData = new int[length];//准备一个辅助数组，长度为归过来的元素个数
	memset(pData,0,sizeof(int)*length);
	int low = left;//定义一个变量，为左边的下标，防止改为left的值
	int hig = mid + 1;
	int index = 0;//辅助数组的下标
	while (hig <= right)//右边没有合并完成
	{
		//如果左边的值小于右边，且左边没有越界
		while (arr[low] <= arr[hig] && low <= mid)
		{
			pData[index] = arr[low];//把左边的值放进辅助数组
			low++;//左边的下标往右++
			index++;
		}
		if (low > mid)//证明左边放完了，左边的数据没有了
		{
			break;
		}
		/*------------------------------------------------------------------*/
		//如果左边的值大于右边，且右边没有越界
		while (arr[low] > arr[hig] && hig <= right)
		{
			pData[index] = arr[hig];//把右边的值放进辅助数组
			hig++;//右边的下标往右++
			index++;
		}
		
	}
	if (low <= mid)//证明左边没有放完
		memmove(&pData[index], &arr[low], sizeof(int)*(mid - low + 1));
	if (hig <= right)//证明左边没有放完
		memmove(&pData[index], &arr[hig], sizeof(int)*(right - hig + 1));
	//到这一步，把所有数据都按次序放在辅助数组里面
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
	_merge(arr,left,mid);//递归左区间
	_merge(arr,mid+1,right);//递归右区间
	_merge_in_arr(arr,left,mid,right);//并操作
}

void  _guibingpaixu(int arr[], int len)//归并排序
{
	_merge(arr, 0, len - 1);
}

void tongpaixu(int arr[], int len)//桶排序
{
	for (int n=1;n<10000;n*=10)
	{
		int temp[10][ARRLEN] = {};//定义辅助数组
		for (int m=0;m<10;++m)//辅助数组初始化
		{
			for (int u=0;u<ARRLEN;++u)
			{
				temp[m][u] = -1;
			}
		}
		//待排序的数组放进辅助数组
		for (int i = 0; i < len; ++i)
		{
			int index = (arr[i] / n) % 10;
			temp[index][i] = arr[i];
		}
		//把辅助数组的数据重新放回数组中
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
	cout << endl << "——————————————————————————" << endl;
	xuanzepaixu(arr1,ARRLEN);
	float endinTimer = timeGetTime() / 1000.0f;
	cout << "选择排序用时:" <<( endinTimer-beginTimer)<<"ms"<<endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "——————————————————————————" << endl;
	maopaopaixu(arr2, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "冒泡排序用时:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "——————————————————————————" << endl;
	charupaixu(arr3, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "插入排序用时:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "——————————————————————————" << endl;
	shellpaixu(arr4, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "希尔排序用时:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "——————————————————————————" << endl;
	_guibingpaixu(arr5, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "归并排序用时:" << (endinTimer - beginTimer) << "ms" << endl;
	beginTimer = timeGetTime() / 1000.0f;
	cout << endl << "——————————————————————————" << endl;
	tongpaixu(arr6, ARRLEN);
	endinTimer = timeGetTime() / 1000.0f;
	cout << "桶排序用时:" << (endinTimer - beginTimer) << "ms" << endl;
	system("pause");
}