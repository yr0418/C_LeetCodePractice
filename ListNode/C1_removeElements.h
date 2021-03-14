/**
 * @moduleName: removeElements
 * @description: 移除链表中的指定元素
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:51
 **/

#include "ListNode.h"

class C1_removeElements {

public:
    // 移除链表中的指定元素
    ListNode* removeElements(ListNode *head, int val) {
        //哨兵节点，类似头结点
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDelete = curr;
            } else prev = curr;

            curr = curr->next;

            if (toDelete != nullptr) {
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode *ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};

