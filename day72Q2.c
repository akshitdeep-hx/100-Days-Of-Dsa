/*
Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
*/
#include <stdio.h>
#include <string.h>


#define INF 1e9

int n;
int memo[1 << 16][16];

int solve(int mask, int u, int cost[16][16]) {
    if (mask == (1 << n) - 1) {
        return cost[u][0];
    }

    if (memo[mask][u] != -1) {
        return memo[mask][u];
    }

    int res = INF;

    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) {
            int current = cost[u][v] + solve(mask | (1 << v), v, cost);
            if (current < res) {
                res = current;
            }
        }
    }

    return memo[mask][u] = res;
}

int tsp(int cost[16][16], int num_cities) {
    n = num_cities;
    memset(memo, -1, sizeof(memo));
    return solve(1, 0, cost);
}