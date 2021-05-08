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
	STDataType* _a; //数组
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

void StackInit(Stack* ps)// 初始化栈
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)// 入栈
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

void StackPop(Stack* ps)// 出栈
{
	assert(ps&&ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)// 获取栈顶元素
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)// 获取栈中有效元素个数
{
	assert(ps);
	return ps->_top;  //为什么_top不减一 因为数组下标是从0开始的
}

int StackEmpty(Stack* ps)// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

void StackDestroy(Stack* ps)// 销毁栈
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
////判断括号类型是否匹配 使用栈
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
//	return ret; //0代表匹配 非0代表不匹配
//}
//
////判断括号类型是否匹配 使用指针数组优化
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
//	return ret; //0代表匹配 非0代表不匹配
//}
//int main(){
//	system("pause");
//	return 0;
//}

//用队列实现栈
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
	if (!QueueEmpty(&obj->_q1))  //判断q1里没有数据
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
	if (!QueueEmpty(&obj->_q1))  //判断q1里没有数据
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

//循环队列
typedef struct{
	int* _a;
	int _size;
	struct MyCircularQueue* front;
	struct MyCircularQueue* back;
}MyCircularQueue;
MyCircularQueue* mycqCreate(int k){
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_a = (int*)malloc(sizeof(int)*k+1); //空间
	cq->_size = k+1; //数据个数为k
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