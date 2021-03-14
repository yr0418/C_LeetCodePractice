/**
 * @moduleName: C2_lowestCommonAncestor_2
 * @description: ${description}
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:16
 **/

#include "TreeNode.h"
class C2_lowestCommonAncestor_2 {

public:
    /**
     * 二叉搜索树的最近公共祖先
     * 解法二：一次遍历
     */
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }

};

