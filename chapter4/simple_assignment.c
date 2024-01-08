#include <stdio.h>

int main(void) {
    
    int i;  // declaration. may set it to 0 or something else...
    printf("int i;      # i is %d\n", i);
    i = 42; // assignment
    printf("i = 42;     # i is %d\n", i);

    int j = 69; // declaration with initializer;
    printf("int j = 69; # j is %d\n", j);
    j = i; // assignment.
    printf("j = i;      # j is %d\n", j);

    // Simple assignments have the following pattern:
    // lvalue = rvalue,
    // where lvalue can be thought of as the locator value,
    // and rvalue can be thought of as the expression value.

    // the locator to the left must be some object in
    // which the expression to the right is evaluated and put in.

    // invalid simple assignments:
    // 13 = i;
    // a+b = c;
    // f(x) = c;
    // &a = c;
    
    // valid simple assignments:
    // int *p = &a;
    // assuming int *p, p = &a;
    // a = *(a+b);
    // b = f(x);
    // c = *(f(x));

    // a side effect is done anytime a value is assigned.
    // functions may or may not have side effects.

    return 0;
}
