#pragma once
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
//	struct BinaryTreeNode* _parent;
	BTDataType _data;

}BTNode;
#include "queue.h"
//ͨ������ǰ���������������
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
void _preorderTraversal(BTNode* root, int* retA, int* pi)
{
	if (root == NULL)
		return;

	retA[(*pi)++] = root->_data;
	_preorderTraversal(root->_left, retA, pi);
	_preorderTraversal(root->_right, retA, pi);
}
int* preorderTraversal(BTNode* root, int * returnSize)
{
	int size = TreeSize(root);
	int* retA = malloc(sizeof(int)*size);
	*returnSize = size;

	int i = 0;
	_preorderTraversal(root, retA, &i);

	return retA;
}
//�������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��������k��ڵ����
int BinaryTreeKLeafSize(BTNode* root,int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeKLeafSize(root->_left, k - 1) + BinaryTreeKLeafSize(root->_right, k - 1);
}

//������������
void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	//���ú���ʽ����
	TreeDestory(root->_left);
	TreeDestory(root->_right);
	free(root);
}

//����һ���������еĽڵ�
BTNode* TreeFind(BTNode* root, char x)
{
	if (root == NULL)
		return NULL;

	if (root->_data == x)
		return root;
	//��������ҵ����ͷ��ظ���һ��
	BTNode* ret = TreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	//�������û�ҵ� �ٵ�������
	ret = TreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
//������� �ö���ʵ��
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root!= NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c", front->_data);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
		printf("\n");
	}
	QueueDestroy(&q);
}
