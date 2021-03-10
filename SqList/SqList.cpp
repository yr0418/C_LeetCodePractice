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

/**
 * 逆置问题1
 * 将 长度为 n 的数组的前端 k 个元素 逆序后 移动到数组后端
 * 原数组中数据不丢失，其余元素的位置无关紧要
 * @param L 数组
 * @param k 前端 K 位
 * @param left 数组起始位置，0
 * @param right 数组末尾
 */
void reverse(SqList &L, int left, int right, int k){
    int tem;
    for (int i = left, j = right; i <left+k && i < j ; ++i, --j) {
        tem = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = tem;
    }
}

/**
 * 逆置问题2
 * 将 长度为 n 的数组的前端 k 个元素 保持 原序 移动到数组后端
 * 原数组中数据不丢失，其余元素的位置无关紧要
 *
 * 解法：先将 前端 k个元素 逆置，在逆置整个数组
 * @param L 数组
 * @param k 前端 k 位
 */
void moveToEnd(SqList &L, int k){
    int right = L.length;
    reverse(L, 0, k-1, k);
    reverse(L, 0, right-1, k);
}

/**
 * 逆置问题3
 * 数组中的元素循环左移 p 个位置
 *
 * 解法：先将 0 ~ p-1 位置的元素逆置，再将 p ~ n-1 位置的元素逆置，再将整个数组逆置
 * @param L
 * @param p
 */
void moveP(SqList &L, int p){
    int n = L.length;
    reverse(L, 0, p-1, p);
    reverse(L, p, n-1, n-p);
    reverse(L, 0, n-1, n);
}

int main(){
    int a[] = {1,2,3,4,5,6};
    SqList L;
    init(L, a, 6);
    printSqList(L);
    moveP(L, 2);
    printSqList(L);
}