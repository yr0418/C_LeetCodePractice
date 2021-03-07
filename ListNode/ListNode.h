//
// Created by Alone-Wolf on 2021-03-07.
//

#ifndef C___LEETCODEPRACTICE_LISTNODE_H
#define C___LEETCODEPRACTICE_LISTNODE_H


class ListNode {

public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


#endif