/*  
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize,  int target, int* returnSize){
    static int result[2];
    
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main(){
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    printf("Enter target: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, n, target, &returnSize);

    if(returnSize == 2){
        printf("[%d, %d]\n", result[0], result[1]);
    }
    else{
        printf("No valid answer exists.\n");
    }
    free(nums);
    return 0;
}
