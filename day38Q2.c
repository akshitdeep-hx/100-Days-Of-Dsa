/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include <stdio.h>

#define MAX 10000

int deque[MAX];
int front = 0, rear = -1;

int isEmpty() {
    return front > rear;
}

void popFront() {
    front++;
}

void popBack() {
    rear--;
}

void pushBack(int x) {
    deque[++rear] = x;
}

int getFront() {
    return deque[front];
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    int result[n];
    int resSize = 0;

    for (int i = 0; i < n; i++) {
        
        if (!isEmpty() && getFront() <= i - k)
            popFront();

    
        while (!isEmpty() && nums[deque[rear]] < nums[i])
            popBack();

        pushBack(i);

        
        if (i >= k - 1)
            result[resSize++] = nums[getFront()];
    }

    
    for (int i = 0; i < resSize; i++)
        printf("%d ", result[i]);

    return 0;
}