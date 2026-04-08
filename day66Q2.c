/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/
#include <stdbool.h>
#include <stdlib.h>

bool hasCycle(int u, int** adj, int* adjSizes, bool* visited, bool* recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (hasCycle(v, adj, adjSizes, visited, recStack)) return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* adjSizes = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        adjSizes[prerequisites[i][1]]++;
    }

    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSizes[i] * sizeof(int));
    }

    int* fillPtr = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v][fillPtr[v]++] = u;
    }

    bool* visited = (bool*)calloc(numCourses, sizeof(bool));
    bool* recStack = (bool*)calloc(numCourses, sizeof(bool));
    bool possible = true;

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (hasCycle(i, adj, adjSizes, visited, recStack)) {
                possible = false;
                break;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj);
    free(adjSizes);
    free(fillPtr);
    free(visited);
    free(recStack);

    return possible;
}