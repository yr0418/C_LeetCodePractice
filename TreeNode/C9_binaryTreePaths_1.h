/**
 * @moduleName: C9_binaryTreePaths_1
 * @description: 二叉树中的全部路径
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:20
 **/

#include "TreeNode.h"
#include <vector>
class C9_binaryTreePaths_1 {

public:
    // 二叉树中的所有路径，深度优先搜索，获取路径
    void getTreePath(vector<string>& paths, string path, TreeNode* root){
        if(root != nullptr){
            path += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr){
                paths.push_back(path);
            }
            else{
                path += "->";
                getTreePath(paths, path, root->left);
                getTreePath(paths, path, root->right);
            }
        }
    }

    /**
     * 二叉树中的所有路径
     * 解法一：深度优先搜索
     */
    vector<string> binaryTreePaths_1(TreeNode* root) {
        vector<string> paths;
        string path = "";
        TreeNode* node = root;
        getTreePath(paths, path, node);
        return paths;
    }
};


