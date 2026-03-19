/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[2000];
    int head = 0;
    int tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelCount = tail - head;
        (*returnColumnSizes)[*returnSize] = levelCount;
        result[*returnSize] = (int*)malloc(levelCount * sizeof(int));

        for (int i = 0; i < levelCount; i++) {
            struct TreeNode* node = queue[head++];
            result[*returnSize][i] = node->val;

            if (node->left) {
                queue[tail++] = node->left;
            }
            if (node->right) {
                queue[tail++] = node->right;
            }
        }
        (*returnSize)++;
    }

    return result;
}