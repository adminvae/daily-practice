#pragma once
#include <stdio.h>
#include<assert.h>
#include <stdlib.h>
typedef int SLDatatype;
typedef struct Seqlist
{
	SLDatatype* a;
	size_t size;
	size_t capacity;
}Seqlist;
//�����ݵĹ��� ��ɾ�Ĳ�
void SeqListInit(Seqlist* ps);
void SeqListDestory(Seqlist* ps);
void SeqListPrint(Seqlist* ps);
void SeqListPushBack(Seqlist* ps, SLDatatype x); //β��
void SeqListPushFront(Seqlist* ps, SLDatatype x); // ͷ��
void SeqListPopBack(Seqlist* ps); //βɾ
void SeqListPopFront(Seqlist* ps); // ͷɾ
int SeqListFind(Seqlist*ps, SLDatatype x);//˳������
void SeqListInsert(Seqlist*ps, size_t pos, SLDatatype x);//˳�����pos������x
void SeqListErase(Seqlist*ps, size_t pos);//ɾ��posλ�õ�ֵ