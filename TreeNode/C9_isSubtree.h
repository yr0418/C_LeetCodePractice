/**
 * @moduleName: C9_isSubtree
 * @description: 另一棵树的子树
 *
 * @author: 杨睿
 * @date: 2021-03-17 11:02
 **/

#include "TreeNode.h"
class C9_isSubtree {

public:
    /**
     * 检查两个节点是否相同，同步移动指针
     * @param s
     * @param t
     * @return
     */
    bool check(TreeNode* s, TreeNode* t){
        if (!s && !t) {
            return true;
        }
        if ((!s && t) || (s && !t) || (s->val != t->val)) {
            return false;
        }
        return check(s->left, t->left) && check(s->right, t->right);
    }

    /**
     * 深度优先搜索，检查各个结点
     * @param s
     * @param t
     * @return
     */
    bool dfs(TreeNode* s, TreeNode* t){
        if (!s ) {
            return false;
        }
        return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t){
        return dfs(s, t);
    }
};


