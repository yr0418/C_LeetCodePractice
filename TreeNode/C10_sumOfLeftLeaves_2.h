/**
 * @moduleName: C10_sumOfLeftLeaves_2
 * @description: 左叶子之和
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:28
 **/

# include "TreeNode.h"
#include <queue>
class C10_sumOfLeftLeaves_2 {

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
     * 左叶子之和，广度优先搜索
     */
    int sumOfLeftLeaves_2(TreeNode* root){
        if (!root){
            return 0;
        }
        // 利用队列存储二叉树中的节点
        queue<TreeNode*> TreeNode_Queue;
        TreeNode_Queue.push(root);
        int ans = 0;
        while (!TreeNode_Queue.empty()){
            // 取出队头
            TreeNode* node = TreeNode_Queue.front();
            TreeNode_Queue.pop();
            if (node->left){
                if (isLeafNode(node->left)){
                    ans += node->left->val;
                }
                else{
                    // 将 非叶子节点 压入队列
                    TreeNode_Queue.push(node->left);
                }
            }
            if (node->right){
                if (!isLeafNode(node->right)){
                    // 将 非叶子节点 压入队列
                    TreeNode_Queue.push(node->right);
                }
            }
        }
        return ans;
    }
};

