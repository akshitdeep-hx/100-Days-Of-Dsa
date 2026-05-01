/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

*/
#include<stdio.h>
#include<stdbool.h>
void findMaxNSum(int* weights, int size, int* low, int* high) {
    for (int i = 0; i < size; i++) {
        if (*low > weights[i]) *low = weights[i];
        *high += weights[i];
    }
}

bool findMinWeights(int* weights, int size, int days, int minWeight) {
    int temp = minWeight;
    int i = 0;
    while (i < size && days > 0) {
        if (temp < weights[i]) {
            days--;
            temp = minWeight;
        } else {
            temp -= weights[i];
            i++;
        }
    }
    return i == size;
}
int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0, ans = 0;
    findMaxNSum(weights, weightsSize, &low, &high);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (findMinWeights(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}