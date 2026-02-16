/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include <stdio.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int col0 = 1; 
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; 
                matrix[0][j] = 0; 
            }
        }
    }

    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        
        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}


void printMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    
    int row0[] = {1, 1, 1};
    int row1[] = {1, 0, 1};
    int row2[] = {1, 1, 1};
    int* matrix[] = {row0, row1, row2};
    int matrixSize = 3;
    int matrixColSize[] = {3};

    printf("Original matrix:\n");
    printMatrix(matrix, matrixSize, matrixColSize);

    setZeroes(matrix, matrixSize, matrixColSize);

    printf("\nModified matrix:\n");
    printMatrix(matrix, matrixSize, matrixColSize);

    return 0;
}
