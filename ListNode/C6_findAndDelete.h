/**
 * @moduleName: C6_findAndDelete
 * @description: 删除指定结点
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:58
 **/

#include "ListNode.h"
class C6_findAndDelete {

public:
    /**
     * 删除指定结点
     * @param C：链表
     * @param x：指定值
     * @return
     */
    int findAndDelete(ListNode* C, int x){
        ListNode* pre = C;
        ListNode* node = C->next;
        while (node != nullptr){
            if (node->val == x){
                pre->next = node->next;
                free(node);
                return 1;
            } else{
                pre = node;
                node = node->next;
            }
        }
        return 0;
    }
};



