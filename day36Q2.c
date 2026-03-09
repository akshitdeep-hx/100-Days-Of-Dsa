/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]
*/
#include <stdlib.h>

typedef struct {
    int* q;
    int f;
    int r;
    int n;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->n = k + 1;
    obj->q = (int*)malloc(sizeof(int) * obj->n);
    obj->f = 0;
    obj->r = 0;
    return obj;
}

int myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return 0;
    obj->f = (obj->f - 1 + obj->n) % obj->n;
    obj->q[obj->f] = value;
    return 1;
}

int myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return 0;
    obj->q[obj->r] = value;
    obj->r = (obj->r + 1) % obj->n;
    return 1;
}

int myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return 0;
    obj->f = (obj->f + 1) % obj->n;
    return 1;
}

int myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return 0;
    obj->r = (obj->r - 1 + obj->n) % obj->n;
    return 1;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->q[obj->f];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->q[(obj->r - 1 + obj->n) % obj->n];
}

int myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->f == obj->r;
}

int myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->r + 1) % obj->n == obj->f;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->q);
    free(obj);
}