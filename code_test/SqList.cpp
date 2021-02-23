#include<stdio.h>
using namespace std;
#define OK 1
#define ERROR 0
#define maxSize 100
//静态分配
typedef struct Sqlist_01{
    int data[maxSize];
    int length;
}Sqlist;

//动态分配，后续继续补充
typedef struct SqList_02
{
    int *elem; //存储空间基址
    int length; //当前长度
    int listSize;  //当前分配的存储容量
}SqList_02;

//初始化静态顺序表
int init(Sqlist_01 &L, int a[], int length){
    for (int i = 0; i < length; i++)
    {
        L.data[i] = a[i];
    }
    L.length = length;
    return OK;
}

//删除下标 i-j 之间的元素，默认 i<j<length
int deleteItem(Sqlist_01 &L, int i, int j){
    for ( ; j+1 < L.length; ){
        L.data[i] = L.data[j+1];
        i++;
        j++;
    }
    L.length = L.length - (j-i+1);
    return OK;
}

int main(){
    Sqlist_01 L;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    init(L, a, 10);
    deleteItem(L, 2, 4);
    for (int i = 0; i < L.length; i++)
    {
        printf("%d  ", L.data[i]);
    }
    printf("长度：%d", L.length);
    return OK;
}


