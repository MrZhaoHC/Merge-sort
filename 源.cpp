#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 100

//�鲢�����㷨
void merge(int* a, int l, int r, int mid)
{
	int* arr;//�洢Ҫ�ϲ�����������
	arr = (int*)malloc((l + r + 1) * sizeof(int));
	for (int i = l; i <= r; i++)
	{
		arr[i] = a[i];
	}
	int i = l;//�������һ��
	int j = mid + 1;//�������һ��
	int k = l;//���շ�������ĵ�ǰλ��
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
	//��ʣ������ִ���a����
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
	if (l >= r)//�ݹ�ֹͣ����
		return;
	int mid = (r + l) / 2;
	merg_sort(a, l, mid);//�����Ѫ
	merg_sort(a, mid + 1, r);//�ұ�����
	merge(a, l, r, mid);
}

void mergsort(int *a, int l, int r)
{
	merg_sort(a, l, r - 1);
}

int main()
{
	int n;
	cout << "������Ҫ������Ŀ" << endl;
	cin >> n;
	int* a;
	a = (int*)malloc(sizeof(int)*n);
	cout << "������Ҫ��������" << endl;
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










