/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Recursive helper to populate the result array
void traverse(struct TreeNode* root, int* res, int* size) {
    if (root == NULL) return;
    

    res[(*size)++] = root->val;
    
    
    traverse(root->left, res, size);
    
    
    traverse(root->right, res, size);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* res = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    
    traverse(root, res, returnSize);
    return res;
}