#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<assert.h>
#include "BinaryTree.h"

////��ת������
//BTNode* invertTree(BTNode* root)
//{
//	if (root == NULL)
//		return NULL;
//
//	BTNode* tmp = root->_left;
//	root->_left = root->_right;
//	root->_right = tmp;
//
//	invertTree(root->_left);
//	invertTree(root->_right);
//	return root;
//}

////�ж��Ƿ�Ϊ��ͬ����
//bool IsSameTree(BTNode* p, BTNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//
//    if (p == NULL || q == NULL)
//		return false;
//
//	if (p->_data != q->_data)
//		return false;
//
//	return IsSameTree(p->_left, q->_left) && IsSameTree(p->_right, q->_right);
//}

////����Գƶ�����
//bool _IsSymmetric(BTNode* p,BTNode* q)
//{
//
//	if (p == NULL && q == NULL)
//		return true;
//
//	if (p == NULL || q == NULL)
//		return false;
//
//	if (p->_data != q->_data)
//	{
//		return false;
//	}
//
//	return _IsSymmetric(p->_left, q->_right) && _IsSymmetric(p->_right, q->_left);
//}
//bool IsSymmetric(BTNode* root)
//{
//	if (root == NULL)
//		return true;
//
//	_IsSymmetric(root->_left, root->_right);
//}

////����ǰ�����
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
//}
//void _preorderTraversal(BTNode* root, int* retA,int* pi)
//{
//	if (root == NULL)
//		return;
//
//	retA[(*pi)++] = root->_data;
//	_preorderTraversal(root->_left, retA, pi);
//	_preorderTraversal(root->_right, retA, pi);
//}
//int* preorderTraversal(BTNode* root, int * returnSize)
//{
//	int size = TreeSize(root);
//	int* retA = malloc(sizeof(int)*size);
//	*returnSize = size;
//
//	int i = 0;
//	_preorderTraversal(root, retA, &i);
//
//	return retA;
//}

////�ж��Ƿ���һ���߶�ƽ��Ķ�������ÿһ���ڵ�����Ҹ߶Ȳ�����1��
//int Depth(BTNode* root)  //����߶�
//{
//	if (root == NULL)
//		return 0;
//
//	int leftdepth = Depth(root->_left);
//	int rightdepth = Depth(root->_right);
//
//	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
//}
//bool IsBalanced(BTNode* root)
//{
//	if (root == NULL)
//		return true;
//
//	int leftdepth = Depth(root->_left);
//	int rightdepth = Depth(root->_right);
//
//	return abs(leftdepth - rightdepth) < 2 && IsBalanced(root->_left) &&IsBalanced(root->_right);
//
//}

////����������
//BTNode* Rebulid(char* a,int* pi)
//{
//	if (a[*pi] = '#')
//	{
//		return NULL;
//	}
//	else{
//		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//		root->_data = a[*pi];
//		++(*pi);
//		root->_left = Rebulid(a, pi);
//		++(*pi);
//		root->_right = Rebulid(a, pi);
//
//		return root;
//	}
//}
//void Inorder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Inorder(root->_left);
//	printf("%c", root->_data);
//	Inorder(root->_right);
//}
//int main(){
//	char a[100];
//	scanf("%s", a);
//	int i = 0;
//	BTNode* root = Rebulid(a, i);
//	Inorder(root);
//	system("pause");
//	return 0;
//}