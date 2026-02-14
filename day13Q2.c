/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
*/

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    if (result == NULL) {
        return NULL; 
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        
        for (int col = left; col <= right; col++) {
            result[index++] = matrix[top][col];
        }
        top++;

        
        for (int row = top; row <= bottom; row++) {
            result[index++] = matrix[row][right];
        }
        right--;

        
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[index++] = matrix[bottom][col];
            }
            bottom--;
        }

        
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[index++] = matrix[row][left];
            }
            left++;
        }
    }

    return result;
}


int main() {
    int matrixSize = 3;
    int matrixColSize[] = {3, 3, 3};
    
    int** matrix = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * matrixColSize[i]);
    }
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    int returnSize;
    int* spiral = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    printf("Spiral order: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", spiral[i], (i == returnSize - 1) ? "" : ",");
    }
    printf("]\n");

    
    free(spiral);
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
