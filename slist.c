#define _CRT_SECURE_NO_WARNINGS
#include "slist.h"
void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SListNode* NewSListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPushBack(SListNode** ppList, SLDataType x) //尾插
{
	SListNode* newNode = NewSListNode(x);
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;

		}
		tail->next = newNode;
	}
}
void SListPushFront(SListNode** ppList, SLDataType x)//头插
{
	SListNode* newNode = NewSListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}
void SListPopBack(SListNode** ppList)//尾删
{
	if (*ppList == NULL) //空
	{
		return;
	}
	else if ((*ppList)->next == NULL) //只有一个节点
	{
		free(*ppList);
		*ppList = NULL;
	}
	else{  //有多个节点
		SListNode* tail = *ppList;
		SListNode*prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void SListPopFront(SListNode** ppList)//头删
{
		SListNode*nextnode = (*ppList)->next;
		free(*ppList);
		*ppList = nextnode;
	}
SListNode* SListFind(SListNode* pList, SLDataType x) //查找
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->next == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode*pos, SLDataType x)//在pos位置之后插入x
{
	SListNode* newnode = NewSListNode(x);
	SListNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
void SListEraseAfter(SListNode*pos)//删除pos位置之后的值
{
	SListNode* next = pos->next;
	if (next!= NULL)
	{
		next->next = next->next;
		free(next);
	}
}
void TestSList()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListPushFront(&pList, 0);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPrint(pList);

}
int main(){
	TestSList();
	system("pause");
	return 0;
}