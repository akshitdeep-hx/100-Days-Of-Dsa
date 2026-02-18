/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (currSum < 0)
            currSum = nums[i];
        else
            currSum += nums[i];

        if (currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}