/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, node->val);

    node->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

struct TreeNode* buildTree(int preorder[], int preorderSize, int inorder[], int inorderSize) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}