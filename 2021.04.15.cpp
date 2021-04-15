#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
//冒泡排序优化
//void Bubble_sort(int *a, int n){
//	for (int end = n; end > 0;end--)
//	{
//		int exchange = 0;
//		for (int n = 1; n < end;n++)
//		{
//			if (a[n-1]>a[n])
//			{
//				int tmp = a[n - 1];
//				a[n-1] = a[n];
//				a[n] = tmp;
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}
//int main(){
//		int a[] = { 1, 2, 3, 4, 5, 6, 7, 9, 8 };
//		int i = 0;
//		Bubble_sort(a, sizeof(a) / sizeof(a[0]));
//		for (i = 0; i<sizeof(a) / sizeof(a[0]);i++){
//			printf("%d", a[i]);
//		}
//		printf("\n");
//		system("pause");
//		return 0;
//}

//使用函数指针数组实现计算器
//int add(int a, int b) {
//	return a + b;
//}
//int sub(int a, int b) {
//	return a - b;
//}
//int mul(int a, int b) {
//	return a*b;
//}
//int divi(int a, int b) {
//	return a / b;
//}
//int main(){
//		int x;
//		int y;
//		int input = 1;
//		int ret = 0;
//		while (input){
//		printf("*************************\n");
//		printf(" 1:add           2:sub  \n");
//		printf(" 3:mul           4:divi \n");
//		printf("*************************\n");
//		printf("请选择：\n");
//		scanf("%d", &input);
//		if (input < 1 || input > 4)
//		{
//			printf("输入错误，请重新输入！\n");
//			continue;
//		}
//			int(*p[5])(int, int) = { 0, add, sub, mul, divi }; //函数指针数组
//			printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//			printf("ret = %d \n", ret);
//		}
//		system("pause");
//		return 0;
//}

//strlen的实现
//int my_strlen(const char*str){
//	assert(str != NULL);
//	int len = 0;
//	while (*str != '\0'){
//		++len;
//		++str;
//	}
//	return len;
//}
//int main(){
//		//char*p1 = "hello world"; //两种字符串赋值方式 
//		//printf("%d\n", strlen(p1));
//		char p2[] = "hello world";
//		printf("%d\n", my_strlen(p2));
//		system("pause");
//		return 0;
//}

//my_strcpy的实现
char* my_strcpy(char*dst, const char*src){
	assert(dst != NULL);
	assert(src != NULL);
	char*ret = dst;
	while (*src != '\0'){
		*dst = *src;
		++src;
		++dst;
	}
	*dst = '\0';
	return ret;
}
int main(){
	char p1[] = "hello";
	char p2[] = "world";
	//strcpy(p2, p1);//把p1的字符串拷贝到p2上
	//printf("%s\n", p2);
	my_strcpy(p2, p1);
	printf("%s\n", p2);
	system("pause");
	return 0;
}