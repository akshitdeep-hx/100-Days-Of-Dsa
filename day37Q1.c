/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int value;
    int priority;
} PQNode;

PQNode pq[MAX];
int size = 0;

void enqueue(int value, int priority) {
    int i;
    if (size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }

    for (i = size - 1; i >= 0 && pq[i].priority < priority; i--) {
        pq[i + 1] = pq[i];
    }

    pq[i + 1].value = value;
    pq[i + 1].priority = priority;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", pq[0].value);
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].priority);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(30, 4);
    enqueue(20, 3);
    enqueue(40, 1);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}