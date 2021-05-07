#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
// ֧�ֶ�̬������ջ
typedef int STDataType;
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