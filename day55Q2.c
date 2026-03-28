/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * 100);
    int count = 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[head++];
            if (i == levelSize - 1) {
                result[count++] = curr->val;
            }
            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    *returnSize = count;
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
    int nodes[] = {1, 2, 3, -1, 5, -1, 4};
    int n = sizeof(nodes) / sizeof(nodes[0]);

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
    int* res = rightSideView(root, &returnSize);

    printf("[");
    for (int j = 0; j < returnSize; j++) {
        printf("%d%s", res[j], (j == returnSize - 1) ? "" : ",");
    }
    printf("]\n");

    free(res);
    free