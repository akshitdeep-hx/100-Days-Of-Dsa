/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
*/
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    int val;
    struct List* next;
} List;

void dfs(int u, int p, List** adj, int* tin, int* low, bool* visited, bool* isAP, int* timer) {
    visited[u] = true;
    tin[u] = low[u] = (*timer)++;
    int children = 0;
    List* curr = adj[u];
    while (curr) {
        int v = curr->val;
        if (v == p) {
            curr = curr->next;
            continue;
        }
        if (visited[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
        } else {
            dfs(v, u, adj, tin, low, visited, isAP, timer);
            if (low[v] < low[u]) low[u] = low[v];
            if (low[v] >= tin[u] && p != -1) isAP[u] = true;
            children++;
        }
        curr = curr->next;
    }
    if (p == -1 && children > 1) isAP[u] = true;
}

int* articulationPoints(int V, List** adj, int* returnSize) {
    int* tin = (int*)malloc(V * sizeof(int));
    int* low = (int*)malloc(V * sizeof(int));
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* isAP = (bool*)calloc(V, sizeof(bool));
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, tin, low, visited, isAP, &timer);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (isAP[i]) count++;
    }

    int* result = (int*)malloc(count * sizeof(int));
    int idx = 0;
    for (int i = 0; i < V; i++) {
        if (isAP[i]) result[idx++] = i;
    }

    free(tin);
    free(low);
    free(visited);
    free(isAP);
    *returnSize = count;
    return result;
}