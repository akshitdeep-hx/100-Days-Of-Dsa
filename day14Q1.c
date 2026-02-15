/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    int mat[100][100];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    bool isIdentity = true;
    
    for (int i = 0; i < n && isIdentity; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (mat[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                if (mat[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
    }
    
    printf("%s\n", isIdentity ? "Identity Matrix" : "Not an Identity Matrix");
    return 0;
}