/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int sumOfLeftLeavesHelper(struct Node* root, bool isLeft) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return isLeft ? root->val : 0;
    }

    return sumOfLeftLeavesHelper(root->left, true) + 
           sumOfLeftLeavesHelper(root->right, false);
}

int sumOfLeftLeaves(struct Node* root) {
    return sumOfLeftLeavesHelper(root, false);
}

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Sum of left leaves: %d\n", sumOfLeftLeaves(root));

    return 0;
}