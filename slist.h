#pragma once
#include <stdio.h>
typedef int SLDataType;
typedef struct SListNode 
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);  //打印
void SListPushBack(SListNode** ppList,SLDataType x);//尾插
void SListPushFront(SListNode** ppList, SLDataType x);//头插
void SListPopBack(SListNode** ppList);//尾删
void SListPopFront(SListNode** ppList);//头删
SListNode* SListFind(SListNode* pList, SLDataType x);//查找
void SListInsertAfter(SListNode*pos, SLDataType x); //在pos位置之后插入x
void SListEraseAfter(SListNode*pos);//删除pos位置之后的值