#include "list.h"
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head; //ǰ��ָ���Լ�
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
void ListDestory(ListNode* phead) //˫����������
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
void ListPrint(ListNode* phead)//˫�������ӡ
{
	ListNode*cur = phead->next;
	while (cur!= phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(ListNode* phead, LTDataType x) //β��
{
	ListNode* newnode = NewListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void ListPopBack(ListNode* phead) //βɾ
{
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
}
void ListPushFront(ListNode* phead, LTDataType x)//ͷ��
{
	ListNode* newnode = NewListNode(x);
	ListNode* first = phead->next; //��ʱ˳��Ϊ phead newnode first
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
void ListPopFront(ListNode* phead)//ͷɾ
{
	assert(phead->next != phead); //����free��ͷ�ڵ�
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}
ListNode* ListFind(ListNode* phead, LTDataType x)//����
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
void ListInsert(ListNode* pos, LTDataType x)//��posǰ����в���
{
	ListNode* prev = pos->prev;
	ListNode*newnode = NewListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;  //ʹ��ListInsert������ʵ��ͷ��ListInsert��head->next,x�� β��ListInsert��head,x��
}
void ListErase(ListNode* pos)//ɾ��posλ�õĽڵ�
{
	ListNode*prev = pos->prev;
	ListNode*next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;  //ʹ��ListErase������ʵ��ͷɾListErase��head->next�� βɾListErase��head->prev��
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