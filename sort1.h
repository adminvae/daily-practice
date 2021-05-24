#pragma once
#include <stdio.h>
typedef int HpDataType;
void PrintArray(int* a,int n)
{
	for (size_t i = 0; i < n;++i)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
//插入排序 时间复杂度O(N^2)
void InsertSort(int*a, int n) 
{
	//控制end的位置从2走到n-2
	for (int i = 0; i < n - 1;++i)
	{
		//单趟排序 在[0,end]区间中插入tmp，依旧有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//希尔排序 平均时间复杂度O（N^1.3） 最坏情况是顺序有序
void ShellSort(int* a,int n)
{
	int gap = n;//间隔为gap的预排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1保证最后一次是1
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//选择排序 一次性选出两个数，最小的一个放第一个位置，最大的放在最后一个位置 时间复杂度O（N^2）
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a,int n)
{
	int begin = 0;
	int end = n - 1;
	//[begin,end]选出一个最小的，选出一个最大的数的下标
	while (begin < end)
	{
		int mini = begin;
		int maxi = end;
		for (int i = begin; i <= end;++i)
		{
			if (a[i]>a[maxi])
			{
				maxi = i;
			}
			if (a[i]<a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
//堆排序 排升序 建小堆
void AdjustDown(HpDataType*a,size_t n, HpDataType root) //向下调整算法 调堆
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child+1 < n && a[child+1] > a[child])
		{
			++child;
		}
		if (a[parent]<a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)  //时间复杂度O（N*logN）
{
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6 ,1,4};
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestShellSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestSelectSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestHeapSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}