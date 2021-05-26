#pragma once
#include <stdio.h>
//冒泡排序 时间复杂度：O(N^2)
void BubbleSort(int* a, int n)
{
	int flag = 0;
	for (int end = n-1; end > 0;--end)
	{
	for (int j = 0; j < n - 1;++j)
	{
		if (a[j]>a[j+1])
		{
			Swap(&a[j], &a[j + 1]);
			flag = 1;
		}
	 }
	if (flag = 0)
	{
		break;
	}
	}
}
//快速排序
int PartSort(int* a, int begin, int end) //单趟排序 hoare版本 左右指针
{
	int key = a[end]; //end做key，左边先走 begin做key，右边先走
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//begin找大
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//end找小
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
int PartSort2(int* a, int begin, int end) //单趟排序 挖坑法
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//begin找大
		{
			++begin;
		}
		a[end] = a[begin];//找到大的 放在右边的坑里 begin位置成为坑位
		while (begin < end && a[end] >= key)//end找小
		{
			--end;
		}
		a[begin] = a[end]; //找到小的 放在左边的坑里 end位置成为坑位
	}
	a[begin] = key;
	return begin;
}
int PrevCurMethod(int* a, int begin, int end) //前后指针实现单趟排序
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur < end) //遇到key就结束了
	{
		if (a[cur]<key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	++prev;
	Swap(&a[prev], &a[end]);
	return prev;
}
void QuickSort(int* a, int begin, int end)  //应用递归的思想
{
	if(begin >= end)
		return;
	//int keyindex = PartSort(a, begin, end); //使用 hoare版本
	//int keyindex = PartSort2(a, begin, end); //使用挖坑法
	int keyindex =PrevCurMethod(a, begin, end); //使用前后指针
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1,end);
}


void TestBubbleSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	QuickSort(a,0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}