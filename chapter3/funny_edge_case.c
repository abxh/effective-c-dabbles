#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int main(void) {
    printf("ABS(%d)=%d", INT_MIN, ABS(INT_MIN));

    return EXIT_SUCCESS;
}
