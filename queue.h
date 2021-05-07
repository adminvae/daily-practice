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

typedef struct Queue  // ���еĽṹ
{
	QNode* _front;//ָ���ͷ
	QNode* _back;//ָ���β
}Queue;

void QueueInit(Queue* q)// ��ʼ������
{
	assert(q);
	q->_front = q->_back = NULL;
}
void QueuePush(Queue* q, QDataType data)// ��β�����
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
		q->_back->next = newnode; //����
		q->_back = newnode; //�ƶ�βָ��
	}
}
void QueuePop(Queue* q)// ��ͷ������
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
QDataType QueueFront(Queue* q)// ��ȡ����ͷ��Ԫ��
{
	assert(q);
	return q->_front->data;
}
QDataType QueueBack(Queue* q)// ��ȡ���ж�βԪ��
{
	assert(q);
	return q->_back->data;
}
int QueueSize(Queue* q)// ��ȡ��������ЧԪ�ظ���
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
int QueueEmpty(Queue* q)// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
{
	return q->_front == NULL ? 1 : 0;
}
void QueueDestroy(Queue* q)// ���ٶ���
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