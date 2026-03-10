/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->heap = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapifyUp(MinHeap* h, int index) {
    while (index > 0 && h->heap[(index - 1) / 2] > h->heap[index]) {
        swap(&h->heap[index], &h->heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->heap[left] < h->heap[smallest])
        smallest = left;
    if (right < h->size && h->heap[right] < h->heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->heap[index], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void insertHeap(MinHeap* h, int val) {
    if (h->size < h->capacity) {
        h->heap[h->size++] = val;
        heapifyUp(h, h->size - 1);
    } else if (val > h->heap[0]) {
        h->heap[0] = val;
        heapifyDown(h, 0);
    }
}

int getMin(MinHeap* h) {
    return h->heap[0];
}

typedef struct {
    MinHeap* heap;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = createMinHeap(k);

    for (int i = 0; i < numsSize; i++) {
        insertHeap(obj->heap, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    insertHeap(obj->heap, val);
    return getMin(obj->heap);
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap->heap);
    free(obj->heap);
    free(obj);
}

int main() {
    int nums[] = {4, 5, 8, 2};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    KthLargest* obj = kthLargestCreate(k, nums, size);

    printf("%d\n", kthLargestAdd(obj, 3));
    printf("%d\n", kthLargestAdd(obj, 5));
    printf("%d\n", kthLargestAdd(obj, 10));
    printf("%d\n", kthLargestAdd(obj, 9));
    printf("%d\n", kthLargestAdd(obj, 4));

    kthLargestFree(obj);
    return 0;
}