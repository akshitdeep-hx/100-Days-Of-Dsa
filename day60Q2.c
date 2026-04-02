/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown
*/
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cameraCount;

int dfs(struct TreeNode* node) {
    if (node == NULL) {
        return 2;
    }

    int left = dfs(node->left);
    int right = dfs(node->right);

    if (left == 0 || right == 0) {
        cameraCount++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameraCount = 0;
    if (dfs(root) == 0) {
        cameraCount++;
    }
    return cameraCount;
}