#include "SqList.h"
#include<stdio.h>
#include "C2_insertElem.h"

using namespace std;
#define OK 1
#define ERROR 0

//初始化静态顺序表
int init(SqList &L, int a[], int length){
    for (int i = 0; i < length; i++)
    {
        L.data[i] = a[i];
    }
    L.length = length;
    return 1;
}

//打印静态链表
void printSqList(SqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("%d  ", L.data[i]);
    }
    printf("\n");
}


int main(){
    int a[] = {1,3,5,2,4,6};
    SqList L;
    C2_insertElem demo;
    demo.insertElem(a, 3, 3);
    for (int i = 0; i <6 ; ++i) {
        printf("%d  ", a[i]);
    }
//    printSqList(L);
}