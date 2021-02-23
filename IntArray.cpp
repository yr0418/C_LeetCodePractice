#include<stdio.h>
using namespace std;
#define maxSize 100
//移动数组元素，将数组元素中的非零元移动至数组前端
void move_element(int a[], int n){
    int i,j,temp;
    i = j = 0;
    for ( i = 0; i < n; i++){
        if (a[i] != 0){
            if (i != j){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            j++;
        }
    }
}

//递归计算数组中的最大值，K 表示数组长度。
int max_element(int a[], int k){
    int max;
    if (k == 1){
        max = a[k-1];  //递归式1：当 k=0 时，最大值即 a[0]
    }
    else{
        max = max_element(a, k-1); // 递归式2：当 k!=0 时，获取从 0-(k-1) 中的最大值，与 a[k]比较
        if (a[k-1] > max){
            max = a[k-1];
        }
    }
    return max;
}

//递归计算数组所有元素的和，k 表示数组长度。
int sum_element(int a[], int k){
    if (k == 1){
        return a[k-1];
    }
    else{
        return a[k-1] + sum_element(a, k-1);
    }
}

//移动元素，以a[n-1]为参考量，将数组分为两部分
int change_element(int a[], int n){
    int i=0, j=n-1, temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    temp = a[i];
    while (i != j){
        while (i<j && a[j]<temp) --j;
        if (i<j){
            /* code */
            a[i] = a[j];
            ++i;
        }
        while (i<j && a[i]>temp) ++i;
        if (i<j){
            /* code */
            a[j] = a[j];
            j--;
        }
    }
    a[i] = temp;
}

//输出二维数组中，既是行最小值，又是列最小值的数及其坐标
int print_min(int a[][3], int m, int n){
    int i,j,min,minj,flag;
    for ( i = 0; i < m; i++){
        /* 初始化 第 i 行 中的最小值 */
        min = a[i][0];
        minj = 0;
        for ( j = 0; j < n; j++){
            /* 选出该行的最小值 */
            if (a[i][j] < min){
                /* minj 记录该最小值的列号 */
                min = a[i][j];
                minj = j;
            }
        }
        for ( j = 0; j < m; j++){
            flag = 1;
            //判断是否为列最小
            if (a[j][minj] < a[i][minj]){
                /* code */
                flag = 0;
                break;
            }
        } 
        if (flag == 1){
            /* code */
            printf("%d, [%d][%d]", min, i, minj);
        }
        
    }
    
}

void print_array(int a[], int n){
    int i;
    for ( i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[3][3];
    int i,j;
    for ( i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
        {
            a[i][j] = 3*i+j;
        }
    }
    print_min(a,3,3);
    return 0;
}