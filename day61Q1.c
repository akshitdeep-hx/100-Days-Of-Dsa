/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/
#include <stdio.h>
#include <stdlib.h>

void buildGraph() {
    int n, m, isDirected;
    
    if (scanf("%d %d %d", &n, &m, &isDirected) != 3) return;

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            if (!isDirected) {
                adj[v][u] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
}

int main() {
    buildGraph();
    return 0;
}