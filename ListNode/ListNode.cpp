#include<stdio.h>
#include<malloc.h>
using namespace std;
#define OK 1
#define ERROR 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//尾插法创建带表头节点单链表，先进先出
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
    return OK;
}

//顺序打印链表
void printNodeList(ListNode *L){
    ListNode *p;
    p = L->next;
    while (p){
        printf("%d  ", p->val);
        p = p->next;
    }
    printf("\n");
}

// 移除链表中的指定元素
ListNode* removeElements(ListNode *head, int val) {
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

int main(){
    int a[] = {1,2,6,3,4,5,6};
    int b = 0;
    ListNode *L;
    initNodeList_01(L, a, 7);
    removeElements(L, 6);
    printNodeList(L);
    return 0;
}
