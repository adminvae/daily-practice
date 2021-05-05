#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
//原地移除数组中所有元素val 要求时间复杂度为O(N)空间复杂度为O(1)
//int removeelement(int*nums,int numszise,int val)
//{
//	int src = 0;
//	int dst = 0;
//	while (src < numszise)
//	{
//		if (nums[src]!= val)
//		{
//			nums[dst] = nums[src];
//			src++;
//			dst++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	for (int i = 0; i < dst;i++)
//	{
//		printf("%d", nums[i]);
//	}
//	printf("\n");
//	return dst;
//}
//int main(){
//	int a[10] = { 1, 2, 2, 3, 4, 5, 6, 7, 2, 8 };
//	removeelement(a,10,2);
//	system("pause");
//	return 0;
//}

//给定一个排序数组，在原地删除（空间复杂度O(1)）重复出现的元素，返回移除后数组的新长度，不使用额外的数组空间
//int removeduplicates(int* nums, int numsize)
//{
//	int src1 = 0;
//	int src2 = 1;
//	int dst = 0;
//	while (src2 < numsize)
//	{
//		nums[dst] = nums[src1];
//		++dst;
//		if (nums[src1]!=nums[src2])
//		{
//			++src1;
//			++src2;
//		}
//		else
//		{
//			while (nums[src1] == nums[src2] && src2 < numsize)
//			{
//				++src2;
//			}
//			src1 = src2;
//			++src2;
//		}
//	}
//	if (src1 < numsize)
//	{
//		nums[dst] = nums[src1];
//		++dst;
//	}
//	for (int i = 0; i < dst; i++)
//	{
//		printf("%d", nums[i]);
//	}
//	printf("\n");
//	return dst;
//}
//int main(){
//	int a[10] = { 1, 2, 2, 3, 4, 5, 6, 7, 7, 8 };
//	removeduplicates(a,10);
//	system("pause");
//	return 0;
//}

//两个有序数组的合并
//void merge(int* nums1,int nums1size,int m, int*nums2, int nums2size,int n)
//{
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = m + n - 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//	while (end1 >= 0)
//	{
//		nums1[end--] = nums1[end1--];
//	}
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}
//int main(){
//	int nums1[6] = { 1, 2, 3 };
//	int nums2[3] = { 2, 5, 6 };
//	system("pause");
//	return 0;
//}