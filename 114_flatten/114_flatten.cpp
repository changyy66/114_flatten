// 114_flatten.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
����һ����������ԭ�ؽ���չ��Ϊ����

���磬����������

1
/ \
2   5
/ \   \
3   4   6
����չ��Ϊ��

1
\
2
\
3
\
4
\
5
\
6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include "stdafx.h"

/**
* Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* flattenHelper(TreeNode* root)
	{
		if (!root)return NULL;
		TreeNode* left = NULL, *right = NULL;
		if (root->left)
		{
			left = flattenHelper(root->left);
		}
		if (root->right)
		{
			right = flattenHelper(root->right);
		}
		root->left = NULL;
		if (left)
		{
			root->right = left;
			while (left->right)
			{
				left = left->right;
			}
			left->right = right;
		}
		else
		{
			root->right = right;
		}
		return root;
	}

	void flatten(TreeNode* root) {
		flattenHelper(root);
	}
};

int main()
{
    return 0;
}

