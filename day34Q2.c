/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
*/
#include <ctype.h>

int calculate(char* s) {
    int stack[1000];
    int top = -1;
    char op = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op = s[i];
            i++;
        }
        else {
            int num = 0;
            while (s[i] != '\0' && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num;
            }
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}