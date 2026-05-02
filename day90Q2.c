/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/
#include <stdio.h>

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int* nums, int low, int high) {
    int pivot = nums[low];
    int j = low;

    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            j++;
            swap(nums, i, j);
        }
    }
    swap(nums, low, j);
    return j;
}

int QSelect(int* nums, int low, int high, int k) {
    if (low <= high) {
        int p = partition(nums, low, high);

        if (p == k) return nums[p];
        if (p < k) return QSelect(nums, p + 1, high, k);
        else return QSelect(nums, low, p - 1, k);
    }
    return nums[low];
}

int findKthLargest(int* nums, int numsSize, int k) {
    return QSelect(nums, 0, numsSize - 1, numsSize - k);
}