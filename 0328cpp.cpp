#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<time.h>
//猜数字游戏实现
void Meum(){
	printf("------------------------\n");
	printf("1.进入游戏\n");
	printf("2.退出游戏\n");
	printf("------------------------\n");
}
void Game(){
	int input_num = 0;
	int random_num = rand() % 100 + 1;
	while (1){
		printf("请输入一个整数\n");
		scanf("%d", &input_num);
		if (input_num > random_num)
		{
			printf("猜高了\n");
		}
		else if (input_num < random_num)
		{
			printf("猜低了\n");
		}
		else
		{
			printf("恭喜你，猜中了！\n");
			break;
		}
	}
}
int main(){
	Meum();
	srand((unsigned)time(NULL));
	while(1){
		int sel = 0;
		printf("请输入选择：\n");
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
			printf("您的选择错误，请重新选择\n");
		}
	}
		system("pause");
		return 0;
}