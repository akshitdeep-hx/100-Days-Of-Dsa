/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int u, int p, int** adj, int* adjSizes, bool* visited) {
    visited[u] = true;
    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (dfs(v, u, adj, adjSizes, visited)) return true;
        } else if (v != p) {
            return true;
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {
    int* adjSizes = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < E; i++) {
        adjSizes[edges[i][0]]++;
        adjSizes[edges[i][1]]++;
    }

    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSizes[i] * sizeof(int));
    }

    int* fillPtr = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][fillPtr[u]++] = v;
        adj[v][fillPtr[v]++] = u;
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool hasCycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSizes, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);
    free(adjSizes);
    free(fillPtr);
    free(visited);

    return hasCycle;
}