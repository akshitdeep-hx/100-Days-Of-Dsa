/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} CircularQueue;

CircularQueue* createQueue(int n) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->size = n;
    q->arr = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if (q->count == q->size) return;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    q->count++;
}

void dequeue(CircularQueue* q) {
    if (q->count == 0) return;
    q->front = (q->front + 1) % q->size;
    q->count--;
}

void display(CircularQueue* q) {
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % q->size]);
    }
}

int main() {
    int n, m, x;
    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    free(q->arr);
    free(q);
    return 0;
}