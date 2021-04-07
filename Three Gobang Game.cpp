#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3  //ʹ�ú궨�� ���ڸ������̸���
char chess_board[MAX_ROW][MAX_COL]; //ȫ�ֱ����������ʼ��Ҳ����Ĭ�ϳ�0
void Init(){ //��ʼ��������
	srand((unsigned int)time(0));//�������������
	for(int row = 0; row < MAX_ROW;row++)
	{
		for (int col = 0; col < MAX_COL; col++){
			chess_board[row][col] = ' ';
		}
	}
}
void PrintChessBoard(){ // ��ӡ����
	printf("----+----+----+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c |  %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("----+----+----+\n");
	}
}
void PlayerMove(){
	printf("������ӣ�\n");
	while (1){ //��ҳ��������������
	printf("������Ҫ���ӵ����꣡\n");
	int row = 0;
	int col = 0;
	scanf("%d %d", &row, &col);
	if (row < 0 || row >= MAX_ROW || col < 0|| col >= MAX_COL)
	{
		printf("����������������룡\n");
	    continue;
	}
	if (chess_board[row][col]!= ' ')
	{
		printf("�������λ���Ѿ��������ˣ����������룡\n");
		continue;
	}
	chess_board[row][col] = 'X';
	break;
	}
}  
void ComputerMove(){
	printf("�������ӣ�\n");
	while (1){
	int row = rand() % MAX_ROW;
	int col = rand() % MAX_COL;//����� ģ3
	if (chess_board[row][col]!= ' ')
	{
		continue;
	}
	chess_board[row][col] = 'O';
	break;
	}
}
int IsFull(){ //������˷���1 û������0
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
char CheckWinner(){ //����x��ʾ��һ�ʤ ����o��ʾ���Ի�ʤ ����' '��ʾʤ��δ�� ����q��ʾ����
	//�ȼ��������
	for (int row = 0; row < MAX_ROW; row++)
	{
	if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]&&chess_board[row][0]!= ' ')
	{
		return chess_board[row][0];
		}
	}
	//���������
	for (int col = 0; col < MAX_COL; col++){
		if (chess_board[0][col]!=' '&&chess_board[0][col] == chess_board[1][col]&&chess_board[0][col] == chess_board[2][col])
		{
			return chess_board[0][col];
		}
	}
	//�ж϶Խ����Ƿ����
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
	//1 �������̳�ʼ��Ϊȫ�ո� �������ΪX ��������ΪO
	Init();
	//2 ��ӡ����
	char winner = ' ';
	while (1){
		PrintChessBoard();
		//3 Ҫ��������ӣ��������������
		PlayerMove();
		//4 �ж���Ϸʤ��  
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
		//5 Ҫ������漴���� �������
		ComputerMove();
		//6.�ж���Ϸʤ��
		//7.�ص�2ѭ��ִ��
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
	}
		PrintChessBoard();
		if (winner == 'X')
		{
			printf("��ϲ��Ӯ�ˣ�\n");
		}
		else if (winner == 'O')
		{
			printf("�����ˣ�\n");
		}
		else{
			printf("�����ˣ�\n");
		}
		system("pause");
		return 0;
}