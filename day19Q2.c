/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
*/


int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int maxSub = nums[0], currentMax = nums[0];
    int minSub = nums[0], currentMin = nums[0];

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        if (i > 0) {
            currentMax = (nums[i] > currentMax + nums[i]) ? nums[i] : currentMax + nums[i];
            maxSub = (maxSub > currentMax) ? maxSub : currentMax;

            currentMin = (nums[i] < currentMin + nums[i]) ? nums[i] : currentMin + nums[i];
            minSub = (minSub < currentMin) ? minSub : currentMin;
        }
    }

    if (totalSum == minSub) return maxSub;

    int circularMax = totalSum - minSub;
    return (maxSub > circularMax) ? maxSub : circularMax;
}