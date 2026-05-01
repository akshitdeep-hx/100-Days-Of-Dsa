/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/
#include <stdio.h>

int isFeasible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];

            if(students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int low = 0, high = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        if(pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    if(n < m) {
        printf("-1");
        return 0;
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isFeasible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}