#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>

//int main(){
//	struct A { //位段A 8字节
//		int _a : 2;
//		int _b : 5;
//		int _c : 10;
//		int _d : 30;
//	};
//	struct S //位段c 3字节
//	{
//		char a : 3;
//		char b : 4;
//		char c : 5;
//		char d : 4;
//	};
//	printf("%d\n", sizeof(struct A));
//	printf("%d\n", sizeof(struct S));
//	system("pause");
//	return 0;
//}
//int main(){
//	union un{ //利用联合判断大端机小端机
//		char c;
//		int i;
//	};
//	union un n;
//	n.i = 1;
//	if (n.c == 1)
//	{
//		printf("小端机\n");
//	}
//	else{
//		printf("大端机\n");
//	}
//	system("pause");
//	return 0;
//}
//int main(){
//	int* p1 = (int*)malloc(sizeof(int)* 10);
//	int* p2 = (int*)calloc(10, sizeof(int)); //开辟空间同时初始化
//	int* p3 = (int *)realloc(p1, sizeof(int)* 40); //动态内存扩容
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//	printf("%p\n", p3);
//	free(p2);
//	free(p3);//释放p3就不用再释放p1
//	system("pause");
//	return 0;
//}
//实现字母的大小写转换。多组输入输出。
//多组输入过程中要注意“回车”也是字母，所以要“吸收”(getchar())掉该字母。
//EOF作为文件结束标志的文件，必须是文本文件。在文本文件中，数据都是以字符的ASCII代码值的形式存放。
//ASCII代码值的范围是0~127，不可能出现-1，因此可以用EOF作为文件结束标志。
//int main(){
//	char c;
//	while (scanf("%c", &c) != EOF){ //EOF表示文件结束符（end of file） 
//		getchar();
//		printf("%c\n", c + 32);//getchar();的用途是从从标准输入流读取一个字符，读回车符时退出。
//	}                          //getchar();永远只向缓存中输入一个字符。
//	return 0;
//	system("pause");
//	return 0;
//}
//通过移位运算(左移)实现2的n次方的计算
int main(){
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", 1 << n);  // 1 << n就代表2的n次方
	}
	system("pause");
	return 0;
}