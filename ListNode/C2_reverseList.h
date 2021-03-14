/**
 * @moduleName: C2_reverseList
 * @description: 反转单链表
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:53
 **/

#include "ListNode.h"

class C2_reverseList {

public:
    //反转单链表
    ListNode* reverseList(ListNode* head) {
        //哨兵节点，类似头结点
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *right, *curr;
        curr = sentinel->next;
        sentinel->next = nullptr;
        while (curr != nullptr){
            right = curr->next;
            curr->next = sentinel->next;
            sentinel->next = curr;
            curr = right;
        }
        head = sentinel->next;
        delete sentinel;
        return head;
    }
};



