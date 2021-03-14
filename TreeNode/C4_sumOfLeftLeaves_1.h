/**
 * @moduleName: C4_sumOfLeftLeaves_1
 * @description: 左叶子之和
 * @author: 杨睿
 * @date: 2021-03-13 15:26
 **/

#include "TreeNode.h"

class C4_sumOfLeftLeaves_1 {

public:
    /**
     * 判断是否为叶子节点
     * @param node
     * @return
     */
    bool isLeafNode(TreeNode* node){
        return !node->left && !node->right;
    }

    /**
     * 深度优先搜索二叉树，返回各左叶子节点值
     * @param root
     * @return
     */
    int dfs(TreeNode* node){
        int ans = 0;
        if (node->left){
            ans += isLeafNode(node->left)? node->left->val: dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)){
            ans += dfs(node->right);
        }
        // return ans，添加返回值，使得递归能正常实现累加操作
        return ans;
    }

    /**
     * 左叶子之和，深度优先搜索
     * @param root
     * @return
     */
    int sumOfLeftLeaves_1(TreeNode* root) {
        return root? dfs(root):0;
    }
};

