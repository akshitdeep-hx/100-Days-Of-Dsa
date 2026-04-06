/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

void bfs(int n, int** adj, int* adjSizes, int s) {
    int* visited = (int*)calloc(n, sizeof(int));
    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0;

    visited[s] = 1;
    queue[tail++] = s;

    while (head < tail) {
        int u = queue[head++];
        printf("%d ", u);

        for (int i = 0; i < adjSizes[u]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[tail++] = v;
            }
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

int main() {
    int n, m, s;
    if (scanf("%d %d %d", &n, &m, &s) != 3) return 0;

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

    bfs(n, adj, adjSizes, s);

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSizes);
    free(adjCapacities);

    return 0;
}