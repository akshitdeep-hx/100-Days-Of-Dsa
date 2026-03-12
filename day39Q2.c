/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
typedef struct {
    int key;
    int freq;
} HashNode;

HashNode hash[MAX];
int hashSize = 0;

int findIndex(int key) {
    for (int i = 0; i < hashSize; i++) {
        if (hash[i].key == key)
            return i;
    }
    return -1;
}
typedef struct {
    int freq;
    int val;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].freq > heap[i].freq) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;
        if (l < heapSize && heap[l].freq < heap[smallest].freq)
            smallest = l;
        if (r < heapSize && heap[r].freq < heap[smallest].freq)
            smallest = r;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void pushHeap(int freq, int val, int k) {
    heap[heapSize++] = (HeapNode){freq, val};
    heapifyUp(heapSize - 1);

    if (heapSize > k) {
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(0);
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        int idx = findIndex(nums[i]);
        if (idx == -1)
            hash[hashSize++] = (HashNode){nums[i], 1};
        else
            hash[idx].freq++;
    }


    for (int i = 0; i < hashSize; i++) {
        pushHeap(hash[i].freq, hash[i].key, k);
    }

    
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].val);
    }

    return 0;
}