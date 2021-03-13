#include <vector>
#include <string>
#include "TreeNode.h"
#include <queue>


using namespace std;

#define OK 1
#define ERROR 0


// 二叉搜索树，获取到达指定节点的路径
vector<TreeNode*> getPath(TreeNode* root, TreeNode* target){
    vector<TreeNode*> path;
    TreeNode* curr = root;
    while(curr->val != target->val){
        path.push_back(curr);
        if(curr->val < target->val){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    path.push_back(curr);
    return path;
}












