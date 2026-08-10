#include <stdio.h>


int T_eval(int inh_val, char op, int b, int c);
int E_eval(int a, int b, int c);

int T_eval(int inh_val, char op, int b, int c) {
    int Tval = b;        
    if (op == '*')
        Tval = Tval * c;  
    printf("T.val computed using inherited base = %d, result = %d\n", inh_val, Tval);
    return Tval;
}

int E_eval(int a, int b, int c) {
    int inherited_from_E = a;          
    int Tval = T_eval(inherited_from_E, '*', b, c); 
    int Eval = inherited_from_E + Tval; 
    printf("E.val (final) = %d + %d = %d\n", inherited_from_E, Tval, Eval);
    return Eval;
}

int main() {
    int a, b, c;
    printf("Enter values for a, b, c (for expression a + b*c): ");
    scanf("%d %d %d", &a, &b, &c);

    int result = E_eval(a, b, c);
    printf("Final Result of a + b*c = %d\n", result);
    return 0;
}