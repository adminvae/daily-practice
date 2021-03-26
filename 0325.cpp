#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
int BinarySearch(int arr[],int size,int findnum)
{
	int left = 0;
	int right = size - 1;
	while (left <= right){
		int mid = (right + left) / 2;
		if (findnum < arr[mid])
		{
			right = mid - 1;
		}
		else if(findnum > arr[mid])
		{
			left = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int main(){
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int result = BinarySearch(arr, 8, 7);
	printf("result = %d \n",result);
		system("pause");
		return 0;
}