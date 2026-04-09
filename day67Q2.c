/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]Output: [0,1]Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*/

#include <stdlib.h>
#include <stdbool.h>

bool findOrderDFS(int u, int** adj, int* adjSizes, int* visited, int* stack, int* top) {
    visited[u] = 1; 

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (visited[v] == 1) return true; 
        if (visited[v] == 0) {
            if (findOrderDFS(v, adj, adjSizes, visited, stack, top)) return true;
        }
    }

    visited[u] = 2; 
    stack[(*top)++] = u;
    return false;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
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
        int target = prerequisites[i][0];
        int source = prerequisites[i][1];
        adj[source][fillPtr[source]++] = target;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* stack = (int*)malloc(numCourses * sizeof(int));
    int top = 0;
    bool hasCycle = false;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (findOrderDFS(i, adj, adjSizes, visited, stack, &top)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        *returnSize = 0;
        for (int i = 0; i < numCourses; i++) free(adj[i]);
        free(adj);
        free(adjSizes);
        free(fillPtr);
        free(visited);
        free(stack);
        return NULL;
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        result[i] = stack[--top];
    }

    *returnSize = numCourses;

    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj);
    free(adjSizes);
    free(fillPtr);
    free(visited);
    free(stack);

    return result;
}