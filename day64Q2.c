/*

Code


Testcase
Testcase
Test Result
994. Rotting Oranges
Solved
Medium
Topics
premium lock icon
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/
#include <stdlib.h>

typedef struct {
    int r, c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int freshCount = 0;
    int minutes = 0;

    Point* queue = (Point*)malloc(rows * cols * sizeof(Point));
    int head = 0, tail = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[tail++] = (Point){i, j};
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (head < tail && freshCount > 0) {
        int currentLevelSize = tail - head;
        minutes++;

        for (int i = 0; i < currentLevelSize; i++) {
            Point p = queue[head++];

            for (int j = 0; j < 4; j++) {
                int nr = p.r + dr[j];
                int nc = p.c + dc[j];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    queue[tail++] = (Point){nr, nc};
                }
            }
        }
    }

    free(queue);

    return (freshCount == 0) ? minutes : -1;
}