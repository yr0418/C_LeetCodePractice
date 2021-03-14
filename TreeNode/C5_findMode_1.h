/**
 * @moduleName: findMode
 * @description: BST 中的众数，暴力破解
 *
 * @author: 杨睿
 * @date: 2021-03-13 14:51
 **/

#include <unordered_map>
#include <algorithm>
#include <vector>
#include "TreeNode.h"

class C5_findMode_1 {

public:

    /**
     * 二叉搜索树中的众数
     * 深度优先搜索二叉树，获取各个值的数量
     * @param mode_map
     * @param cur
     */
    void search_BST(unordered_map<int, int>& mode_map, TreeNode* cur){
        if (cur == NULL){
            return;
        }
        mode_map[cur->val]++;
        search_BST(mode_map, cur->left);
        search_BST(mode_map, cur->right);
    }

    /**
     * 定义排序规则
     * @param a
     * @param b
     * @return
     */
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    /**
     * 二叉搜索树中的众数
     * 解法一：深度优先搜索
     * @param root
     * @return
     */
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> mode_map;
        search_BST(mode_map, root);
        int max_count = 0;
        vector<pair<int, int>>vec(mode_map.begin(), mode_map.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        for (int i=1; i<vec.size(); i++){
            if (vec[i].second == vec[0].second){
                result.push_back(vec[i].first);
            }
        }
        return result;
    }
};

