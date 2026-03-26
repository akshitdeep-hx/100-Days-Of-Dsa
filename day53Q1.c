/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if(root == NULL) return;

    struct Pair q[1000];
    int front = 0, rear = 0;

    int hdArr[1000];
    int valArr[1000];
    int count = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while(front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node;
        int hd = cur.hd;

        hdArr[count] = hd;
        valArr[count] = temp->data;
        count++;

        if(temp->left != NULL) {
            q[rear].node = temp->left;
            q[rear].hd = hd - 1;
            rear++;
        }

        if(temp->right != NULL) {
            q[rear].node = temp->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }

    for(int i = -100; i <= 100; i++) {
        int printed = 0;
        for(int j = 0; j < count; j++) {
            if(hdArr[j] == i) {
                printf("%d ", valArr[j]);
                printed = 1;
            }
        }
        if(printed)
            printf("\n");
    }