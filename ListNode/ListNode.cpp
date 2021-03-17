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
    return 1;
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

int main(){
    int a[] = {0,4,6};
    int b[] = {1,3,5,7};
    ListNode *A, *B, *C;
//    initNodeList_01(A, a, 3);
//    printNodeList(A);
//    bool s = isPalindrome(L);
//    cout << boolalpha << s <<endl;
    return 0;
}
