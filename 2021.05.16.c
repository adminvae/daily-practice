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
//	//k个数的小堆
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

//单值二叉树 递归左子树 递归右子树
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
//求二叉树的高度/深度
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