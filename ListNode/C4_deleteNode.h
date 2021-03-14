/**
 * @moduleName: C4_deleteNode
 * @description: 删除指定节点
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:55
 **/

#include "ListNode.h"
class C4_deleteNode {

public:
    /**
     * 删除指定节点
     * 解法：复制下一个节点，并删除下一个节点
     */
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }

};

