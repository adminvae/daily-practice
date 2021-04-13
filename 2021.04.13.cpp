#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//判断一个机器是大端机还是小端机
//int main(){
//	int x = 1;
//	char c = (char)x;
//	if (c == 1)
//	{
//		printf("此机器是一个小端机\n");
//	}else if (c == 0)
//	{
//		printf("此机器是一个大端机\n");
//	}
//		system("pause");
//		return 0;
//}
//输出printf(“Hello world!”)的返回值
//int main(){
//		int i = printf("Hello world!"); //注意此处不能加\n，因为这样会导致Printf的返回值中加一，应该单独换行
//		printf("\n");
//		printf("%d\n", i);
//		system("pause");
//		return 0;
//}
//依次输入一个学生的学号，以及3科（C语言，数学，英语）成绩，在屏幕上输出该学生的学号，3科成绩。
//int main(){
//	long sn = 0;
//	float score1 = 0;
//	float score2 = 0;
//	float score3 = 0;
//	scanf("%d;%f,%f,%f", &sn, &score1, &score2, &score3);
//	printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.\n", sn, score1, score2, score3);
//	system("pause");
//	//%.2f 表示只输出小数点后两位
//	return 0;
//}
//输入一个字符，用它构造一个三角形金字塔。
//int main(){
//	char i = '1';
//	scanf("%c", &i);
//	printf("    %c    \n", i);
//	printf("   %c %c   \n", i, i);
//	printf("  %c %c %c  \n", i, i, i);
//	printf(" %c %c %c %c \n", i, i, i, i);
//	printf("%c %c %c %c %c\n", i, i, i, i, i);
//	system("pause");
//	return 0;
//}
int main(){
	char a;
	scanf("%c", &a);
	for (int n = 0; n < 5; n++){
		for (int m = 0; m < 4 - n; m++){
			printf(" ");
		}
		for (int j = 0; j <= n; j++){
			printf("%c ", a);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}