#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
#include "heap.h"
#include "BinaryTree.h"

//void PrintTopK(int*a, int n, int k)
//{
//	//k������С��
//	Heap hp;
//	HeapCreat(&hp, a, k);
//	for (int i = k; i < n;++i)
//	{
//		if (HeapTop(&hp)<a[i])
//		{
//			HeapPop(&hp);
//			HeapPush(&hp, a[i]);
//		}
//	}`
//	HeapPrint(&hp);
//}

//��ֵ������ �ݹ������� �ݹ�������
//bool IsUnivalTree(struct TreeNode* root)
//{

//	if (root == NULL)
//	{
//		return true;
//	}
//	if (root->_left && root->left->val != root->val)
//	{
//		return false;
//	}
//	if (root->_right && root->right->val != root->val)
//	{
//		return false;
//	}
//	return IsUnivalTree(root->_left) && IsUnivalTree(root->_right);
//}
//��������ĸ߶�/���
//int BinaryTreeHigh(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int lefthigh = BinaryTreeHigh(root->_left);
//	int righthigh = BinaryTreeHigh(root->_right);
//	return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
//}
//int main(){
//	system("pause");
//	return 0;
//}