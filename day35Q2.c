/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 
*/

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

int isEmptyStack1() {
    return top1 == -1;
}

void push(int x) {
    stack1[++top1] = x;
}

int pop() {
    // Move all elements to stack2
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int removed = stack2[top2--];

    // Move back to stack1
    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return removed;
}

int peek() {
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int front = stack2[top2];

    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return front;
}

int empty() {
    return top1 == -1;
}