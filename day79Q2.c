/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. 
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] 
denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.
*/
#include <stdbool.h>
#include <stdlib.h>
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