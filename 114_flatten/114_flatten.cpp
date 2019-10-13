// 114_flatten.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

1
/ \
2   5
/ \   \
3   4   6
将其展开为：

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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

