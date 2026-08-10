#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int main() {
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression (e.g. 32+4*): ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
            printf("Push operand: %c -> Stack top = %d\n", ch, stack[top]);
        } else {
            op2 = pop();   // synthesized from right child
            op1 = pop();   // synthesized from left child
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }
            push(result);
            printf("Apply %c: %d %c %d = %d\n", ch, op1, ch, op2, result);
        }
    }
    printf("Final Result = %d\n", pop());
    return 0;
}