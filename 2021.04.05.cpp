#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//接受一个整型值（无符号），按照顺序打印它的每一位。 例如： 输入：1234，输出 1 2 3 4. 递归
// void Print(int x){
//	if (x > 9) //x是一个多位数
//	{
//		Print(x / 10);
//	}
//	printf("%d", x % 10);
//}
//int main(){
//    	Print(1234);
//		system("pause");
//		return 0;
//}
//编写函数不允许创建临时变量，求字符串的长度
//int StrLen(char* str){
//	int len = 0;  //创建临时变量 循环
//	while (str[len] != '\0'){
//		len++;
//	}
//	return len;
//}
//int main(){
//	    char str[100] = "haha";
//		int len = StrLen(str);
//		printf("len = %d\n", len);
//		system("pause");
//		return 0;
//}
//int StrLen(char str[]){
//	if (str[0] == '\0') //空字符串
//	{
//		return 0;
//	}
//	return 1 + StrLen(str + 1); //递归 递归代码的执行效率比非递归代码低
//}
//int main(){
//	char str[100] = "haha";
//	int len = StrLen(str);
//	printf("len = %d\n", len);
//	system("pause");
//	return 0;
//}
//求n的阶乘 递归
//int Factor(int n){
//	if (n == 0)
//	{
//		return 1;
//	}
//	return n * Factor(n - 1);
//}
//int main(){
//	    printf("%d\n", Factor(5));
//		system("pause");
//		return 0;
//}
//求第n个斐波那契数
//int Fib(int n){
//	if ( n ==1 || n ==2)
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int Fib(int n){  //使用循环 避免循环计算
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	int cur = 0;//表示第i项
//	int last1 = 1; //表示第i - 1项
//	int last2 = 1; //表示第i - 2项
//	for (int i = 3; i <= n;i++)
//	{
//		cur = last1 + last2;
//		last2 = last1;
//		last1 = cur;
//	}
//	return cur;
//}
//int main(){
//	printf("%d\n", Fib(40));
//		system("pause");
//		return 0;
//}
//汉诺塔问题
//有三根杆子A, B, C。A杆上有N个(N > 1)穿孔圆盘, 盘的尺寸由下到上依次变小.要求按下列规则将所有圆盘移至C杆：
//1.每次只能移动一个圆盘；
//2.大盘不能叠在小盘上面.
//可将圆盘临时置于B杆, 也可将从A杆移出的圆盘重新移回A杆, 但都必须尊循上述两条规则。求移动的过程。
int step;
void move(int n, char form, char to){
	printf("第%d步，把第%d个盘子，从%c移动到%c\n", ++step, n, form, to);
}
void Hanio(int n, char x, char y, char z){
	if (n == 0)
	{
		return;
		
	}
	else{
	Hanio(n - 1, x, z, y);
	move(n, x, z);
	Hanio(n - 1, y, x, z);
	}
}
int main(){
	int num;
	step = 0;
	printf("请输入盘子的数量：\n");
	scanf("%d", &num);
	Hanio(num, 'A', 'B', 'C');
	system("pause");
	return 0;
}
//青蛙跳台阶问题