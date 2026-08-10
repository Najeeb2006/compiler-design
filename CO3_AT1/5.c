#include <stdio.h>
#include <string.h>

int isValidOp(char *type1, char op, char *type2) {
    int numeric1 = (strcmp(type1, "int") == 0 || strcmp(type1, "float") == 0);
    int numeric2 = (strcmp(type2, "int") == 0 || strcmp(type2, "float") == 0);

    if ((op == '+' || op == '-' || op == '*' || op == '/') && numeric1 && numeric2)
        return 1;
    return 0;
}

int main() {
    char type1[20], type2[20];
    char op;

    printf("Enter type of operand 1 (int/float/char/char*): ");
    scanf("%s", type1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter type of operand 2 (int/float/char/char*): ");
    scanf("%s", type2);

    if (isValidOp(type1, op, type2))
        printf("Result: Valid expression (%s %c %s)\n", type1, op, type2);
    else
        printf("Result: Type Error -> Invalid operation between %s and %s\n", type1, type2);

    return 0;
}