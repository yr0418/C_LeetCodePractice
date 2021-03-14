/**
 * @moduleName: C1_invertTree_1
 * @description: 反转二叉树，从根节点开始反转，从上往下递归
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:10
 **/

#include "TreeNode.h"

class C1_invertTree_1 {

public:
    //反转二叉树，从根节点开始反转，从上往下递归
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }

        TreeNode* curr = new TreeNode();
        curr = root->left;
        root->left = root->right;
        root->right = curr;
        invertTree_1(root->left);
        invertTree_1(root->right);
        return root;
    }
};

