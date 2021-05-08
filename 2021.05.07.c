#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
#include "queue.h"

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a; //����
	int _top; // ջ��
	int _capacity; // ����
}Stack;

void StackInit(Stack* ps)// ��ʼ��ջ
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)// ��ջ
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)// ��ջ
{
	assert(ps&&ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)// ��ȡջ��Ԫ��
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)// ��ȡջ����ЧԪ�ظ���
{
	assert(ps);
	return ps->_top;  //Ϊʲô_top����һ ��Ϊ�����±��Ǵ�0��ʼ��
}

int StackEmpty(Stack* ps)// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

void StackDestroy(Stack* ps)// ����ջ
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
////�ж����������Ƿ�ƥ�� ʹ��ջ
//int isValid(char *s)
//{
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s =='{' || *s =='(' || *s == '[')
//		{
//			StackPush(&st, *s);
//		}
//		else if (*s == '}')
//		{
//			if (StackEmpty(&st))
//			{
//				return 1;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top !='{')
//			{
//				return 1;
//			}
//		}
//		else if (*s == ')')
//		{
//			if (StackEmpty(&st))
//			{
//				return 1;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top != '(')
//			{
//				return 1;
//			}
//		}
//		else if (*s == ']')
//		{
//			if (StackEmpty(&st))
//			{
//				return 1;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if (top != '[')
//			{
//				return 1;
//			}
//		}
//		++s;
//	}
//	int ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret; //0����ƥ�� ��0����ƥ��
//}
//
////�ж����������Ƿ�ƥ�� ʹ��ָ�������Ż�
//int isValid(char *s)
//{
//	Stack st;
//	StackInit(&st);
//	char* symbols[3] = { "{}", "()", "[]" };
//	while (*s)
//	{
//		if (*s == '{' || *s == '(' || *s == '[')
//		{
//			StackPush(&st, *s);
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				return 1;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			for (int i = 0; i < 3; ++i)
//			{
//				if (*s == symbols[i][1] && top != symbols[i][0])
//				{
//					return 1;
//				}
//			}
//		}
//		++s;
//	}
//	int ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret; //0����ƥ�� ��0����ƥ��
//}
//int main(){
//	system("pause");
//	return 0;
//}

//�ö���ʵ��ջ
typedef struct{
	Queue _q1;
	Queue _q2;
}MyStack;

MyStack* mystackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);
	return st;
}
void mystackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->_q1))  //�ж�q1��û������
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}
int mystackPop(MyStack* obj)
{
	Queue* emptyQ = &obj->_q1;
	Queue* noemptyQ = &obj->_q2;
	if (!QueueEmpty(&obj->_q1))
	{
		emptyQ = &obj->_q2;
		noemptyQ = &obj->_q1;
	}
	while (QueueSize(noemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noemptyQ));
		QueuePop(noemptyQ);
	}
	QueuePop(noemptyQ);
}
int mystackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->_q1))  //�ж�q1��û������
	{
		 return QueueBack(&obj->_q1);
	}
	else
	{
		 return QueueBack(&obj->_q2);
	}
}
bool mystackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}
void mystackFree(MyStack* obj)
{
	QueueDestroy(&obj->_q1);
	QueueDestroy(&obj->_q2);
	free(obj);
}

//ѭ������
typedef struct{
	int* _a;
	int _size;
	struct MyCircularQueue* front;
	struct MyCircularQueue* back;
}MyCircularQueue;
MyCircularQueue* mycqCreate(int k){
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_a = (int*)malloc(sizeof(int)*k+1); //�ռ�
	cq->_size = k+1; //���ݸ���Ϊk
	cq->front = cq->back = 0;
}
bool mycqIsFull(MyCircularQueue* obj)
{
	if (obj->back + 1 == obj ->front)
	{
		return true;
	}
	else if ((obj->back+1 % obj->_size) == obj->front)
	{
		return true;
	}
	return false;
}
bool mycqEnQueue(MyCircularQueue* obj, int value)
{
	if (mycqIsFull(obj))
	{
		return false;
	}
	obj->_a[obj->back] = value;
	obj->back++;
	if (obj->back == obj->_size)
	{
		obj->back = 0;
	}
	return ture;
}
bool mycqDeQueue(MyCircularQueue* obj)
{
	if (mycqEmpty(obj))
	{
		return false;
	}

}