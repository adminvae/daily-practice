#pragma once
#include <stdio.h>
typedef int SLDataType;
typedef struct SListNode 
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);  //��ӡ
void SListPushBack(SListNode** ppList,SLDataType x);//β��
void SListPushFront(SListNode** ppList, SLDataType x);//ͷ��
void SListPopBack(SListNode** ppList);//βɾ
void SListPopFront(SListNode** ppList);//ͷɾ
SListNode* SListFind(SListNode* pList, SLDataType x);//����
void SListInsertAfter(SListNode*pos, SLDataType x); //��posλ��֮�����x
void SListEraseAfter(SListNode*pos);//ɾ��posλ��֮���ֵ