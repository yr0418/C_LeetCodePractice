#include "SqList.h"
#include<stdio.h>

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
    int a[] = {1,2,3,4,5,6};
    SqList L;
    init(L, a, 6);
    printSqList(L);
    moveP(L, 2);
    printSqList(L);
}