/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int u, int** adj, int* adjSizes, bool* visited, bool* recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (dfs(v, adj, adjSizes, visited, recStack)) return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

    int* adjSizes = (int*)calloc(n, sizeof(int));
    int** edges = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        adjSizes[edges[i][0]]++;
    }

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSizes[i] * sizeof(int));
    }

    int* fillPtr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][fillPtr[u]++] = v;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool* recStack = (bool*)calloc(n, sizeof(bool));
    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSizes, visited, recStack)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");

    for (int i = 0; i < n; i++) free(adj[i]);
    for (int i = 0; i < m; i++) free(edges[i]);
    free(adj);
    free(edges);
    free(adjSizes);
    free(fillPtr);
    free(visited);
    free(recStack);
}

int main() {
    solve();
    return 0;
}