#include <stdio.h>
#include <limits.h>

typedef unsigned int uint;

int main (void) {
    // we want to determine if their sum will go out of bounds
    uint a=4294967294, b=4294967294;

    // instead of a+b>UINT32_MAX, we do a > UINT32_MAX-b
    if (a > UINT_MAX - b) {
        printf("Too big!\n");
    } else {
        printf("Alright.\n");
    }

    // be careful about doing stuff like this.
    printf("%u", ((uint)1) - ((uint)5));
    return 0;
}
