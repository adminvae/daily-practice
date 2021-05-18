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
//通过树的前序遍历创建二叉树
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
//二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
//二叉树叶子节点个数
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
//二叉树第k层节点个数
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

//二叉树的销毁
void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	//采用后序方式销毁
	TreeDestory(root->_left);
	TreeDestory(root->_right);
	free(root);
}

//查找一个二叉树中的节点
BTNode* TreeFind(BTNode* root, char x)
{
	if (root == NULL)
		return NULL;

	if (root->_data == x)
		return root;
	//如果左树找到，就返回给上一层
	BTNode* ret = TreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	//如果左树没找到 再到右树找
	ret = TreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
//层序遍历 用队列实现
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
