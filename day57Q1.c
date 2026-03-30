/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if(left == NULL && right == NULL)
        return true;

    if(left == NULL || right == NULL)
        return false;

    if(left->val != right->val)
        return false;

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    return isMirror(root->left, root->right);
}