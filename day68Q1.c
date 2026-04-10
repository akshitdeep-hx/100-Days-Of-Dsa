/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

void kahnsTopologicalSort(int n, int** adj, int* adjSizes) {
    int* inDegree = (int*)calloc(n, sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0, count = 0;
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < adjSizes[u]; i++) {
            inDegree[adj[u][i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    while (head < tail) {
        int u = queue[head++];
        result[count++] = u;

        for (int i = 0; i < adjSizes[u]; i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
        }
    }

    if (count != n) {
        printf("Cycle detected! No topological order exists.\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    free(inDegree);
    free(result);
    free(queue);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

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

    kahnsTopologicalSort(n, adj, adjSizes);

    for (int i = 0; i < n; i++) free(adj[i]);
    for (int i = 0; i < m; i++) free(edges[i]);
    free(adj);
    free(edges);
    free(adjSizes);
    free(fillPtr);

    return 0;
}