#include <stdio.h>

int m[2] = {1, 2};

int main(void) {
    int *pi = &m[0];
    int *org = pi;
    int j = 0;
    printf("pi - org: %d ints\n", (pi - org));
    printf("j: %i\n", j);
    for (; pi < &m[2]; ++pi) {
        printf("pi - org: %d ints\n", (pi - org));
        j += *pi;
    }
    printf("pi - org: %d ints\n", (pi - org));
    printf("j: %i\n", j);
    return 0;
}
