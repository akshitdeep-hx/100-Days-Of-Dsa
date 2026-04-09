/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int** adj, int* adjSizes, int* visited, int* stack, int* top) {
    visited[u] = 1;

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, adj, adjSizes, visited, stack, top);
        }
    }

    stack[(*top)++] = u;
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

    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSizes, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) free(adj[i]);
    for (int i = 0; i < m; i++) free(edges[i]);
    free(adj);
    free(edges);
    free(adjSizes);
    free(fillPtr);
    free(visited);
    free(stack);
}

int main() {
    solve();
    return 0;
}