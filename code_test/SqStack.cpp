#include<stdio.h>
using namespace std;
#define maxSize 100

typedef struct Stack{
    int data[maxSize];
    int top;
}Stack;

void init_stack(Stack &stack){
    stack.top = 0;
}

void print_stack(Stack stack){
    while (stack.top != -1){
        stack.top--;
        printf("%d  ", stack.data[stack.top]);
    }
    printf("\n");
}

int change(int x){
    int stack[maxSize];
    int top = 0;

    int result = 0; // 保存最后结果
    int i, j; //保存余数
    while (x != 0){
        j = x%2;
        stack[top] = j;
        x = x/2;
        top++;
    }
    while (top != 0){
        top--;
        i = stack[top];
        result = result*10+i;
        
    }
    return result;
}

int main(){
    Stack stack;
    int result;
    init_stack(stack);
    result = change(8);
    printf("%d", result);
}