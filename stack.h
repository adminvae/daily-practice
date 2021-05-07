#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
// 支持动态增长的栈
typedef int STDataType;
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
void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}