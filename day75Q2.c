/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other
*/
#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int c, int** graph, int* graphColSize, int* colors) {
    colors[node] = c;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == 0) {
            if (!dfs(neighbor, -c, graph, graphColSize, colors)) {
                return false;
            }
        } else if (colors[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* colors = (int*)calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == 0) {
            if (!dfs(i, 1, graph, graphColSize, colors)) {
                free(colors);
                return false;
            }
        }
    }
    free(colors);
    return true;
}