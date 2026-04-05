/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

void dfsRecursive(int u, int** adj, int* adjSizes, int* visited) {
    visited[u] = 1;
    printf("%d ", u);

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfsRecursive(v, adj, adjSizes, visited);
        }
    }
}

void solve() {
    int n, m, s;
    if (scanf("%d %d %d", &n, &m, &s) != 3) return;

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSizes = (int*)calloc(n, sizeof(int));
    int* adjCapacities = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        adjCapacities[i] = 2;
        adj[i] = (int*)malloc(adjCapacities[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) == 2) {
            if (adjSizes[u] == adjCapacities[u]) {
                adjCapacities[u] *= 2;
                adj[u] = (int*)realloc(adj[u], adjCapacities[u] * sizeof(int));
            }
            adj[u][adjSizes[u]++] = v;
            
            if (adjSizes[v] == adjCapacities[v]) {
                adjCapacities[v] *= 2;
                adj[v] = (int*)realloc(adj[v], adjCapacities[v] * sizeof(int));
            }
            adj[v][adjSizes[v]++] = u;
        }
    }

    int* visited = (int*)calloc(n, sizeof(int));

    dfsRecursive(s, adj, adjSizes, visited);
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSizes);
    free(adjCapacities);
    free(visited);
}

int main() {
    solve();
    return 0;
}