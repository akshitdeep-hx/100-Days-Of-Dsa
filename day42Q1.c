/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;

    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

void push(Stack** top, int x) {
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->data = x;
    node->next = *top;
    *top = node;
}

int pop(Stack** top) {
    if (*top == NULL)
        return -1;

    Stack* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void reverseQueue(Queue* q) {
    Stack* stack = NULL;

    while (q->front != NULL) {
        push(&stack, dequeue(q));
    }

    while (stack != NULL) {
        enqueue(q, pop(&stack));
    }
}