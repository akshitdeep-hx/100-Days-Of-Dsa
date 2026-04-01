/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];

    int rootIdx = inStart;
    for (; rootIdx <= inEnd; rootIdx++) {
        if (inorder[rootIdx] == root->val) break;
    }

    int leftSize = rootIdx - inStart;

    root->left = build(inorder, inStart, rootIdx - 1, postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, rootIdx + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}

void printLevelOrder(struct TreeNode* root) {
    if (!root) return;
    struct TreeNode* queue[2000];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        if (curr) {
            printf("%d ", curr->val);
            queue[tail++] = curr->left;
            queue[tail++] = curr->right;
        } else {
            printf("null ");
        }
    }
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Level Order: ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}