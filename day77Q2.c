/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
typedef struct Node {
    int v;
    struct Node* next;
} Node;

int timer;

Node* addEdge(Node* head, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = head;
    return newNode;
}

void dfs(int node, int parent, Node** adj, int* visited, int* disc, int* low,
         int** ans, int* count, int** returnColumnSizes) {
    visited[node] = 1;
    disc[node] = low[node] = timer++;

    Node* temp = adj[node];
    while(temp != NULL) {
        int next = temp->v;

        if(next == parent) {
            temp = temp->next;
            continue;
        }

        if(!visited[next]) {
            dfs(next, node, adj, visited, disc, low, ans, count, returnColumnSizes);

            if(low[next] < low[node])
                low[node] = low[next];

            if(low[next] > disc[node]) {
                ans[*count] = (int*)malloc(2 * sizeof(int));
                ans[*count][0] = node;
                ans[*count][1] = next;
                (*returnColumnSizes)[*count] = 2;
                (*count)++;
            }
        }
        else {
            if(disc[next] < low[node])
                low[node] = disc[next];
        }

        temp = temp->next;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    Node** adj = (Node**)malloc(n * sizeof(Node*));
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for(int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u] = addEdge(adj[u], v);
        adj[v] = addEdge(adj[v], u);
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    int** ans = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;
    timer = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1, adj, visited, disc, low, ans, returnSize, returnColumnSizes);
        }
    }

    free(visited);
    free(disc);
    free(low);

    for(int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while(temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adj);

    return ans;
}