#include <stdio.h>

#define HENLO "henlo"

int main(void) {
    char a[5] = HENLO; // missing '/0';
    char b[] = HENLO;
    printf("%lu\n", sizeof(b)/sizeof(*b));
    return 0;
}
