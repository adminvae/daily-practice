#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define Max_Row 9
#define Max_Col 9
#define Max_Mine_Count 10
char mine_map[Max_Row][Max_Col]; //表示每个位置是不是雷
char show_map[Max_Row][Max_Col]; //表示每个位置周围有几个雷
void Init(){
	//先对show_map初始化，把每个位置都填成‘*’
	for (int row = 0; row < Max_Row;row++)
	{
		for (int col = 0; col < Max_Col;col++)
		{
			show_map[row][col] = '*';
		}
	}
	//对mine_map初始化 先把每个位置都填成 ‘0’再把随机位置填成‘1’
	for (int row = 0; row < Max_Row; row++)
	{
		for (int col = 0; col < Max_Col; col++)
		{
			mine_map[row][col] = '0';
		}
	}
	srand((unsigned int)time(0));
	int mine_count = 0;
	while (1){
		int row = rand() % Max_Row;
		int col = rand() % Max_Col;
		if (mine_map[row][col] == '1')
		{
			continue;
		}
		mine_map[row][col] = '1';
		mine_count++;
		if (mine_count >= Max_Mine_Count)
		{
			break;
		}
	}
}
void PrintMap(char the_map[Max_Row][Max_Col]){ //这个函数既能打印show_map也能打印mine_map
	for (int row = 0; row < Max_Row; row++)
	{
		for (int col = 0; col < Max_Col; col++)
		{
			printf("%c", the_map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(char mine_map[Max_Row][Max_Col],char show_map[Max_Row][Max_Col],int row,int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r == row && c == col)
			{
				continue;
			}
			if (r < 0 || r >= Max_Row || c < 0 || c >= Max_Col) // 检验非法下标
			{
				continue;
			}
			if (mine_map[r][c] == '1')
			{
				count++;
			}
		}
	}
	show_map[row][col] = '0' + count;
}
int main(){
	//1.初始化地图 
	Init();
	int count = 0;
	//2.打印地图show_map
	while (1){
	PrintMap(show_map);
	//3.让玩家输入坐标 翻开某个位置
	printf("请输入要翻开的位置（row col）：");
	int row = 0;
	int col = 0;
	scanf("%d %d", &row, &col);
	if (row < 0 || row>= Max_Row || col <0 || col >= Max_Col)
	{
		printf("您的输入有误，请重新输入！\n");
		continue;
	}
	if (show_map[row][col] != '*')
	{
		printf("这个位置已经翻开，请重新输入！\n");
		continue;
	}
	//4.判断是否踩雷
	if (mine_map[row][col] == '1')
	{
		printf("Game over!\n");
		PrintMap(mine_map);
		break;
	}
	//5.判断游戏是否胜利
	++count; //使用count记录已经翻开的不是雷的格子
	if (count == Max_Row * Max_Col - Max_Mine_Count)
	{
		printf("You Win!\n");
		PrintMap(mine_map);
		break;
	}
	//6.更新show_map
	UpdateShowMap(mine_map,show_map,row,col);
	}
		system("pause");
		return 0;
}