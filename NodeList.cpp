#include<stdio.h>
#include<malloc.h>
using namespace std;
#define OK 1
#define ERROR 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

//尾插法创建带表头节点单链表，先进先出
int initNodeList_01(LNode *&L, int a[], int length){
    LNode *s, *r;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    for (int i = 0; i < length; i++){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s; s->next = NULL;
        r = s;
    }
    return OK;
}

//头插法创建带表头节点单链表，先进后出
int initNodeList_02(LNode *&L, int a[], int length){
    LNode *s;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < length; i++){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        //关键代码，头插法即向单链表中的指定位置插入节点，与单链表的插入算法一致。
        s->next = L->next;
        L->next = s; 
    }
    return OK;
}

//删除重复节点
int deleteNode(LNode *L){
    LNode *p, *q;
    p = L->next;
    while (p->next != NULL){
        q = p->next;
        if (p->data == q->data){
            p->next = q->next;
            free(q);
        }
        else{
            p = p->next;
        }
    }
    return OK;
}

//删除一个最小值节点
int deleteMin(LNode *L){
    LNode *min, *minpre=L, *pre=L;
    while (pre->next != NULL){
        if (minpre->next->data > pre->next->data){
            minpre = pre;
            pre = pre->next;
        }else{
            pre = pre->next;
        }
    }
    min = minpre->next;
    minpre->next = min->next;
    free(min);
    return OK;
}

//单链表的逆置：利用头插法逆置
int reversel(LNode *L){
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p != NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return OK;
}

//拆分单链表A，使得A中只包含奇数，B中只包含偶数
int splitList(LNode *LA, LNode *&LB){
    LB = (LNode *)malloc(sizeof(LNode));
    LNode *a = LA, *b = LB;
    while (a->next != NULL){
        if((a->next->data)%2 == 0){
            b->next = a->next;
            a->next = a->next->next;
            b = b->next;
            b->next = NULL;
        }
        else{
            a = a->next;
        }
    }
    return OK;
}

//打印单链表
void printNodeList(LNode *L){
    LNode *p;
    p = L->next;
    while (p){
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

//逆序打印单链表，当单链表带头结点时，最后会打印单链表头结点的data地址。
void print_Node_reversel(LNode *L){
    if (L != NULL){
        print_Node_reversel(L->next);
        printf("%d  ", L->data);
    }
}

//倒数第K个数
int findElem(LNode *L, int k){
    LNode *p = L->next, *K_elem = L;
    int i = 1;
    //防止出现 K 大于链表长度的情况。
    while (p != NULL){
        p = p->next;
        ++i;
        if (i > k){
            K_elem = K_elem->next;
        }
    }
    if (K_elem == L){
        return 0;
    }
    else{
        printf("%d ", K_elem->data);
        return 1;
    }
}


int main(){
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b = 0;
    LNode *L, *L1;
    initNodeList_02(L, a, 10);
    printNodeList(L);
    findElem(L, 11);
    return 0;
}
