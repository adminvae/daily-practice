#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//��ŵ������
//����������A, B, C��A������N��(N > 1)����Բ��, �̵ĳߴ����µ������α�С.Ҫ�����й�������Բ������C�ˣ�
//1.ÿ��ֻ���ƶ�һ��Բ�̣�
//2.���̲��ܵ���С������.
//�ɽ�Բ����ʱ����B��, Ҳ�ɽ���A���Ƴ���Բ�������ƻ�A��, ����������ѭ���������������ƶ��Ĺ��̡�
//int step = 0; //����ȫ�ֱ���step��¼����
//void move(int i,char form,char to){
//	printf("��%d��������%d�����Ӵ�%c�ƶ���%c\n", ++step,i,form, to);
//}
//void Hanio(int n,char a,char b,char c){
//	if (n == 0)
//	{
//		return;
//	}
//	Hanio(n - 1,a,c,b); //��n-1��A���ϵ�����ͨ��C���ƶ���B��
//	move(n, a, c);  //��A���ϱ��Ϊn�������ƶ���C��
//	Hanio(n - 1, b, a, c); //�ٽ�B���ϵĵ�n-1������ͨ��A���ƶ���C��
//}
//int main(){
//	    int n;
//		printf("�����뺺ŵ�����ж��ٸ�Բ�̣�\n");
//		scanf("%d", &n);
//		Hanio(n, 'A', 'B', 'C'); //��n��Բ�̴�A��ͨ��B���ƶ���C��
//		system("pause");
//		return 0;
//}
//
//һֻ����һ�ο������� 1 ��̨�ף�Ҳ��������2 ���������������һ��n����̨���ܹ��ж�����������
//��n = 1�� ֻ��1����������n = 2ʱ����������������n = 3 ʱ����3����������n = 4ʱ����5����������n = 5ʱ����8������
//f(n)=f(n-1)+f(n-2)
//int Frog(int n){
//	if (n <= 2 && n >= 0)
//	{
//		return n;
//	}
//	else if (n < 0)
//	{
//		printf("�����������\n");
//		return n;
//	}else
//	{
//		return Frog(n - 1) + Frog(n - 2);
//	}
//}
//int main(){
//		int n;
//		printf("�������м���̨�ף�\n");
//		scanf("%d", &n);
//		int result = Frog(n);
//		if(n >= 0){ 
//			printf("������%d������\n", result);
//		}
//		system("pause");
//		return 0;
//}
//ð������ ����
void Swap(int* x,int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Bubblesort(int arr[],int size){
	for (int bound = 0; bound < size;bound++) //ʹ��bound�����黮�ֳ��������֣�[0,bound)���������䣬[bound,size)����������
	{
		for (int cur = size - 1; cur > bound; cur--){
			if (arr[cur - 1]>arr[cur])
			{
				Swap(&arr[cur - 1],&arr[cur]);
			}
		}
	}
}
int main(){
		int arr[] = { 9, 5, 2, 7 };
		int size = sizeof(arr) / sizeof(arr[0]); //������Ԫ�ظ���
		Bubblesort(arr, size);
		for (int i = 0; i < size;i++)
		{
			printf("%d",arr[i]);
		}
		system("pause");
		return 0;
}