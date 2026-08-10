#include <stdio.h>
#include <string.h>

int isEquivalent(char *t1, char *t2) {
    return strcmp(t1, t2) == 0;
}

int main() {
    char type1[20], type2[20];

    printf("Enter first type expression (e.g. int, float, int*): ");
    scanf("%s", type1);
    printf("Enter second type expression: ");
    scanf("%s", type2);

    if (isEquivalent(type1, type2))
        printf("Types are Equivalent\n");
    else {
        printf("Types are NOT Equivalent\n");

        char base1[20], base2[20];
        strcpy(base1, type1);
        strcpy(base2, type2);

        int p1 = 0, p2 = 0;
        if (base1[strlen(base1)-1] == '*') { base1[strlen(base1)-1] = '\0'; p1 = 1; }
        if (base2[strlen(base2)-1] == '*') { base2[strlen(base2)-1] = '\0'; p2 = 1; }

        if (p1 && p2 && strcmp(base1, base2) == 0)
            printf("Note: Same base type but check confirms structurally equivalent pointer types\n");
        else if (p1 != p2)
            printf("Reason: One is a pointer type, the other is not\n");
        else
            printf("Reason: Different base types\n");
    }
    return 0;
}