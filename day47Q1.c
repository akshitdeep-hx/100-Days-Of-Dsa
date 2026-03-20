/*
Problem: Height of Binary Tree

Implement the solution for this problem.

*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);


        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the tree is: %d", getHeight(root));

    return 0;
}