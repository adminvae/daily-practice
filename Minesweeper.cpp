#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define Max_Row 9
#define Max_Col 9
#define Max_Mine_Count 10
char mine_map[Max_Row][Max_Col]; //��ʾÿ��λ���ǲ�����
char show_map[Max_Row][Max_Col]; //��ʾÿ��λ����Χ�м�����
void Init(){
	//�ȶ�show_map��ʼ������ÿ��λ�ö���ɡ�*��
	for (int row = 0; row < Max_Row;row++)
	{
		for (int col = 0; col < Max_Col;col++)
		{
			show_map[row][col] = '*';
		}
	}
	//��mine_map��ʼ�� �Ȱ�ÿ��λ�ö���� ��0���ٰ����λ����ɡ�1��
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
void PrintMap(char the_map[Max_Row][Max_Col]){ //����������ܴ�ӡshow_mapҲ�ܴ�ӡmine_map
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
			if (r < 0 || r >= Max_Row || c < 0 || c >= Max_Col) // ����Ƿ��±�
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
	//1.��ʼ����ͼ 
	Init();
	int count = 0;
	//2.��ӡ��ͼshow_map
	while (1){
	PrintMap(show_map);
	//3.������������� ����ĳ��λ��
	printf("������Ҫ������λ�ã�row col����");
	int row = 0;
	int col = 0;
	scanf("%d %d", &row, &col);
	if (row < 0 || row>= Max_Row || col <0 || col >= Max_Col)
	{
		printf("���������������������룡\n");
		continue;
	}
	if (show_map[row][col] != '*')
	{
		printf("���λ���Ѿ����������������룡\n");
		continue;
	}
	//4.�ж��Ƿ����
	if (mine_map[row][col] == '1')
	{
		printf("Game over!\n");
		PrintMap(mine_map);
		break;
	}
	//5.�ж���Ϸ�Ƿ�ʤ��
	++count; //ʹ��count��¼�Ѿ������Ĳ����׵ĸ���
	if (count == Max_Row * Max_Col - Max_Mine_Count)
	{
		printf("You Win!\n");
		PrintMap(mine_map);
		break;
	}
	//6.����show_map
	UpdateShowMap(mine_map,show_map,row,col);
	}
		system("pause");
		return 0;
}