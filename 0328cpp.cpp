#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<time.h>
//��������Ϸʵ��
void Meum(){
	printf("------------------------\n");
	printf("1.������Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("------------------------\n");
}
void Game(){
	int input_num = 0;
	int random_num = rand() % 100 + 1;
	while (1){
		printf("������һ������\n");
		scanf("%d", &input_num);
		if (input_num > random_num)
		{
			printf("�¸���\n");
		}
		else if (input_num < random_num)
		{
			printf("�µ���\n");
		}
		else
		{
			printf("��ϲ�㣬�����ˣ�\n");
			break;
		}
	}
}
int main(){
	Meum();
	srand((unsigned)time(NULL));
	while(1){
		int sel = 0;
		printf("������ѡ��\n");
		scanf("%d", &sel);
		if (sel == 1)
		{
			Game();
			break;
		}
		else if (sel == 2)
		{
			break;
		}
		else
		{
			printf("����ѡ�����������ѡ��\n");
		}
	}
		system("pause");
		return 0;
}