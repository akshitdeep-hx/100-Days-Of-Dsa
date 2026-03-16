/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]
*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    traverse(root->left, result, index);
    result[(*index)++] = root->val;
    traverse(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    int index = 0;
    traverse(root, result, &index);
    
    return result;
}