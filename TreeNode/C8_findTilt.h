/**
 * @moduleName: C8_findTilt
 * @description: 二叉树的坡度
 *
 * @author: 杨睿
 * @date: 2021-03-17 9:42
 **/

#include "TreeNode.h"
#include <algorithm>
class C8_findTilt {

public:
    int ans;  // 记录坡度之和

    int dfs(TreeNode* cur){
        if (cur == nullptr){
            return 0;
        }
        int left = dfs(cur->left);  // 左子树节点和
        int right = dfs(cur->right);  // 右子树节点和
        ans += std::abs(left-right);  // 计算当前节点坡度，并入总坡度
        return left + right + cur->val;  // 返回当前节点的 节点和
    }

    int findTilt(TreeNode* root){
        ans = 0;
        dfs(root);
        return ans;
    }
};
