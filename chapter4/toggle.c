#include <stdio.h>

int main(void) {
    int a = 5;
    for (int i = 0; i < 10; i++) {
        printf("%s\n", a ^ i ? "true": "false");
    }
    return 0;
}
