#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"

int main() {
    // get the expression
    char *s = (char *)malloc(100 * sizeof(char));
    printf("Enter the expression: ");
    scanf("%s", s);
    // evaluate the expression
    int result = evaluate(s);
    printf("Result: %d\n", result);
    return 0;
}