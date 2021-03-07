#include<vector>
#include<string>
#include "TreeNode.h"
#include <queue>
using namespace std;
#define OK 1
#define ERROR 0

//反转二叉树，从根节点开始反转，从上往下递归
TreeNode* invertTree_1(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
        
    TreeNode* curr = new TreeNode();
    curr = root->left;
    root->left = root->right;
    root->right = curr;
    invertTree_1(root->left);
    invertTree_1(root->right);
    return root;
}

//反转二叉树，从叶子节点开始反转，从下往上递归
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

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


/**
 * 判断是否为叶子节点
 * @param node
 * @return
 */
bool isLeafNode(TreeNode* node){
    return !node->left && !node->right;
}

/**
 * 深度优先搜索二叉树，返回各左叶子节点值
 * @param root
 * @return
 */
int dfs(TreeNode* node){
    int ans = 0;
    if (node->left){
        ans += isLeafNode(node->left)? node->left->val: dfs(node->left);
    }
    if (node->right && !isLeafNode(node->right)){
        ans += dfs(node->right);
    }
    // return ans，添加返回值，使得递归能正常实现累加操作
    return ans;
}
/**
 * 左叶子之和，深度优先搜索
 * @param root
 * @return
 */
int sumOfLeftLeaves_1(TreeNode* root) {
    return root? dfs(root):0;
}

/**
 * 左叶子之和，广度优先搜索
 */
int sumOfLeftLeaves_2(TreeNode* root){
    if (!root){
        return 0;
    }
    // 利用队列存储二叉树中的节点
    queue<TreeNode*> TreeNode_Queue;
    TreeNode_Queue.push(root);
    int ans = 0;
    while (!TreeNode_Queue.empty()){
        // 取出队头
        TreeNode* node = TreeNode_Queue.front();
        TreeNode_Queue.pop();
        if (node->left){
            if (isLeafNode(node->left)){
                ans += node->left->val;
            }
            else{
                // 将 非叶子节点 压入队列
                TreeNode_Queue.push(node->left);
            }
        }
        if (node->right){
            if (!isLeafNode(node->right)){
                // 将 非叶子节点 压入队列
                TreeNode_Queue.push(node->right);
            }
        }
    }
    return ans;
}
