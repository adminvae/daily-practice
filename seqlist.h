#pragma once
#include <stdio.h>
#include<assert.h>
#include <stdlib.h>
typedef int SLDatatype;
typedef struct Seqlist
{
	SLDatatype* a;
	size_t size;
	size_t capacity;
}Seqlist;
//对数据的管理 增删改查
void SeqListInit(Seqlist* ps);
void SeqListDestory(Seqlist* ps);
void SeqListPrint(Seqlist* ps);
void SeqListPushBack(Seqlist* ps, SLDatatype x); //尾插
void SeqListPushFront(Seqlist* ps, SLDatatype x); // 头插
void SeqListPopBack(Seqlist* ps); //尾删
void SeqListPopFront(Seqlist* ps); // 头删
int SeqListFind(Seqlist*ps, SLDatatype x);//顺序表查找
void SeqListInsert(Seqlist*ps, size_t pos, SLDatatype x);//顺序表在pos处插入x
void SeqListErase(Seqlist*ps, size_t pos);//删除pos位置的值