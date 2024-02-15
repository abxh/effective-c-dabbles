#include <stdio.h>

int main(void) {
    int x;
    printf("%s\n", (x = 1, 0) ? "true" : "false");
    printf("%s\n", (x = 2, 1) ? "true" : "false");

    int y = 5, z = 6, *x_p = &x;

    // technically the above is valid C code.
    // hence some people just write int *x, instead of int* x;

    printf("%d\n", (x = 2, x+=5));
}
