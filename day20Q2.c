/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

#include <stdlib.h>
#include <stdio.h>


int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Initial capacity for the results array (will resize if needed)
    int capacity = 32; 
    int **result = (int**)malloc(sizeof(int*) * capacity);
    int *cols = (int*)malloc(sizeof(int) * capacity);
    int count = 0;
    
    
    qsort(nums, numsSize, sizeof(int), compareInt);
    
    for (int i = 0; i < numsSize - 2; i++) {
    
        if (nums[i] > 0) break;
        
        
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = numsSize - 1;
        int target = -nums[i];
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                // Found a valid triplet
                int* triplet = (int*)malloc(sizeof(int) * 3);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                
                // Store the triplet and its column size
                result[count] = triplet;
                cols[count] = 3;
                count++;
                
                // Resize result array if capacity is reached
                if (count == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                    cols = (int*)realloc(cols, sizeof(int) * capacity);
                }
                
                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == triplet[1]) left++;
                while (left < right && nums[right] == triplet[2]) right--;
            } else if (sum < target) {
                left++; 
            } else {
                right--; 
            }
        }
    }
    
    
    *returnSize = count;
    *returnColumnSizes = cols;
    
    return result;
}
