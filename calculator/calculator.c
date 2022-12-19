// implement calculator parser and evaluator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"

// find the index of the lowest precedence operator in the expression
// include +, -, *, /
// in case of equal precedence, return the leftmost operator
// return -1 if there is no operator
int findOperator(char *s) {
    int i = 0;
    int j = -1;
    while (s[i] != '\0') {
        if (s[i] == '+' || s[i] == '-') {
            if (j == -1 || s[j] == '*' || s[j] == '/') {
                j = i;
            }
        } else if (s[i] == '*' || s[i] == '/') {
            if (j == -1) {
                j = i;
            }
        }
        i++;
    }
    return j;
}

// evaluate the expression
// return the result
int evaluate(char *s) {
    int i = findOperator(s);
    if (i == -1) {
        return atoi(s);
    }
    char *left = (char *)malloc(i * sizeof(char));
    char *right = (char *)malloc((strlen(s) - i - 1) * sizeof(char));

    memcpy(left, s, i * sizeof(char));
    memcpy(right, s + i + 1, (strlen(s) - i - 1) * sizeof(char));

    int leftValue = evaluate(left);
    int rightValue = evaluate(right);

    if (s[i] == '+') {
        return leftValue + rightValue;
    } else if (s[i] == '-') {
        return leftValue - rightValue;
    } else if (s[i] == '*') {
        return leftValue * rightValue;
    } else if (s[i] == '/') {
        return leftValue / rightValue;
    }
    return 0;
}