#include<stdio.h>
#define maxSize 100
using namespace std;
typedef struct SqQueue{
    int data[maxSize];
    int front;
    int rear;
}SqQueue;

//初始化循环队列，设置队头队尾指向同一位置。
void init_queue(SqQueue &queue){
    queue.front = queue.rear = 0;
}

//判断队列是否为空。
int is_empty_queue(SqQueue queue){
    if (queue.front == queue.rear){
        return 1;
    }
    else{
        return 0;
    }
}

//进队算法，队尾进队。使 front 指向 队头元素，rear 指向 队尾元素的下一位
int enQueue_rear(SqQueue &queue, int x){
    //判断 队满，注意，队满的标志即 队尾的下一位置是队头。
    if (((queue.rear +1)%maxSize) == queue.front){
        return 0;
    }
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear +1) % maxSize;
    return 1;
}

//进队算法，队头进队。使 front 指向 队头元素，rear 指向 队尾元素的下一位
int enQueue_front(SqQueue &queue, int x){
    //判断队满
    if (((queue.rear+1) % maxSize) == queue.front){
        return 0;
    }

    //队头进队，移动队头指针时注意，要避免 front 出现负值。
    queue.front = (queue.front-1 +maxSize) % maxSize;
    queue.data[queue.front] = x;
    return 1;
}

//出队算法，队头出队。使 front 指向 队头元素，rear 指向 队尾元素的下一位
int deQueue_front(SqQueue &queue, int &x){
    //判断 队空
    if (queue.rear == queue.front){
        return 0;
    }
    x = queue.data[queue.front];
    queue.front = (queue.front +1) % maxSize;
    return 1;
}

//出队算法，队尾出队。使 front 指向 队头元素，rear 指向 队尾元素的下一位
int deQueue_rear(SqQueue &queue, int &x){
    //判断 队空
    if (queue.rear == queue.front){
        return 0;
    }
    //队尾出队，同样要注意，防止 队尾出现 负值。
    queue.rear = (queue.rear -1 +maxSize) % maxSize;
    x = queue.data[queue.rear];
    return 1;
}