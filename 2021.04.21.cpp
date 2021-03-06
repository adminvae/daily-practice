#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>

//int main(){
	//FILE* fp = fopen("test.c", "w");
	//fseek(fp, 5, SEEK_SET);
	//fseek(fp, 0, SEEK_END);//指向最后一个位置
	//printf("%d", ftell(fp));//计算文件大小
//int main() {   //文本文件
//		int c; // 注意：int，非char，要求处理EOF
//		FILE* fp = fopen("test.txt", "r");
//		if (!fp) {
//			perror("File opening failed");
//			return EXIT_FAILURE;
//		}
//		//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//		while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//		{
//			putchar(c);
//		}
//		//判断是什么原因结束的
//		if (ferror(fp))
//			puts("I/O error when reading");
//		else if (feof(fp))
//			puts("End of file reached successfully");
//		fclose(fp);
//		system("pause");
//		return 0;
//	}
enum { SIZE = 5 };  //二进制文件
int main() {
	double a[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
	fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
	fclose(fp);
	fp = fopen("test.bin", "rb");
	// 读 double 的数组
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
