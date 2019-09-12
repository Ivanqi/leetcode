#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

typedef struct {
    int *array;
    int head;
    int tail;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
    obj->array = (int *)malloc(sizeof(int) * MAXSIZE);
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

void enqueue(RecentCounter* obj, int data) {
    if (obj == NULL) {
        return;
    }
    obj->array[obj->tail++] = data;
}

int dequeue(RecentCounter* obj) {
    if (obj == NULL) {
        return -1;
    }
    obj->head++;
}

int size(RecentCounter* obj) {
    if (obj == NULL) {
        return -1;
    }
    return obj->tail - obj->head;
}

int recentCounterPing(RecentCounter* obj, int t) {
    if (obj == NULL) {
        return -1;
    }

    enqueue(obj, t);
    while (obj->array[obj->head] < t - 3000) {
        dequeue(obj);
    }
    return size(obj);
}

void recentCounterFree(RecentCounter* obj) {
    if (obj == NULL) {
        return;
    }
    if (obj->array == NULL) {
        return;
    }
    free(obj->array);
    free(obj);
}

int main () {

    RecentCounter *R = recentCounterCreate();

    printf("RecentCounter val: %d\n", recentCounterPing(R, 1));
    printf("RecentCounter val: %d\n", recentCounterPing(R, 100));
    printf("RecentCounter val: %d\n", recentCounterPing(R, 3001));
    printf("RecentCounter val: %d\n", recentCounterPing(R, 3002));
}

