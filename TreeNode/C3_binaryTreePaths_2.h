/**
 * @moduleName: C3_binaryTreePaths_2
 * @description: 二叉树中的所有路径
 *
 * @author: 杨睿
 * @date: 2021-03-13 15:22
 **/

#include "TreeNode.h"
#include <vector>
#include <queue>

class C3_binaryTreePaths_2 {

public:
    /**
     * 二叉树中的所有路径
     * 解法二：广度搜索优先
     * 利用 c++ 提供的队列：queue
     */
    vector<string> binaryTreePaths_2(TreeNode* root) {
        vector<string> paths;
        if (root == nullptr) {
            return paths;
        }
        //c++ 提供 queue类
        queue<TreeNode*> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(to_string(root->val));

        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr) {
                paths.push_back(path);
            } else {
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + to_string(node->left->val));
                }

                if (node->right != nullptr) {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};
