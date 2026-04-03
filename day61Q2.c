/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
*/
#include <stdio.h>
#include <stdlib.h>

void dfs(int** isConnected, int* visited, int n, int i) {
    for (int j = 0; j < n; j++) {
        
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, visited, n, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            visited[i] = 1; 
            dfs(isConnected, visited, n, i);
        }
    }

    free(visited);
    return count;
}