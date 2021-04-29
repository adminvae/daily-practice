#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
#include "seqlist.h"

void SeqListInit(Seqlist* ps)
{
	assert(ps);
	ps ->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(Seqlist* ps){
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(Seqlist* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d", ps->a[i]);
	}
	printf("\n");
}
void CheckCapacity(Seqlist*ps){ //容量检查及增容
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //判断之前的内存大小是否为零
		ps->a = (SLDatatype*)realloc(ps->a, newcapacity*sizeof(SLDatatype));
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(Seqlist* ps, SLDatatype x) //尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;  //以数组形式存储
	ps->size++;
}
void SeqListPushFront(Seqlist* ps, SLDatatype x) // 头插
{
	assert(ps);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[0] = x;
	++ps->size;
}
void SeqListPopBack(Seqlist* ps)//尾删
{
	assert(ps);
	ps->size--;
}
void SeqListPopFront(Seqlist* ps) // 头删
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size-1) //控制边界
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	--ps->size;
}
int SeqListFind(Seqlist* ps, SLDatatype x)//顺序表查找
{
	for (size_t i = 0; i < ps->size;++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(Seqlist*ps, size_t pos, SLDatatype x)//顺序表在pos处插入x
{
	assert(ps);
	assert(pos < ps->size);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end + 1] = ps->a[end-1];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(Seqlist*ps, size_t pos)//删除pos位置的值
{
	assert(ps);
	assert(pos < ps->size);
	size_t start = pos;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
void TestSeqList()
{
	Seqlist s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListPrint(&s);

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListFind(&s,4);
	SeqListPrint(&s);

	SeqListInsert(&s,3,3);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListPrint(&s);

	SeqListDestory(&s);
}
int main(){
	TestSeqList();
	system("pause");
	return 0;
}