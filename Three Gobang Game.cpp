#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3  //使用宏定义 后期更改棋盘更简单
char chess_board[MAX_ROW][MAX_COL]; //全局变量如果不初始化也被会默认成0
void Init(){ //初始化空棋盘
	srand((unsigned int)time(0));//先设置随机种子
	for(int row = 0; row < MAX_ROW;row++)
	{
		for (int col = 0; col < MAX_COL; col++){
			chess_board[row][col] = ' ';
		}
	}
}
void PrintChessBoard(){ // 打印棋盘
	printf("----+----+----+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c |  %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("----+----+----+\n");
	}
}
void PlayerMove(){
	printf("玩家落子！\n");
	while (1){ //玩家出错可以重新输入
	printf("请输入要落子的坐标！\n");
	int row = 0;
	int col = 0;
	scanf("%d %d", &row, &col);
	if (row < 0 || row >= MAX_ROW || col < 0|| col >= MAX_COL)
	{
		printf("输入错误，请重新输入！\n");
	    continue;
	}
	if (chess_board[row][col]!= ' ')
	{
		printf("请输入的位置已经有棋子了，请重新输入！\n");
		continue;
	}
	chess_board[row][col] = 'X';
	break;
	}
}  
void ComputerMove(){
	printf("电脑落子！\n");
	while (1){
	int row = rand() % MAX_ROW;
	int col = rand() % MAX_COL;//随机数 模3
	if (chess_board[row][col]!= ' ')
	{
		continue;
	}
	chess_board[row][col] = 'O';
	break;
	}
}
int IsFull(){ //如果满了返回1 没满返回0
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++){
			if (chess_board[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char CheckWinner(){ //返回x表示玩家获胜 返回o表示电脑获胜 返回' '表示胜负未分 返回q表示和棋
	//先检测所有行
	for (int row = 0; row < MAX_ROW; row++)
	{
	if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]&&chess_board[row][0]!= ' ')
	{
		return chess_board[row][0];
		}
	}
	//检测所有列
	for (int col = 0; col < MAX_COL; col++){
		if (chess_board[0][col]!=' '&&chess_board[0][col] == chess_board[1][col]&&chess_board[0][col] == chess_board[2][col])
		{
			return chess_board[0][col];
		}
	}
	//判断对角线是否相等
	if (chess_board[0][0] == chess_board[1][1]&&chess_board[0][0] == chess_board[2][2]&& chess_board[0][0] != ' ')
	{
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0] && chess_board[0][2] != ' ')
	{
		return chess_board[0][2];
	}
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}
int main(){
	//1 创建棋盘初始化为全空格 玩家落子为X 电脑落子为O
	Init();
	//2 打印棋盘
	char winner = ' ';
	while (1){
		PrintChessBoard();
		//3 要求玩家落子，让玩家输入坐标
		PlayerMove();
		//4 判定游戏胜负  
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
		//5 要求电脑随即落子 随机落子
		ComputerMove();
		//6.判定游戏胜负
		//7.回到2循环执行
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
	}
		PrintChessBoard();
		if (winner == 'X')
		{
			printf("恭喜你赢了！\n");
		}
		else if (winner == 'O')
		{
			printf("你输了！\n");
		}
		else{
			printf("和棋了！\n");
		}
		system("pause");
		return 0;
}