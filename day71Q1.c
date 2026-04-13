/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) ht->table[i] = EMPTY;
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int idx = ( (key % m) + (i * i) ) % m;
        if (ht->table[idx] == EMPTY) {
            ht->table[idx] = key;
            return;
        }
    }
}

void search(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int idx = ( (key % m) + (i * i) ) % m;
        if (ht->table[idx] == key) {
            printf("FOUND\n");
            return;
        }
        if (ht->table[idx] == EMPTY) {
            break;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);

    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(ht, key);
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}