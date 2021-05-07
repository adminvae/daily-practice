#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue  // 队列的结构
{
	QNode* _front;//指向队头
	QNode* _back;//指向队尾
}Queue;

void QueueInit(Queue* q)// 初始化队列
{
	assert(q);
	q->_front = q->_back = NULL;
}
void QueuePush(Queue* q, QDataType data)// 队尾入队列
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = data;
	newnode->next = NULL;
	if (q->_back == NULL)
	{
		q->_back = q->_front = newnode;
	}
	else{
		q->_back->next = newnode; //插入
		q->_back = newnode; //移动尾指针
	}
}
void QueuePop(Queue* q)// 队头出队列
{
	assert(q);
	if (q->_front->next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QNode* next = q->_front->next;
		free(q->_front);
		q->_front = next;
	}
}
QDataType QueueFront(Queue* q)// 获取队列头部元素
{
	assert(q);
	return q->_front->data;
}
QDataType QueueBack(Queue* q)// 获取队列队尾元素
{
	assert(q);
	return q->_back->data;
}
int QueueSize(Queue* q)// 获取队列中有效元素个数
{
	int n = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
int QueueEmpty(Queue* q)// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
{
	return q->_front == NULL ? 1 : 0;
}
void QueueDestroy(Queue* q)// 销毁队列
{
	QNode*cur = q->_front;
	while (cur)
	{
		QNode*next = cur->next;
		free(cur);
		cur = next;
	}
	q->_front = q->_back = NULL;
}