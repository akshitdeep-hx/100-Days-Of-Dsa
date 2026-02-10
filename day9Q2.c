/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <stdio.h>

void reverseString(char* s, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[] = {'h','e','l','l','o'};
    int size = sizeof(s) / sizeof(s[0]);

    reverseString(s, size);

    printf("Reversed string: ");
    for (int i = 0; i < size; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}