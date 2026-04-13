/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int total_cost = 0;
    int edges_count = 0;
    
    int* min_dist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    
    for (int i = 0; i < n; i++) {
        min_dist[i] = INT_MAX;
    }
    
    min_dist[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_val = INT_MAX;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && min_dist[j] < min_val) {
                min_val = min_dist[j];
                u = j;
            }
        }
        
        visited[u] = true;
        total_cost += min_val;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < min_dist[v]) {
                    min_dist[v] = dist;
                }
            }
        }
    }
    
    free(min_dist);
    free(visited);
    
    return total_cost;
}