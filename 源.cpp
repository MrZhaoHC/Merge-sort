#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 100

//归并排序算法
void merge(int* a, int l, int r, int mid)
{
	int* arr;//存储要合并的两个数组
	arr = (int*)malloc((l + r + 1) * sizeof(int));
	for (int i = l; i <= r; i++)
	{
		arr[i] = a[i];
	}
	int i = l;//左数组第一个
	int j = mid + 1;//右数组第一个
	int k = l;//最终返回数组的当前位置
	while (i <= mid && j <= r)
	{
		if (arr[i] < arr[j])
		{
			a[k++] = arr[i++];
			
		}
		else if (arr[i] == arr[j])
		{
			a[k++] = arr[i++];
			a[k++] = arr[j++];
		}
		else
		{
			a[k++] = arr[j++];
			
		}
	}
	//将剩余的数字存入a数组
	while (i <= mid)
	{
		a[k++] = arr[i++];
	}
	while (j <= r)
	{
		a[k++] = arr[j++];
	}
}

void merg_sort(int* a, int l, int r)
{
	if (l >= r)//递归停止条件
		return;
	int mid = (r + l) / 2;
	merg_sort(a, l, mid);//左边排血
	merg_sort(a, mid + 1, r);//右边排序
	merge(a, l, r, mid);
}

void mergsort(int *a, int l, int r)
{
	merg_sort(a, l, r - 1);
}

int main()
{
	int n;
	cout << "请输入要排序数目" << endl;
	cin >> n;
	int* a;
	a = (int*)malloc(sizeof(int)*n);
	cout << "请输入要排序数组" << endl;
	for (int i = 0; i < n; i++)
	{	
		cin >> a[i];
	}
	mergsort(a, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}










