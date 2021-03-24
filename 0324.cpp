#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//int main(){
	        //判断一个数是否为奇数
		/*	int num =0;
			printf("请输入一个整数：\n");
			scanf("%d",&num);
			if (num%2==0 )
			{
				printf("%d是一个偶数！\n",num);

			}
			else{
				printf("%d是一个奇数！\n",num);

			}*/
	      //输出1-100之间的奇数
			/*	int num =1 ;
				while (num<101) {
				if (num%2!=0)
				{
				printf("%d\n", num);
				}
				num++;
				}*/
	//使用for循环在屏幕上打印1-10的数字
	/*for (int num = 1; num < 11; num++){
		printf("%d\n", num);
		};*/
	//计算n的阶乘
	/*int n = 0 ;
	int m = 1;
	int cout = 1;
	printf("请输入n:\n");
	scanf("%d", &n);
	for (m; m <= n;m++)
	{
	cout = m*cout;
	};
	printf("%d的阶乘为%d\n", n, cout);*/
	//计算1！+2！+3！+....+10！
	/*int n = 1;
	int m = 1;
	int cout = 1;
	int p = 0;
	while (n<11){
	for (m; m <= n; m++)
	{
	cout = m*cout;
	};
	n++;
	p = p + cout;
	}
	printf("1！+2！+3！+....+10！的结果为%d\n",p);*/
	//编写代码，演示多个字符从两端移动，向中间汇聚 "撩门帘"
//char arr1[] = "hello i am danggui";
//char arr2[] = "##################";
//int left = 0;
//int right = strlen(arr1) - 1;
//while (left <= right)
//{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	system("cls");
//	printf("%s\n", arr2);
//	Sleep(100);
//	left++;
//	right--;
//}
	//编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则提示登录
	//成，如果三次均输入错误，则退出程序
	/*int n = 0;
	for (; n < 3; n++){
	char password[1024] = { 0 };
	printf("请输入六位密码：\n");
	scanf("%s", password);
	if (strcmp(password,"888888")== 0)
	{
	printf("登录成功！\n");
	break;
	}
	else
	{
	printf("密码错误，请重新输入密码！\n");
	}
	}
	if (n == 3)
	{
	printf("登录失败\n");
	}*/
	//有一个数组，里面存的都是整数，再给定一个整数，查找这个整数在数组中是否存在
	//如果存在返回整数对应下标，不存在返回-1
	/*int Search(int arr[], int size, int findnum){
		for (int i = 0; i < size; i++){
		if (arr[i] == findnum)
		{
			return i;
		}	
     }
		return -1;
	}*/
	//int main(){
		/*int arr[5] = { 1, 2, 3, 4, 5 };
		int result = Search(arr, 5, 3);
		printf("result = %d\n", result);*/
/*  system("pause");
return 0;
}*/
//int BinarySearch(int arr[], int size, int findnum){    //二分查找 升序 使用二分查找数组必须是有序的
//	int left = 0;
//	int right = size - 1;
//	while (left <= right){
//		int mid = (left + right) / 2;
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
//    
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int result = BinarySearch(arr, 5, 2);
//	printf("result = %d\n", result);
//	system("pause");
//	 return 0;
//  }