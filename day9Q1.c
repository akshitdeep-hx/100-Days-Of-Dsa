/*
Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/

#include<stdio.h>

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