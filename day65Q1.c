/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfsCycle(int u, int p, int** adj, int* adjSizes, int* visited) {
    visited[u] = 1;

    for (int i = 0; i < adjSizes[u]; i++) {
        int v = adj[u][i];
        
        if (!visited[v]) {
            if (dfsCycle(v, u, adj, adjSizes, visited)) {
                return true;
            }
        } 
        else if (v != p) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

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
    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adj, adjSizes, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSizes);
    free(adjCapacities);
    free(visited);
}

int main() {
    solve();
    return 0;
}