#pragma once
#include <stdio.h>
//ð������ ʱ�临�Ӷȣ�O(N^2)
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
//��������
int PartSort(int* a, int begin, int end) //�������� hoare�汾 ����ָ��
{
	int key = a[end]; //end��key��������� begin��key���ұ�����
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//begin�Ҵ�
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//end��С
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
int PartSort2(int* a, int begin, int end) //�������� �ڿӷ�
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//begin�Ҵ�
		{
			++begin;
		}
		a[end] = a[begin];//�ҵ���� �����ұߵĿ��� beginλ�ó�Ϊ��λ
		while (begin < end && a[end] >= key)//end��С
		{
			--end;
		}
		a[begin] = a[end]; //�ҵ�С�� ������ߵĿ��� endλ�ó�Ϊ��λ
	}
	a[begin] = key;
	return begin;
}
int PrevCurMethod(int* a, int begin, int end) //ǰ��ָ��ʵ�ֵ�������
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur < end) //����key�ͽ�����
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
void QuickSort(int* a, int begin, int end)  //Ӧ�õݹ��˼��
{
	if(begin >= end)
		return;
	//int keyindex = PartSort(a, begin, end); //ʹ�� hoare�汾
	//int keyindex = PartSort2(a, begin, end); //ʹ���ڿӷ�
	int keyindex =PrevCurMethod(a, begin, end); //ʹ��ǰ��ָ��
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