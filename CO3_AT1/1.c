#include <stdio.h>
#include <ctype.h>

char expr[100];
int pos = 0;

int E();
int T();
int F();

int F() {
    int val;
    if (expr[pos] == '(') {
        pos++; 
        val = E();
        pos++; 
    } else {
        val = 0;
        while (isdigit(expr[pos])) {
            val = val * 10 + (expr[pos] - '0');
            pos++;
        }
    }
    return val; 
}

int T() {
    int val = F(); 
    while (expr[pos] == '*' || expr[pos] == '/') {
        char op = expr[pos];
        pos++;
        int f2 = F();
        if (op == '*') val = val * f2;   // T.val = T1.val * F.val
        else            val = val / f2;   // T.val = T1.val / F.val
    }
    return val;
}

int E() {
    int val = T(); // E.val = T.val
    while (expr[pos] == '+' || expr[pos] == '-') {
        char op = expr[pos];
        pos++;
        int t2 = T();
        if (op == '+') val = val + t2;   // E.val = E1.val + T.val
        else            val = val - t2;   // E.val = E1.val - T.val
    }
    return val;
}

int main() {
    printf("Enter an arithmetic expression (no spaces): ");
    scanf("%s", expr);
    pos = 0;
    int result = E();
    printf("Result = %d\n", result);
    return 0;
}