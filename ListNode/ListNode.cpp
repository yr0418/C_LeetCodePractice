#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<vector>
#include "ListNode.h"
using namespace std;
#define OK 1
#define ERROR 0

//尾插法创建不带表头节点单链表，先进先出
int initNodeList_01(ListNode *&L, int a[], int length){
    ListNode *s, *r;
    L = (ListNode *)malloc(sizeof(ListNode));
    L->next = NULL;
    r = L;
    for (int i = 0; i < length; i++){
        s = (ListNode *)malloc(sizeof(ListNode));
        s->val = a[i];
        r->next = s; s->next = NULL;
        r = s;
    }
    //头结点后移一位，使得不带头结点
//    L = L->next;
    return OK;
}

//顺序打印链表
void printNodeList(ListNode *L){
    ListNode *p = L->next;
//    p = L;
    while (p){
        printf("%d  ", p->val);
        p = p->next;
    }
    printf("\n");
}

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

/**
 * 删除指定节点
 * 解法：复制下一个节点，并删除下一个节点
 */ 
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

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


int main(){
    int a[] = {0,4,6};
    int b[] = {1,3,5,7};
    ListNode *A, *B, *C;
    initNodeList_01(A, a, 3);
    int ans = findAndDelete(A, 4);
    printNodeList(A);
    printf("%d", ans);
//    bool s = isPalindrome(L);
//    cout << boolalpha << s <<endl;
    return 0;
}
