#include <stdio.h>

// read for more info:
// https://stackoverflow.com/a/840504

typedef int (*int_to_int_f)(int);

int g(int x) {
    return x*2;
}

int_to_int_f f(void) {
    return g;
}

int (*h(void))(int) {
    return f();
}

int a(int b(int)) {
    return b(5);
}

int main(void) {
    printf("g(%i) is %i\n", 5, g(5));
    printf("g is %p\n", g);
    printf("f is %p\n", f);
    printf("f() is %p\n", f());
    printf("f()(%i) is %i\n", 5, f()(5));
    printf("h is %p\n", h);
    printf("*h is %p\n", *h);
    printf("&h is %p\n", &h);
    printf("h() is %p\n", h());
    printf("h()(%i) is %i\n", 5, h()(5));
}
