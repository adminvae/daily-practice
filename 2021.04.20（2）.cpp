#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>

//int main(){
//	struct A { //λ��A 8�ֽ�
//		int _a : 2;
//		int _b : 5;
//		int _c : 10;
//		int _d : 30;
//	};
//	struct S //λ��c 3�ֽ�
//	{
//		char a : 3;
//		char b : 4;
//		char c : 5;
//		char d : 4;
//	};
//	printf("%d\n", sizeof(struct A));
//	printf("%d\n", sizeof(struct S));
//	system("pause");
//	return 0;
//}
//int main(){
//	union un{ //���������жϴ�˻�С�˻�
//		char c;
//		int i;
//	};
//	union un n;
//	n.i = 1;
//	if (n.c == 1)
//	{
//		printf("С�˻�\n");
//	}
//	else{
//		printf("��˻�\n");
//	}
//	system("pause");
//	return 0;
//}
//int main(){
//	int* p1 = (int*)malloc(sizeof(int)* 10);
//	int* p2 = (int*)calloc(10, sizeof(int)); //���ٿռ�ͬʱ��ʼ��
//	int* p3 = (int *)realloc(p1, sizeof(int)* 40); //��̬�ڴ�����
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//	printf("%p\n", p3);
//	free(p2);
//	free(p3);//�ͷ�p3�Ͳ������ͷ�p1
//	system("pause");
//	return 0;
//}
//ʵ����ĸ�Ĵ�Сдת�����������������
//�������������Ҫע�⡰�س���Ҳ����ĸ������Ҫ�����ա�(getchar())������ĸ��
//EOF��Ϊ�ļ�������־���ļ����������ı��ļ������ı��ļ��У����ݶ������ַ���ASCII����ֵ����ʽ��š�
//ASCII����ֵ�ķ�Χ��0~127�������ܳ���-1����˿�����EOF��Ϊ�ļ�������־��
//int main(){
//	char c;
//	while (scanf("%c", &c) != EOF){ //EOF��ʾ�ļ���������end of file�� 
//		getchar();
//		printf("%c\n", c + 32);//getchar();����;�ǴӴӱ�׼��������ȡһ���ַ������س���ʱ�˳���
//	}                          //getchar();��Զֻ�򻺴�������һ���ַ���
//	return 0;
//	system("pause");
//	return 0;
//}
//ͨ����λ����(����)ʵ��2��n�η��ļ���
int main(){
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", 1 << n);  // 1 << n�ʹ���2��n�η�
	}
	system("pause");
	return 0;
}