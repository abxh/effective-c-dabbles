#include <stdio.h>

int main(void) {
    int i = 2;
    printf("%d\n", i++ * i++);
    printf("%d\n", (i = i + 1) * (i = i + 1));
    return 0;
}
