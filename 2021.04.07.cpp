#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//int BitOneCount(int num){ //求一个整数中二进制为1的个数
//	int count = 0;
//	for (int i = 0; i < 32; i++){
//		int tmp = 0x1 << i;
//		if (tmp&num){
//			count++;
//		}
//	}
//	return count;
//}
//int main(){
//		printf("%d\n",BitOneCount(10));
//		system("pause");
//		return 0;
//}
//int Max(int x ,int y){
//	return x > y ? x : y;   //三目运算符 优先级最低
//}
//int main(){
//		printf("%d\n",Max(3,5));
//		system("pause");
//		return 0;
//}
void Swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Bubblesort(int arr[],int size){
	for (int bound = 0; bound < size;bound++)
	{
		for (int cur = size - 1; cur>bound;cur--)
		{
			if (arr[cur]<arr[cur-1])
			{
				Swap(&arr[cur], &arr[cur - 1]);
			}
		}
	}
}
int main(){
		int arr[] = { 5, 7, 9, 3 };
		int size = sizeof(arr) / sizeof(arr[0]);
		Bubblesort(arr, size);
		for (int i = 0; i < size;i++)
	{
		printf("%d", arr[i]);
	}
		printf("\n");
		system("pause");
		return 0;
}