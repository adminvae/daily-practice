#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//�Ƚ��������Ĵ�С
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
//	printf("%d��%d��ȣ����������%d\n", a, b, Max(a, b));
//		system("pause");
//		return 0;
//}
//ʹ��ָ��ʵ�ֽ���
//void Swap(int* x, int* y){
//	int tmp = *x;    //*x�ͱ���a�ǵȼ۵�
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
//�ж�һ�����ǲ������� ����һ��ָ����������1���⣬һ����Ҫô��1����Ҫô����������
//int ISprime(int num){
//	if (num == 0 || num ==1)      //���num������ ����1 ���򷵻�0
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
//�ж�һ���ǲ�������
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
//		printf("%d������\n", year);
//	} 
//	else
//	{
//		printf("%d��������\n", year);
//	}
//		system("pause");
//		return 0;
//}
//������������Ķ��ֲ���
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
//	int result = binarysearch(arr,sizeof(arr)/sizeof(arr[0]),7);  //sizeof(arr)/sizeof(arr[0]�������鳤��	
//	printf("%d\n",result);
//	system("pause");
//	return 0;
//}
