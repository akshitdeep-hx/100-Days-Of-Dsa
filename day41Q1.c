/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct myQueue {
    int currSize;
    Node* front;
    Node* rear;
} myQueue;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

myQueue* createQueue() {
    myQueue* q = (myQueue*)malloc(sizeof(myQueue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->currSize = 0;
    return q;
}

int isEmpty(myQueue* q) {
    return q->front == NULL;
}

void enqueue(myQueue* q, int data) {
    Node* node = newNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->currSize++;
}

int dequeue(myQueue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    Node* temp = q->front;
    int removedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->currSize--;
    return removedData;
}