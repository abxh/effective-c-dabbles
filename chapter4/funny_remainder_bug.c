#include <limits.h>
#include <stdio.h>

int main(void) {
    // does not always appear it seems.
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MIN / -1: %d\n", INT_MIN / -1);
    printf("INT_MIN %% -1: %d (bugged: %s)\n", INT_MIN % -1, INT_MIN % -1 != 0 ? "true": "false");
    return 0;
}
