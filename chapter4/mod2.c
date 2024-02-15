#include <stdio.h>

int main(void) {
    size_t x = 0;
    for (size_t i = 0; i < 5; i++) {
        printf("%s\n", (x ^= 1) ? "true" : "false");
    }
}
