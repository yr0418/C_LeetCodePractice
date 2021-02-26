#include<vector>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0

//定义二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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

// 获取路径
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
 * 需先定义队列
 */
//vector<string> binaryTreePaths_2(TreeNode* root) {
//    vector<string> paths;
//    if (root == nullptr) {
//        return paths;
//    }
//    queue<TreeNode*> node_queue;
//    queue<string> path_queue;
//
//    node_queue.push(root);
//    path_queue.push(to_string(root->val));
//
//    while (!node_queue.empty()) {
//        TreeNode* node = node_queue.front();
//        string path = path_queue.front();
//        node_queue.pop();
//        path_queue.pop();
//
//        if (node->left == nullptr && node->right == nullptr) {
//            paths.push_back(path);
//        } else {
//            if (node->left != nullptr) {
//                node_queue.push(node->left);
//                path_queue.push(path + "->" + to_string(node->left->val));
//            }
//
//            if (node->right != nullptr) {
//                node_queue.push(node->right);
//                path_queue.push(path + "->" + to_string(node->right->val));
//            }
//        }
//    }
//    return paths;
//}