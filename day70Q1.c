/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("Node %d: INF\n", i);
        } else {
            printf("Node %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, m, src;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge* edges = malloc(m * sizeof(struct Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    free(edges);
    return 0;
}