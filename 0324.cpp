#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
//int main(){
	        //�ж�һ�����Ƿ�Ϊ����
		/*	int num =0;
			printf("������һ��������\n");
			scanf("%d",&num);
			if (num%2==0 )
			{
				printf("%d��һ��ż����\n",num);

			}
			else{
				printf("%d��һ��������\n",num);

			}*/
	      //���1-100֮�������
			/*	int num =1 ;
				while (num<101) {
				if (num%2!=0)
				{
				printf("%d\n", num);
				}
				num++;
				}*/
	//ʹ��forѭ������Ļ�ϴ�ӡ1-10������
	/*for (int num = 1; num < 11; num++){
		printf("%d\n", num);
		};*/
	//����n�Ľ׳�
	/*int n = 0 ;
	int m = 1;
	int cout = 1;
	printf("������n:\n");
	scanf("%d", &n);
	for (m; m <= n;m++)
	{
	cout = m*cout;
	};
	printf("%d�Ľ׳�Ϊ%d\n", n, cout);*/
	//����1��+2��+3��+....+10��
	/*int n = 1;
	int m = 1;
	int cout = 1;
	int p = 0;
	while (n<11){
	for (m; m <= n; m++)
	{
	cout = m*cout;
	};
	n++;
	p = p + cout;
	}
	printf("1��+2��+3��+....+10���Ľ��Ϊ%d\n",p);*/
	//��д���룬��ʾ����ַ��������ƶ������м��� "������"
//char arr1[] = "hello i am danggui";
//char arr2[] = "##################";
//int left = 0;
//int right = strlen(arr1) - 1;
//while (left <= right)
//{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	system("cls");
//	printf("%s\n", arr2);
//	Sleep(100);
//	left++;
//	right--;
//}
	//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ���ֻ���������������룬���������ȷ����ʾ��¼
	//�ɣ�������ξ�����������˳�����
	/*int n = 0;
	for (; n < 3; n++){
	char password[1024] = { 0 };
	printf("��������λ���룺\n");
	scanf("%s", password);
	if (strcmp(password,"888888")== 0)
	{
	printf("��¼�ɹ���\n");
	break;
	}
	else
	{
	printf("��������������������룡\n");
	}
	}
	if (n == 3)
	{
	printf("��¼ʧ��\n");
	}*/
	//��һ�����飬�����Ķ����������ٸ���һ����������������������������Ƿ����
	//������ڷ���������Ӧ�±꣬�����ڷ���-1
	/*int Search(int arr[], int size, int findnum){
		for (int i = 0; i < size; i++){
		if (arr[i] == findnum)
		{
			return i;
		}	
     }
		return -1;
	}*/
	//int main(){
		/*int arr[5] = { 1, 2, 3, 4, 5 };
		int result = Search(arr, 5, 3);
		printf("result = %d\n", result);*/
/*  system("pause");
return 0;
}*/
//int BinarySearch(int arr[], int size, int findnum){    //���ֲ��� ���� ʹ�ö��ֲ�����������������
//	int left = 0;
//	int right = size - 1;
//	while (left <= right){
//		int mid = (left + right) / 2;
//		if (findnum < arr[mid])
//		{
//			right = mid - 1;
//		}else if (findnum > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main(){
//    
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int result = BinarySearch(arr, 5, 2);
//	printf("result = %d\n", result);
//	system("pause");
//	 return 0;
//  }