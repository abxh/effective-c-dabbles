#include <stdio.h>
#include <stdbool.h>

bool isN(int *ptr, int n) {
    return ptr && *ptr == n;
}

int main(void) {
    int i = 5;
    int j = 6;
    int *ptr = NULL;
    printf("%s\n", isN(ptr, j) ? "true" : "false");
    ptr = &i;
    printf("%s\n", isN(ptr, j) ? "true" : "false");
    ptr = &j;
    printf("%s\n", isN(ptr, j) ? "true" : "false");
    return 0;
}
