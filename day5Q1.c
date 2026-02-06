/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/

#include <stdio.h>

int main() {
    int n1, n2;
    int arr1[100], arr2[100], result[200];
    
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
    
    for (int i = 0; i < k; i++) {
        printf("%d", result[i]);
        if (i < k - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}  
