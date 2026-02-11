/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int key;
    int count;
} HashNode;

HashNode hash[MAX];
int hashSize = 0;

int findIndex(int key) {
    for (int i = 0; i < hashSize; i++) {
        if (hash[i].key == key) return i;
    }
    return -1;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int nums1[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &nums2[i]);

    // Count frequency of nums1
    for (int i = 0; i < n1; i++) {
        int idx = findIndex(nums1[i]);
        if (idx == -1) hash[hashSize++] = (HashNode){nums1[i], 1};
        else hash[idx].count++;
    }

    // Find intersection with nums2
    printf("Intersection: ");
    for (int i = 0; i < n2; i++) {
        int idx = findIndex(nums2[i]);
        if (idx != -1 && hash[idx].count > 0) {
            printf("%d ", nums2[i]);
            hash[idx].count--;
        }
    }
    printf("\n");

    return 0;
}