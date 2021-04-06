#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//汉诺塔问题
//有三根杆子A, B, C。A杆上有N个(N > 1)穿孔圆盘, 盘的尺寸由下到上依次变小.要求按下列规则将所有圆盘移至C杆：
//1.每次只能移动一个圆盘；
//2.大盘不能叠在小盘上面.
//可将圆盘临时置于B杆, 也可将从A杆移出的圆盘重新移回A杆, 但都必须尊循上述两条规则。求移动的过程。
//int step = 0; //设置全局变量step记录步数
//void move(int i,char form,char to){
//	printf("第%d步，将第%d个盘子从%c移动到%c\n", ++step,i,form, to);
//}
//void Hanio(int n,char a,char b,char c){
//	if (n == 0)
//	{
//		return;
//	}
//	Hanio(n - 1,a,c,b); //第n-1个A柱上的盘子通过C柱移动到B柱
//	move(n, a, c);  //将A柱上编号为n的盘子移动到C柱
//	Hanio(n - 1, b, a, c); //再将B柱上的第n-1个盘子通过A柱移动到C柱
//}
//int main(){
//	    int n;
//		printf("请输入汉诺塔中有多少个圆盘：\n");
//		scanf("%d", &n);
//		Hanio(n, 'A', 'B', 'C'); //将n个圆盘从A柱通过B柱移动到C柱
//		system("pause");
//		return 0;
//}
//
//一只青蛙一次可以跳上 1 级台阶，也可以跳上2 级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//当n = 1， 只有1中跳法；当n = 2时，有两种跳法；当n = 3 时，有3种跳法；当n = 4时，有5种跳法；当n = 5时，有8种跳法
//f(n)=f(n-1)+f(n-2)
//int Frog(int n){
//	if (n <= 2 && n >= 0)
//	{
//		return n;
//	}
//	else if (n < 0)
//	{
//		printf("您的输入错误\n");
//		return n;
//	}else
//	{
//		return Frog(n - 1) + Frog(n - 2);
//	}
//}
//int main(){
//		int n;
//		printf("请输入有几级台阶：\n");
//		scanf("%d", &n);
//		int result = Frog(n);
//		if(n >= 0){ 
//			printf("青蛙有%d种跳法\n", result);
//		}
//		system("pause");
//		return 0;
//}
//冒泡排序 升序
void Swap(int* x,int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Bubblesort(int arr[],int size){
	for (int bound = 0; bound < size;bound++) //使用bound把数组划分成两个部分，[0,bound)已排序区间，[bound,size)待排序区间
	{
		for (int cur = size - 1; cur > bound; cur--){
			if (arr[cur - 1]>arr[cur])
			{
				Swap(&arr[cur - 1],&arr[cur]);
			}
		}
	}
}
int main(){
		int arr[] = { 9, 5, 2, 7 };
		int size = sizeof(arr) / sizeof(arr[0]); //求数组元素个数
		Bubblesort(arr, size);
		for (int i = 0; i < size;i++)
		{
			printf("%d",arr[i]);
		}
		system("pause");
		return 0;
}