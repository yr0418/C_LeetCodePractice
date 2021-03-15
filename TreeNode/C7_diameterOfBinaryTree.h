/**
 * @moduleName: C7_diameterOfBinaryTree
 * @description: 获取二叉树的最大直径
 *
 * @author: 杨睿
 * @date: 2021-03-15 14:56
 **/

#include "TreeNode.h"
#include "algorithm"

class C7_diameterOfBinaryTree {

public:
    int d_node;  //记录当前最大直径

    /**
     * 深度优先遍历二叉树
     * @param cur
     * @return
     */
    int depth(TreeNode* cur){
        if (cur == nullptr){
            return 0;
        }
        int L = depth(cur->left);  // 当前节点 左子树 深度
        int R = depth(cur->right);  // 当前节点 右子树 深度
        d_node = max(d_node, (L+R+1));  // 更新最大直径
        return max(L,R)+1;  // 返回当前节点能达到的最大深度
    }

    /**
     * 获取二叉树的最大直径
     * @param root
     * @return
     */
    int diameterOfBinaryTree(TreeNode* root) {
        d_node = 1;
        depth(root);
        return d_node-1;
    }
};
