/**
 * @moduleName: C7_difference
 * @description: 两个集合的差集
 *
 * @author: 杨睿
 * @date: 2021-03-14 10:35
 **/

#include "ListNode.h"
class C7_difference {

public:
    void difference(ListNode* A, ListNode* B){
        ListNode* A_node = A->next;
        ListNode* B_node = B->next;
        ListNode* pre = A;
        ListNode* r;
        while (A_node != nullptr && B_node != nullptr){
            // 值相等，删除该节点，A_node 后移一位
            if (A_node->val == B_node->val){
                pre->next = A_node->next;
                r = A_node;
                A_node = A_node->next;
                free(r);
            }
            // A值 小于 B值，说明 A值 为差集中的元素，pre 后移一位，A_node后移一位
            else if (A_node->val < B_node->val){
                pre = A_node;
                A_node = A_node->next;
            }
            // A值 大于 B值，B_node 后移一位
            else{
                B_node = B_node->next;
            }
        }

    }
};
