/**
 * @moduleName: C7_lowestCommonAncestor_1
 * @description: 二叉搜索树的最近公共祖先
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:14
 **/

#include "TreeNode.h"
#include <vector>
class C7_lowestCommonAncestor_1 {

public:
    /**
     * 二叉搜索树的最近公共祖先
     * 解法一：两次遍历
     */
    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        TreeNode* curr;
        path_p = getPath(root, p);
        path_q = getPath(root, q);
        for(int i = 0; i < path_p.size() && i < path_q.size(); ++i){
            if(path_p[i]->val == path_q[i]->val){
                curr = path_p[i-1];
            }
            else{
                break;
            }
        }
        return curr;
    }
};
