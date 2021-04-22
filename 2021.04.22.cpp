#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
//#define CASE break;case //在写case语句时自动把break补上
//#define DEBUG_PRINT  printf("file:%s\t line:%d\t \
//							 date:%s\t time:%s\n",\
//							 __FILE__, __LINE__, \
//							 __DATE__, __TIME__) //如果定义的过长 可以分几行写 除最后一行外 每行后面加一个\ (续写符)
////实现一个MAX宏函数
//#define MAX(a,b) (((a)>(b))?(a):(b))  //要注意加上括号 否则符号优先级会产生问题
//#define PRINT(FORMAT, VALUE) printf("the value of " #VALUE "  is "FORMAT "\n", VALUE); //#的作用
//#define ADD_PRINTF(num,value) sum ## num += value; //##的作用 把位于它旁边的两个符号合成为一个符号
//void f(int x, int y){
//	printf("%d %d\n", x, y);
//}
//int main(){
	//DEBUG_PRINT;
	//int x1 = 1,x2 = 2;
	//printf("%d\n", MAX(x1, x2));
	//int i = 10;
	//PRINT("%d", i + 3);
	//double sum5 = 5.0;
	//ADD_PRINTF(5, 10);
//	int i = 1;
//	f(i++, i++); //函数传参顺序，可以从左到右也可以从右到左 跟编译平台有关 所以可能是21或12
//	printf("%d\n", i); //i = 3
//	system("pause");
//	return 0;
//} 
