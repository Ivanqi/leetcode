#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false -1

typedef struct {
    int head;   // 队头下标
    int tail;   // 队尾下标
    int max;    // 队列最大容量
    int *array; // 数据存储区
} MyCircularQueue;


/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));

    if (obj == NULL) {
        return NULL;
    }

    obj->max = k;
    obj->tail = k;
    obj->head = 0;
    obj->array = (int *)malloc(sizeof(int) * k);

    if (obj->array == NULL) {
        return NULL;
    }

    return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL || obj->array == NULL) {
        return false;
    }

    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    obj->array[(obj->head++) % obj->max] = value;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL) {
        return false;
    }

    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->tail++;
    
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->array[obj->tail % obj->max];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->array[(obj->head - 1) % obj->max];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return ((unsigned int)(obj->tail - obj->head) == obj->max);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return (obj->head == obj->tail);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->array == NULL) {
        return;
    }

    free(obj);
    free(obj->array);
}

int main () {
    
    MyCircularQueue *obj = myCircularQueueCreate(3);

    printf("enQueue: %d\n", myCircularQueueEnQueue(obj, 1));
    printf("enQueue: %d\n", myCircularQueueEnQueue(obj, 2));
    printf("enQueue: %d\n", myCircularQueueEnQueue(obj, 3));
    printf("enQueue: %d\n", myCircularQueueEnQueue(obj, 4));

    // printf("Rear: %d \n", myCircularQueueDeQueue(obj));
    // printf("Rear: %d \n", myCircularQueueDeQueue(obj));
    // printf("Rear: %d \n", myCircularQueueDeQueue(obj));
    // printf("Rear: %d \n", myCircularQueueDeQueue(obj));
    // printf("Rear: %d \n", myCircularQueueRear(obj));

    printf("isFull: %d \n", myCircularQueueIsFull(obj));

    printf("deQueue:%d \n", myCircularQueueDeQueue(obj));

    printf("Rear: %d \n", myCircularQueueRear(obj));

    printf("enQueue: %d \n", myCircularQueueEnQueue(obj, 4));   

    printf("Rear: %d \n", myCircularQueueRear(obj));
}