/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* pre = curr->left;
            while (pre->right != NULL) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int nodes[] = {1, 2, 5, 3, 4, -1, 6};
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

    flatten(root);

    struct TreeNode* temp = root;
    printf("[");
    while (temp != NULL) {
        printf("%d,null%s", temp->val, (temp->right ==NULL) ? "" : ",");
        temp = temp->right;
    }
    printf("]\n");

    free(q);
    return 0;
}