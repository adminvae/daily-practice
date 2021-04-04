#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//比较两个数的大小
//int Max(int x, int y){
//	if (x > y)
//	{
//		return x;
//	}
//	return y;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	printf("%d与%d相比，更大的数是%d\n", a, b, Max(a, b));
//		system("pause");
//		return 0;
//}
//使用指针实现交换
//void Swap(int* x, int* y){
//	int tmp = *x;    //*x和变量a是等价的
//	*x = *y;
//	*y = tmp;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//	printf("a = %d,b = %d", a, b);
//		system("pause");
//		return 0;
//}
//判断一个数是不是素数 素数一般指质数：除了1以外，一个数要么被1整除要么对自身整除
//int ISprime(int num){
//	if (num == 0 || num ==1)      //如果num是素数 返回1 否则返回0
//	{
//		return 0;
//	}
//	for (int i = 2; i < num; i++){
//		if (num % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main(){
//	printf("%d\n",ISprime(11));
//		system("pause");
//		return 0;
//}
//判断一年是不是闰年
//int ISLeapYear(int year){
//	if (year % 100 == 0 )
//	{
//		if (year % 400 == 0)
//		{
//			return 1;
//		}else{
//			return 0;
//		}
//	}else{
//		if (year % 4 == 0)
//		{
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}
//}
//int main(){
//	int year = 2021;
//	int result = ISLeapYear(2021);
//	if (result == 1)
//	{
//		printf("%d是闰年\n", year);
//	} 
//	else
//	{
//		printf("%d不是闰年\n", year);
//	}
//		system("pause");
//		return 0;
//}
//整形有序数组的二分查找
//int binarysearch(int arr[], int size, int findnum){    
//	int left = 0;
//	int right = size - 1;
//	while (left <= right){
//	int mid = (left + right) / 2;
//		if (findnum < arr[mid])
//		{
//			right = mid - 1;
//		}else if (findnum > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main(){
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int result = binarysearch(arr,sizeof(arr)/sizeof(arr[0]),7);  //sizeof(arr)/sizeof(arr[0]）求数组长度	
//	printf("%d\n",result);
//	system("pause");
//	return 0;
//}
