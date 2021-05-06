//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include<assert.h>
//typedef struct ListNode{
//	int data;
//	struct ListNode* next;
//}Node;
//输入一个链表，输出该链表中倒数第k个元素
//struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k)
//{
//	Node* fast = pListHead;
//	Node* slow = pListHead;
//	while (k--)  //走了k步
//	{
//		if (fast == NULL)
//		{
//			return NULL;
//		}
//		else{
//			fast = fast->next;
//		}
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//合并两个有序链表
//struct ListNode* mergeTwoLists(struct ListNode*l1, struct ListNode*l2)
//{
//	if (l1 == NULL)
//	{
//		return l2;
//	}
//	if (l2 == NULL)
//	{
//		return l1;
//	}
//	Node* head = NULL;
//	Node* tail = NULL;
//	while (l1&&l2)
//	{
//		if (l1 ->data <= l2->data)
//		{
//			if (tail == NULL)
//			{
//				head = tail = l1;
//			}
//			else
//			{
//				tail->next = l1;
//				tail = l1;
//			}
//			    l1 = l1->next;
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				head = tail = l2;
//			}
//			else
//			{
//				tail->next = l2;
//				tail = l2;
//			}
//			l2 = l2->next;
//		}
//	}
//	if (l1)
//	{
//		tail->next = l1;
//	}
//	else if (l2)
//	{
//		tail->next = l2;
//	}
//	return head;
//} 

//链表分割 将小于x的结点排在大于x的结点之前z
//struct ListNode* partition(struct ListNode*pHead, int x)
//{
//	Node* cur = pHead;
//	Node* lessHead, *lessTail, *greaterHead, *greaterTail;
//	lessHead = lessTail = (Node*)malloc(sizeof(Node));
//	greaterHead = greaterTail = (Node*)malloc(sizeof(Node));
//	lessTail->next = NULL;
//	greaterTail->next = NULL;
//	while (cur)
//	{
//		if (cur->data <x)
//		{
//			lessTail->next = cur;
//			lessTail = cur;
//		}
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = cur;
//		}
//		cur = cur->next;
//	}
//	greaterTail->next = greaterHead->next;
//	greaterTail->next = NULL; //重点
//	Node* list = lessHead->next;
//	free(lessHead);
//	free(greaterHead);
//	return list;
//}

//链表的回文结构 时间复杂度O（n） 空间复杂度O（1）保证链表长度小于等于900
//int chkpalindrome(struct ListNode* A)
//{
//	int a[900] = { 0 };
//	int n = 0;
//	while (A)
//	{
//		a[n++] = A->data;
//		A = A->next;
//	}
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		if (a[begin] != a[end])
//		{
//			return 1;
//			++begin;
//			--end;
//		}
//		return 0;
//	}
//}

//相交链表  找到两个单链表相交的起始节点
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//	if (headA == NULL || headB ==NULL)
//	{
//		return NULL;
//	}
//	Node* curA = headA;
//	Node* curB = headB;
//	int lenA = 0, lenB = 0;
//	while (curA->next)
//	{
//		lenA++;
//		curA = curA->next;
//	}
//	while (curB->next)
//	{
//		lenB++;
//		curB = curB->next;
//	}
//	if (curA != curB)
//	{
//		return NULL;
//	}
//	int gap = abs(lenA - lenB); //abs求绝对值的函数
//	Node* longList = headA;
//	Node* shortList = headB;
//	if (lenA<lenB)
//	{
//		longList = headB;
//		shortList = headA;
//	}
//	while (gap--) //走gap步
//	{
//		longList = longList->next;
//	}
//	while (longList != shortList)
//	{
//		longList = longList->next;
//		shortList = shortList->next;
//	}
//	return longList;
//}

//环形链表 使用快慢指针
//int hasCycle(struct ListNode* head)
//{
//	Node* fast = head;
//	Node* slow = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;  //快慢指针
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main(){
//	system("pause");
//	return 0;
//}