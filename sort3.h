#pragma once
#include <stdio.h>
////���������Ż��� ����ȡ�з� ���԰�������������������Ž�
//int GetMidIndex(int* a, int begin, int end)
//{
//	int mid = (begin + end) >> 1; //������λ�ķ�ʽ����
//	if (a[begin] < a[mid])
//	{
//		if (a[mid] < a[end])
//		{
//			return mid;
//		}
//		else if (a[begin] < a[end])
//		{
//			return end;
//		}
//		else{
//			return begin;
//		}
//	}
//	else if (a[begin] > a[mid])
//	{
//		if (a[mid] > a[end])
//		{
//			return mid;
//		}
//		else if (a[begin] < a[mid])
//		{
//			return begin;
//		}
//		else{
//			return end;
//		}
//	}
//
//}
//int PrevCurMethod(int* a, int begin, int end) //ǰ��ָ��ʵ�ֵ�������
//{
//	int midindex = GetMidIndex(a, begin, end);
//	Swap(&a[midindex], &a[end]);
//	int prev = begin - 1;
//	int cur = begin;
//	int key = a[end];
//	while (cur < end) //����key�ͽ�����
//	{
//		if (a[cur] < key && ++prev != cur)
//		{
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	++prev;
//	Swap(&a[prev], &a[end]);
//	return prev;
//}
//int QuickSort(int* a, int begin, int end)  //Ӧ�õݹ��˼��
//{
//	if (begin >= end)
//		return;
//	int keyindex = PrevCurMethod(a, begin, end); //ʹ��ǰ��ָ��
//	QuickSort(a, begin, keyindex - 1);
//	QuickSort(a, keyindex + 1, end);
//}
//void TestQuickSort()
//{
//	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
//	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
////�ǵݹ�ʵ�ֿ������� ʹ�����ݽṹ��ջ��ģ��ݹ�
//void QuickSortNonR(int* a, int begin, int end)
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, begin);
//	StackPush(&st, end);
//	while (!StackEmpty(&st))
//	{
//		int right = StackTop(&st);
//		StackPop(&st);
//		int left = StackTop(&st);
//		StackPop(&st);
//		int keyindex = PrevCurMethod(a, left, right);
//		if (left < keyindex-1)
//		{
//			StackPush(&st, left);
//			StackPush(&st,keyindex-1);
//		}
//		if (keyindex+1 < right)
//		{
//			StackPush(&st, keyindex+1);
//			StackPush(&st,right);
//		}
//	}
//	StackDestroy(&st);
//}
//�鲢���� ʱ�临�Ӷ� O��N*logN��  �鲢�������������������鲢������
void _MergeSort(int*a, int begin, int end,int*tmp)
{
	if (begin >= end)
		return;

	int mid = begin + end >> 1; //�Ȼ��ֳ�����
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
			tmp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));//���鲢��tmp�����ݹ鲢��ԭ����
}
void MergeSort(int *a, int n)
{
	int*tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}
int TestMergeSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	MergeSort(a,sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}