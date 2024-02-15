#include <stdio.h>

int main(void) {
    // there are different ways to implement the % operator it seems.
    // For C we have

    printf("10 %% 3 == %d\n", 10 % 3);     // ->  1
    printf("10 %% -3 == %d\n", 10 % -3);   // ->  1
    printf("-10 %% 3 == %d\n", -10 % 3);   // -> -1
    printf("-10 %% -3 == %d\n", -10 % -3); // -> -1

    // remainder has the same sign as the dividend.
}
