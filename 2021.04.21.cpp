#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>

//int main(){
	//FILE* fp = fopen("test.c", "w");
	//fseek(fp, 5, SEEK_SET);
	//fseek(fp, 0, SEEK_END);//ָ�����һ��λ��
	//printf("%d", ftell(fp));//�����ļ���С
//int main() {   //�ı��ļ�
//		int c; // ע�⣺int����char��Ҫ����EOF
//		FILE* fp = fopen("test.txt", "r");
//		if (!fp) {
//			perror("File opening failed");
//			return EXIT_FAILURE;
//		}
//		//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//		while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//		{
//			putchar(c);
//		}
//		//�ж���ʲôԭ�������
//		if (ferror(fp))
//			puts("I/O error when reading");
//		else if (feof(fp))
//			puts("End of file reached successfully");
//		fclose(fp);
//		system("pause");
//		return 0;
//	}
enum { SIZE = 5 };  //�������ļ�
int main() {
	double a[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
	fwrite(a, sizeof(*a), SIZE, fp); // д double ������
	fclose(fp);
	fp = fopen("test.bin", "rb");
	// �� double ������
	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}
	if (feof(fp))
		printf("Error reading test.bin: unexpected end of file\n");
	else if (ferror(fp)) {
		perror("Error reading test.bin");
	}
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}
