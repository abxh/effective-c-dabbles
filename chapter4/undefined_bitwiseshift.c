#include <stdio.h>

int main(void) {
    printf("%d\n", -2 >> 1); // may preserve sign. may not.
                             // specific to impl
}
