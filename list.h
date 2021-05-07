#pragma  once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int LTDataType;
typedef struct ListNode 
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* ListCreate();
void ListDestory(ListNode* phead); //双向链表销毁
void ListPrint(ListNode* phead);//双向链表打印
void ListPushBack(ListNode* phead, LTDataType x); //尾插
void ListPopBack(ListNode* phead); //尾删
void ListPushFront(ListNode* phead, LTDataType x);//头插
void ListPopFront(ListNode* phead);//头插
ListNode* ListFind(ListNode* phead, LTDataType x);//查找
void ListInsert(ListNode* pos, LTDataType x);//在pos前面进行插入
void ListErase(ListNode* pos);//删除pos位置的节点