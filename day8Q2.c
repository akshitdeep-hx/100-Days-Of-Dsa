/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num1 = 16;
    int num2 = 3;
    int num3 = 1;

    printf("%d is a power of two: %s\n", num1, isPowerOfTwo(num1) ? "true" : "false");
    printf("%d is a power of two: %s\n", num2, isPowerOfTwo(num2) ? "true" : "false"); 
    printf("%d is a power of two: %s\n", num3, isPowerOfTwo(num3) ? "true" : "false"); 

    return 0;
}