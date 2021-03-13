/**
 * @moduleName: findMode_2
 * @description: BST 中的众数，中序遍历
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:05
 **/
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "TreeNode.h"

class findMode_2 {

public:
    vector<int> answer;
    int base, count, maxCount;

    /**
     * BST，更新标识
     * @param x
     */
    void update(int x){
        if (x == base){
            count++;
        } else{
            base = x;
            count = 1;
        }
        if (count == maxCount){
            answer.push_back(base);
        }
        if (count > maxCount){
            maxCount = count;
            answer = vector<int>{base};
        }
    }

    /**
     * 深度优先搜索，中序遍历二叉树
     * @param cur
     */
    void dfs(TreeNode* cur){
        if (!cur){
            return;
        }
        dfs(cur->left);
        update(cur->val);
        dfs(cur->right);
    }

    /**
     * BST 中的众数
     * 中序遍历
     * @param root
     * @return
     */
    vector<int> findMode(TreeNode* root){
        dfs(root);
        return answer;
    }
};

