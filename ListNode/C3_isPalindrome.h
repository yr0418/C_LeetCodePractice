/**
 * @moduleName: C3_isPalindrome
 * @description: 判断链表是否回文
 *
 * @author: 杨睿
 * @date: 2021-03-14 8:54
 **/

#include "ListNode.h"
#include <vector>

class C3_isPalindrome {

public:
    /**
     * 判断链表是否回文
     * 解法：借助数组
     *
     */
    bool isPalindrome(ListNode* head) {
        ListNode *curr = head;
        vector<int> nums;
        while(curr != nullptr){
            nums.push_back(curr->val);
            curr = curr->next;
        }
        for (int i = 0, j = (int)nums.size()-1; i < j; ++i, --j){
            if(nums[i] != nums[j]){
                return false;
            }
        }
        return true;

    }
};

