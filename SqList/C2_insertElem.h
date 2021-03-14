/**
 * @moduleName: C2_insertElem
 * @description: 元素插入
 *
 * @author: 杨睿
 * @date: 2021-03-14 9:52
 **/
class C2_insertElem {

public:
    void insertElem(int a[], int m, int n){
        int i ,j;
        int temp;
        for (i = m; i < (m+n) ; ++i) {
            temp = a[i];
            for (j = i-1; j >= 0 && a[j] > temp ; --j) { // 注意判定条件，当找到 第一个 j 使得 a[j] < temp 时，就应该跳出循环以记录当前 j 的值，使得 temp 插入正确的位置
                a[j+1] = a[j]; // a[j] > temp，则该元素后移一位，
            }
            a[j+1] = temp; // a[j] < temp，所以 temp 插在 a[j+1] 位置
        }
    }
};


