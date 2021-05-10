//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include<assert.h>
//循环队列
//typedef struct{
//	int* array; //数组
//	int n; //数组空间的大小
//	int front;//队头
//	int rear;//队尾
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

////复杂链表的复制
//typedef  struct ListNode{
//	struct ListNode* next;
//	struct ListNode* random;
//	int val;
//}Node;
//
//Node* Copyrandomnode(Node* head) //拷贝节点并插入原节点后面
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
//	//置random
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
//	//拆分各个节点
//	Node* copyhead = NULL, *copytail= NULL;
//	cur = head;
//	while (cur)
//	{
//		Node* copynode = cur->next;
//		Node* next = copynode->next;
//		//copynode尾插到拷贝链表
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

