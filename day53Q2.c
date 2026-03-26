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

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int head = 0, tail = 0;
    
    queue[tail++] = root;
    int level = 0;

    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[level] = levelSize;
        result[level] = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[head++];
            result[level][i] = curr->val;

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
        level++;
    }

    *returnSize = level;
    free(queue);
    return result;
}

struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int nodes[] = {3, 9, 20, -1, -1, 15, 7};
    int n = sizeof(nodes) / sizeof(nodes[0]);
    
    if (n == 0) return 0;

    struct TreeNode* root = newNode(nodes[0]);
    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int h = 0, t = 0;
    q[t++] = root;
    
    int i = 1;
    while (i < n) {
        struct TreeNode* curr = q[h++];
        if (i < n) {
            curr->left = newNode(nodes[i++]);
            if (curr->left) q[t++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(nodes[i++]);
            if (curr->right) q[t++] = curr->right;
        }
    }

    int returnSize;
    int* returnColumnSizes;
    int** res = levelOrder(root, &returnSize, &returnColumnSizes);

    printf("[");
    for (int j = 0; j < returnSize; j++) {
        printf("[");
        for (int k = 0; k < returnColumnSizes[j]; k++) {
            printf("%d%s", res[j][k], (k == returnColumnSizes[j] - 1) ? "" : ",");
        }
        printf("]%s", (j == returnSize - 1) ? "" : ",");
    }
    printf("]\n");

    return 0;
}