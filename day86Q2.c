/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
*/
#include<stdio.h>
int mySqrt(int x) {
       if(x == 0) return 0;

    int low = 1, high = x;
    int ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid <= (long long)x) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}