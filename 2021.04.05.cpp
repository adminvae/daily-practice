#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�� ���磺 ���룺1234����� 1 2 3 4. �ݹ�
// void Print(int x){
//	if (x > 9) //x��һ����λ��
//	{
//		Print(x / 10);
//	}
//	printf("%d", x % 10);
//}
//int main(){
//    	Print(1234);
//		system("pause");
//		return 0;
//}
//��д��������������ʱ���������ַ����ĳ���
//int StrLen(char* str){
//	int len = 0;  //������ʱ���� ѭ��
//	while (str[len] != '\0'){
//		len++;
//	}
//	return len;
//}
//int main(){
//	    char str[100] = "haha";
//		int len = StrLen(str);
//		printf("len = %d\n", len);
//		system("pause");
//		return 0;
//}
//int StrLen(char str[]){
//	if (str[0] == '\0') //���ַ���
//	{
//		return 0;
//	}
//	return 1 + StrLen(str + 1); //�ݹ� �ݹ�����ִ��Ч�ʱȷǵݹ�����
//}
//int main(){
//	char str[100] = "haha";
//	int len = StrLen(str);
//	printf("len = %d\n", len);
//	system("pause");
//	return 0;
//}
//��n�Ľ׳� �ݹ�
//int Factor(int n){
//	if (n == 0)
//	{
//		return 1;
//	}
//	return n * Factor(n - 1);
//}
//int main(){
//	    printf("%d\n", Factor(5));
//		system("pause");
//		return 0;
//}
//���n��쳲�������
//int Fib(int n){
//	if ( n ==1 || n ==2)
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int Fib(int n){  //ʹ��ѭ�� ����ѭ������
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	int cur = 0;//��ʾ��i��
//	int last1 = 1; //��ʾ��i - 1��
//	int last2 = 1; //��ʾ��i - 2��
//	for (int i = 3; i <= n;i++)
//	{
//		cur = last1 + last2;
//		last2 = last1;
//		last1 = cur;
//	}
//	return cur;
//}
//int main(){
//	printf("%d\n", Fib(40));
//		system("pause");
//		return 0;
//}
//��ŵ������
//����������A, B, C��A������N��(N > 1)����Բ��, �̵ĳߴ����µ������α�С.Ҫ�����й�������Բ������C�ˣ�
//1.ÿ��ֻ���ƶ�һ��Բ�̣�
//2.���̲��ܵ���С������.
//�ɽ�Բ����ʱ����B��, Ҳ�ɽ���A���Ƴ���Բ�������ƻ�A��, ����������ѭ���������������ƶ��Ĺ��̡�
int step;
void move(int n, char form, char to){
	printf("��%d�����ѵ�%d�����ӣ���%c�ƶ���%c\n", ++step, n, form, to);
}
void Hanio(int n, char x, char y, char z){
	if (n == 0)
	{
		return;
		
	}
	else{
	Hanio(n - 1, x, z, y);
	move(n, x, z);
	Hanio(n - 1, y, x, z);
	}
}
int main(){
	int num;
	step = 0;
	printf("���������ӵ�������\n");
	scanf("%d", &num);
	Hanio(num, 'A', 'B', 'C');
	system("pause");
	return 0;
}
//������̨������