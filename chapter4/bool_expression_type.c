#include <stdio.h>

int main(void) {
    printf("1 == 1 %s int\n", sizeof(1 == 1) == sizeof(int) ? "is": "is not");
    return 0;
}
