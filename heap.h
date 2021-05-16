#pragma once
typedef int HpDataType;
typedef struct Heap
{
	HpDataType _a;
	size_t _size;
	size_t _capacity;
}Heap;
void AdjustDown(HpDataType*a, size_t n, HpDataType root);
void HeapCreat(Heap* hp,HpDataType *a, size_t n);

void HeapPush(Heap* hp, HpDataType x);

void HeapPop(Heap* hp);

HpDataType HeapTop(Heap* hp);