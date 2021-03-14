/**
 * @moduleName: C5_merge
 * @description: 合并两个链表
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:56
 **/

#include "ListNode.h"
class C5_merge {

public:
    /**
     * 合并两个链表
     */
    void merge(ListNode* A, ListNode* B, ListNode* &C){ // C: 采取 引用 标识
        ListNode* A_next = A->next;
        ListNode* B_next = B->next;
        C = A;
        C->next = nullptr;
        ListNode* C_next = C;
        while (A_next != nullptr || B_next != nullptr){
            if (A_next != nullptr && B_next != nullptr){
                if (A_next->val < B_next->val){
                    C_next->next = A_next;
                    C_next = C_next->next;
                    A_next = A_next->next;
                } else{
                    C_next->next = B_next;
                    C_next = C_next->next;
                    B_next = B_next->next;
                }
            }
            else if (A_next == nullptr){
                C_next->next = B_next;
                break;
            }
            else {
                C_next->next = A_next;
                break;
            }
        }
    }
};

