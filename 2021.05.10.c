//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include<assert.h>
//ѭ������
//typedef struct{
//	int* array; //����
//	int n; //����ռ�Ĵ�С
//	int front;//��ͷ
//	int rear;//��β
//}MyCircularQueue;
//
//MyCircularQueue* MyCircularQueueCreate(int k)
//{
//	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	cq->array = (int*)malloc(sizeof(int)*(k + 1));
//	cq->n = k + 1;
//}
//bool MyCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	return obj->front == obj->rear;
//}
//bool MyCircularQueueIsFull(MyCircularQueue* obj)
//{
//	int rearnext = obj->rear + 1;
//	rearnext %= obj->n;
//	return rearnext == obj->front;
//}
//int MyCircularQueueFront(MyCircularQueue* obj)
//{
//	if (MyCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	return obj->array[obj->front];
//}
//int MyCircularQueueRear(MyCircularQueue* obj)
//{
//	if (MyCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	int prevrear = obj->rear - 1;
//	if (obj->rear == 0)
//	{
//		prevrear = obj->n - 1;
//		return obj->array[prevrear];
//	}
//}

////��������ĸ���
//typedef  struct ListNode{
//	struct ListNode* next;
//	struct ListNode* random;
//	int val;
//}Node;
//
//Node* Copyrandomnode(Node* head) //�����ڵ㲢����ԭ�ڵ����
//{
//	Node* cur = head;
//	while (cur)
//	{
//		Node* next = cur->next;
//		Node* copynode = (Node*)malloc(sizeof(Node));
//		copynode->val = cur->val;
//		copynode ->next = NULL;
//		copynode->random = NULL;
//
//		cur->next = copynode;
//		copynode->next = next;
//
//		cur = next;
//	}
//	//��random
//	cur = head;
//	while (cur)
//	{
//		Node* copynode = cur->next;
//		if (cur->random ==NULL)
//		{
//			copynode->random = cur->random->next;
//		}
//		else{
//			copynode->random = NULL;
//		}
//		cur = cur->next->next;
//	}
//	//��ָ����ڵ�
//	Node* copyhead = NULL, *copytail= NULL;
//	cur = head;
//	while (cur)
//	{
//		Node* copynode = cur->next;
//		Node* next = copynode->next;
//		//copynodeβ�嵽��������
//		if (copytail == NULL)
//		{
//			copyhead = copytail = copynode;
//		}
//		else
//		{
//			copytail->next = copynode;
//			copytail = copynode;
//		}
//		cur->next = next;
//		cur = next;
//	}
//	return copyhead;
//}
//int main(){
//	system("pause");
//	return 0;
//}

