#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
//strcat的实现
//char* my_strcat(char* dst, const char*src){
//	assert(dst&&src);
//	char* ret = dst;
//	while (*dst != '\0'){
//		++dst;
//	}
//	while (*dst++ = *src++);
//	return ret;
//}
//int main(){
//		char p1[11] = "hello";
//		char*p2 = "world";
//		my_strcat(p1, p2);
//		printf("%s\n",p1);
//		system("pause");
//		return 0;
//}
//strcmp的实现
//int my_strcmp(const char* str1, const char* str2){
//	assert(str1&&str2);
//	int ret = 0;
//	unsigned char* s1 = (unsigned char*)str1;
//	unsigned char* s2 = (unsigned char*)str2;
//	while (*s1 && *s2){
//		if (*s1 > *s2)
//		{
//			return 1;
//		}else if (*s1 < *s2)
//		{
//			return -1;
//		}
//		else{
//			++s1;
//			++s2;
//		}
//	}
//	if (*s1 == '\0'&& *s2 == '\0')
//	{  
//		return 0;
//	}else if (*s1 == '\0')
//	{
//		return -1;
//	}
//	else{
//		return 1;
//	}
//	return ret;
//}
//int main(){
//	char* p1 = "hello";
//	char* p2 = "world";
//	printf("%d\n", my_strcmp(p1, p2));
//	system("pause");
//	return 0;
//}
//strstr的实现
//const char* my_strstr(const char*src,const char*sub){
//	assert(src && sub);
//	const char* srci = src;
//	const char* subi = sub;
//	while (*srci != '\0'){
//		while (*srci == *subi && *subi != '\0')
//		{
//			++srci;
//			++subi;
//		}
//		if (*subi == '\0')
//		{
//			return src;
//		}
//		else
//		{
//			subi = sub;
//			++src;
//			srci = src;
//		}
//	}
//	return NULL;
//}
//int main(){
//	char* p1 = "abcde"; //判断是否是旋转串
//	char* p2 = "cdeba";
//	char p3[11];
//	strcpy(p3, p1);
//	strcat(p3, p2);
//	if (my_strstr(p3,p2)!= NULL)
//	{
//		printf("是旋转串\n");
//	}
//	else{
//		printf("不是旋转串\n");
//	}
//	char* p4 = "aaaaa";
//	char* p5 = "aabb";
//	if (my_strstr(p4, p5) != NULL)
//	{
//		printf("是旋转串\n");
//	}
//	else{
//		printf("不是旋转串\n");
//	}
//	system("pause");
//	return 0;
//}
//memcpy的实现
//void* my_memcpy(void* dst, const void* src, size_t num){  //注意是void* 因为可能是任意类型
//	assert(dst && src);
//	char* str_dst = (char*)dst;
//	char* str_src = (char*)src;
//	for (size_t i = 0; i < num; ++i){
//		str_dst[i] = str_src[i];
//	}
//	return dst;
//}
//int main(){
//	int a1[10] = { 1, 2, 3, 4, 5 };
//	int a2[10];
//	my_memcpy(a2, a1, 10 * sizeof(int));
//	for (int i = 0; i < 10;i++)
//	{
//		printf("%d ", a2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//memmove的实现
//void* my_memmove(void* dst,const void* src,size_t num){
//	assert(dst && src);
//	char* str_dst = (char*)dst;
//	char* str_src = (char*)src;
//	if (str_src < str_dst && dst < str_src+num) //后重叠 从前往后拷贝
//	{
//		for (int i = num - 1; i >= 0; --i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//	else{  //前重叠 不重叠 从前往后拷贝
//		for (int i = 0; i < num; ++i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//	return dst;
//}
//int main(){
//	int a[10] = { 1, 2, 3, 4, 5 };
//	my_memmove(a + 3, a, 5 * sizeof(int));
//	for (size_t i = 0; i < 10;++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}