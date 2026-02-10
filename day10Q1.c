/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/
#include<stdio.h>
#include<string.h>

void isPalindrome(char *str){
    int left = 0;
    int right = strlen(str) - 1;

    while(left < right){

        if(str[left] != str[right]){
            printf("No\n");
            return;
        }

        left++;
        right--;
    }

    printf("Yes\n");
}

int main(){
    isPalindrome("level");
    return 0;
}