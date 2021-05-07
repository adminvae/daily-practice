#include "list.h"
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head; //前后都指向自己
	return head;
}
ListNode* NewListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListDestory(ListNode* phead) //双向链表销毁
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
void ListPrint(ListNode* phead)//双向链表打印
{
	ListNode*cur = phead->next;
	while (cur!= phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(ListNode* phead, LTDataType x) //尾插
{
	ListNode* newnode = NewListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void ListPopBack(ListNode* phead) //尾删
{
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
}
void ListPushFront(ListNode* phead, LTDataType x)//头插
{
	ListNode* newnode = NewListNode(x);
	ListNode* first = phead->next; //此时顺序为 phead newnode first
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
void ListPopFront(ListNode* phead)//头删
{
	assert(phead->next != phead); //不能free掉头节点
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}
ListNode* ListFind(ListNode* phead, LTDataType x)//查找
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data!=x)
		{
			cur=cur->next;
		}
		return cur;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)//在pos前面进行插入
{
	ListNode* prev = pos->prev;
	ListNode*newnode = NewListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;  //使用ListInsert还可以实现头插ListInsert（head->next,x） 尾插ListInsert（head,x）
}
void ListErase(ListNode* pos)//删除pos位置的节点
{
	ListNode*prev = pos->prev;
	ListNode*next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;  //使用ListErase还可以实现头删ListErase（head->next） 尾删ListErase（head->prev）
}
void TestList()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);

	ListPopBack(list);
	ListPrint(list);

	ListPushFront(list, 0);
	ListPrint(list);

	ListPopFront(list);
	ListPrint(list);
}
int main()
{
	TestList();
	system("pause");
	return 0;
}