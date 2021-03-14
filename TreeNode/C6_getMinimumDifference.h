/**
 * @moduleName: C6_getMinimumDifference
 * @description: 二叉搜索树的最小绝对差
 *
 * @author: 杨睿
 * @date: 2021-03-14 13:53
 **/

#include "TreeNode.h"
#include <algorithm>
class C6_getMinimumDifference {

public:

    /**
     * 深度优先搜索，中序遍历
     * @param node
     * @param pre
     * @param ans
     */
    void dfs(TreeNode* node, int& pre, int& ans){
        if (node == nullptr){
            return;
        }
        dfs(node->left, pre, ans);
        //第一个节点，更新 pre 的值
        if (pre == -1){
            pre = node->val;
        } else{
            // 后续遍历，更新 最小绝对差
            int abs = node->val - pre;
            min = min < abs? min: abs;
            pre = node->val;  // pre 后移
        }
        dfs(node->right, pre, ans);
    }


    int getMinimumDifference(TreeNode* root){
        int pre = -1;
        int ans = 0;
        dfs(root, pre, ans);
        return ans;
    }
};
