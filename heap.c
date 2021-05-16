#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
#include "heap.h"
void Swap(int*a, int*b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
//小堆 条件：左右子树都是堆
void AdjustDown(HpDataType*a,size_t n, HpDataType root) //向下调整算法 调堆
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (a[child+1]<a[child])
		{
			++child;
		}
		if (a[parent]>a[child])
		{
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(int* a, int child)//向上调整算法
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapCreat(Heap* hp,HpDataType *a, size_t n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	//建小堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	return hp;
}
void HeapPush(Heap* hp, HpDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(sizeof(HpDataType)*newcapacity,hp->_capacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
HpDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
HpDataType HeapEmpty(Heap* hp)
{
	return hp->_size > 0 ? 1 : 0;
}
int main(){
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 28, 18 };
	Heap hp;
	HeapCreat(&hp, a, 10);
	system("pause");
	return 0;
}