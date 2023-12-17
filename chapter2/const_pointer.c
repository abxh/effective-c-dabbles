#include <stdio.h>

int main(void) {
    int i = 32;
    const int j = 64;
    const int *ip = &i;
    const int *jp = &j;
    *(int *)ip = 5;
    *(int *)jp = 5;
    printf("*ip: %d\n", *ip);
    printf("*jp: %d\n", *jp);
}
