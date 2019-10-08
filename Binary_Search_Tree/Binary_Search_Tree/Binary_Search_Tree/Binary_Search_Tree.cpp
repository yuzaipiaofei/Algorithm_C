﻿// Binary_Search_Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>


typedef int ELEMENT_TYPE;



typedef struct TreeNode
{
	ELEMENT_TYPE data;
	struct TreeNode * left;
	struct TreeNode * right;


}TreeNode_t;

typedef struct TreeNode * node;


node find(node	 BiTree,ELEMENT_TYPE X )
{
	if (BiTree == NULL)
	{
		return NULL;
	}

	if (X > BiTree->data)
	{
		find(BiTree->right, X);
	} 
	else if (X < BiTree->data)
	{
		find(BiTree->left, X);
	}
	else
	{
		return BiTree;
	}
	

}
node find_Min(node Bitree)
{
	node p;
	if (Bitree == NULL){
		return NULL;
	}else if (Bitree->left == NULL){
		return Bitree; //return curren node
	}else{
		return	find_Min(Bitree->left);
	}

}

//尾递归 的方式查找最大元素节点
node find_Max(node Bitree)
{
	if (!Bitree){
		return NULL;
	} 
	else if(Bitree->right == NULL){
		return Bitree;
	}else{
		return find_Max(Bitree->right);
	}
}
//迭代 的方式查找最大元素节点，右子树最后面的节点就是最大值，同理左子树最小值为最左侧的节点
node find_Max1(node Bitree)
{
	if (Bitree)
	{
		while(Bitree->right !=NULL)
		{
			Bitree = Bitree->right;
		}
	}
	return Bitree;
}


node create_node(ELEMENT_TYPE X)
{
	node temp;

	temp = (node)malloc(sizeof(struct TreeNode));
	temp->data = X;
	temp->left = temp->right = NULL;
	return temp;

}
node insert(node Bitree,ELEMENT_TYPE X)
{
	node temp;
	 
	
	if (!Bitree)
	{
		temp = (node)malloc(sizeof(struct TreeNode));
		temp->data = X;
		temp->left = temp->right = NULL;
	}
	else
	{
		if (X < Bitree->data)
		{
			insert(Bitree->left, X);
		}
		else if(X > Bitree->data)
		{
			insert(Bitree->right,X);	
		}
	}
	return Bitree;
}

node Delete(node Bitree,ELEMENT_TYPE X)
{
	node temp;
	if (!Bitree)
	{
		printf("Tree is empty!\n");

	} 
	else if(X < Bitree->data)
	{
		Bitree->left = Delete(Bitree->left, X);
	}
	else if (X > Bitree->data) {
		Bitree->right = Delete(Bitree->right, X);
	}
	else
	{	// 被删除节点有左右子树同时存在的情况下，找右子树最小的节点或者左子树最大的节点替换要删除的节点，然后把那个节点删除掉。
		if (Bitree->left && Bitree->right)
		{
			temp = find_Min(Bitree->right);//find min node of right tree
			Bitree->data = temp->data;
			Bitree->right = Delete(Bitree->right, Bitree->data);
		} 
		else// 被删除节点只有一个子树，左子树或者右子树
		{
			temp = Bitree;
			if (Bitree->left == NULL)
			{
				Bitree = Bitree->right;
			} 
			else if(Bitree->right ==NULL)
			{
				Bitree = Bitree->left;
			}
			free(temp);

		}
	}
	return Bitree;
}

void Preorder_Traversal(node Bitree)
{
	if (Bitree)
	{
		printf("Preorder :%d\n", Bitree->data);
		Preorder_Traversal(Bitree->left);
		Preorder_Traversal(Bitree->right);
	}
}

int maxDepth(TreeNode root)
{
	return 0;
}



int main()
{
	node root=NULL;
	root = create_node(1);
	root = insert(root,2);
	root = insert(root,3);
	root=  insert(root, 4);
	Preorder_Traversal(root);

    return 0;
}

