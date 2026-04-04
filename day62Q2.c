/*
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
*/
#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    int* queue = (int*)malloc(roomsSize * sizeof(int));
    int head = 0, tail = 0;

    visited[0] = true;
    queue[tail++] = 0;
    int visitedCount = 1;

    while (head < tail) {
        int currentRoom = queue[head++];

        for (int i = 0; i < roomsColSize[currentRoom]; i++) {
            int key = rooms[currentRoom][i];
            if (!visited[key]) {
                visited[key] = true;
                queue[tail++] = key;
                visitedCount++;
            }
        }
    }

    free(visited);
    free(queue);

    return visitedCount == roomsSize;
}