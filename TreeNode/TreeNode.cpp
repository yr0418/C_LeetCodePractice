#include<stdio.h>
#include<malloc.h>
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
