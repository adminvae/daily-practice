#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>

//��ת���� �ռ临�Ӷ�ΪO(1)
//void reverse(int* nums, int begin, int end) //���ú���
//{
//	while (begin < end)
//	{
//		int tmp = nums[begin];
//		nums[begin] = nums[end];
//		nums[end] = tmp;
//		++begin;
//		--end;
//	}
//}
//void rotate(int*nums, int numssize, int k)
//{
//	reverse(nums, 0, numssize-1);
//	if (k > numssize)
//	{
//		k %= numssize;
//	}
//	reverse(nums, 0, k - 1);
//	reverse(nums, k, numssize-1);
//}
//
////������ʽ�������ӷ�
//int* addToArryForm(int* a, int asize, int k, int* returnsize)
//{
//	int* addret = (int*)malloc(10001 * sizeof(int));
//	int reti = 0;
//	int next = 0;//��λֵ
//	int ai = asize - 1;
//	while (ai >= 0 || k > 0)
//	{
//		int x1 = 0;
//		if (ai>=0)
//		{
//			x1 = a[ai];
//			--ai;
//		}
//		int x2 = 0;
//		if (k>0)
//		{
//			x2 = k % 10;
//			k /= 10;
//		}
//		int ret = x1 + x2 + next;
//		if (ret>9)
//		{
//			ret %= 10;
//			next = 1;
//		}
//		else
//		{
//			next = 0;
//		}
//		addret[reti++] = ret;
//	}
//	if (next == 1)
//	{
//		addret[reti++] = 1;
//	}
//	reverse(addret, 0, reti - 1);
//	*returnsize = reti;
//	return addret;
//}

//������м�ڵ�
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head)
//{
//	ListNode*slow = head;  //����ָ��
//	ListNode*fast = head;
//	while (!(fast == NULL || slow == NULL))
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}

//�Ƴ�����Ԫ��
//typedef struct ListNode{
//	int data;
//	struct ListNode* next;
//
//}Node;
//struct ListNode* removeElement(struct ListNode* head, int val)
//{
//	ListNode* prev = NULL;
//	ListNode* cur = head;
//	while (cur != NULL)
//	{
//		if (cur->val == val)
//		{
//			ListNode* next = cur->next;
//			free(cur);
//			if (cur == head)
//			{
//				head = next;
//			}
//			else
//			{
//				prev = cur;
//				cur = cur->next;
//			}
//		}
//		return head;
//	}
//}
//int main(){
//	int a[] = { 9, 9, 9 };
//	int k = 11;
//	int retlen = 0;
//	int* adda = addToArryForm(a, sizeof(a) / sizeof(int), k,&retlen);
//	system("pause"); 
//	return 0;
//}

//��ת���� ��������
//typedef struct ListNode{
//	int data;
//	struct ListNode* next;
//
//}Node;
//struct ListNode* reverseList(struct ListNode* head)  //��ת��ͷ�ķ���
//{
//	if (head == NULL||head->next == NULL)
//	{
//		return head;
//	}
//	Node*n1, *n2, *n3;
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//	while (n2 != NULL)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3!=NULL)
//		{
//			n3 = n3->next;
//		}
//	}
//	return n1;
//}
//struct ListNode* reverseList(struct ListNode* head) //ͷ�巨
//{
//	Node*cur = head;
//	Node*newhead = NULL;
//	while (cur)
//	{
//		Node*next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//	return newhead;
//}
