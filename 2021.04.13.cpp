#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//�ж�һ�������Ǵ�˻�����С�˻�
//int main(){
//	int x = 1;
//	char c = (char)x;
//	if (c == 1)
//	{
//		printf("�˻�����һ��С�˻�\n");
//	}else if (c == 0)
//	{
//		printf("�˻�����һ����˻�\n");
//	}
//		system("pause");
//		return 0;
//}
//���printf(��Hello world!��)�ķ���ֵ
//int main(){
//		int i = printf("Hello world!"); //ע��˴����ܼ�\n����Ϊ�����ᵼ��Printf�ķ���ֵ�м�һ��Ӧ�õ�������
//		printf("\n");
//		printf("%d\n", i);
//		system("pause");
//		return 0;
//}
//��������һ��ѧ����ѧ�ţ��Լ�3�ƣ�C���ԣ���ѧ��Ӣ��ɼ�������Ļ�������ѧ����ѧ�ţ�3�Ƴɼ���
//int main(){
//	long sn = 0;
//	float score1 = 0;
//	float score2 = 0;
//	float score3 = 0;
//	scanf("%d;%f,%f,%f", &sn, &score1, &score2, &score3);
//	printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.\n", sn, score1, score2, score3);
//	system("pause");
//	//%.2f ��ʾֻ���С�������λ
//	return 0;
//}
//����һ���ַ�����������һ�������ν�������
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