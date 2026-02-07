/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include<stdio.h>
int main(){
    int n, arr[100];
    scanf("%d", &n);

    for(int i = 0; i< n; i++){
        scanf("%d ", &arr[i]);
    }

     int slow = 0;
    for (int fast = 1; fast < n; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    
    for (int i = 0; i <= slow; i++) {
        printf("%d", arr[i]);
        if (i < slow) printf(" ");
    }
    printf("\n");
    
    return 0;
}



