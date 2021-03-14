/**
 * @moduleName: C1_invertTree_2
 * @description: //反转二叉树，从叶子节点开始反转，从下往上递归
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:12
 **/

#include "TreeNode.h"

class C1_invertTree_2 {

public:
    //反转二叉树，从叶子节点开始反转，从下往上递归
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

