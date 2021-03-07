//
// Created by Alone-Wolf on 2021-03-07.
//

#ifndef C___LEETCODEPRACTICE_TREENODE_H
#define C___LEETCODEPRACTICE_TREENODE_H


class TreeNode {

public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


#endif //C___LEETCODEPRACTICE_TREENODE_H
