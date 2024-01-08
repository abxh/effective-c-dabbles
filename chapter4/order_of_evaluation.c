#include <stdio.h>

// order of evaluation is unspecified (left to the compiler)
// gcc may produce 'b' before 'a'
// clang may produce 'a' before 'b'

typedef void func(void);

int f(void) {
    puts("a");
    return 2;
}
int g(void) {
    puts("b");
    return 1;
}
int sum(int x, int y) {
    return x + y;
}
int main(void) {
    // you probably want to compute the computations
    // in individual lines if they have side effects
    // that affect each other.
    printf("%d\n", sum(f(), g()));
    return 0;
}
