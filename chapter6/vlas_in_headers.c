#include <stdlib.h>
#include <stdio.h>

int x2matrix_sum(size_t rows, int m[][2]) {
    size_t total = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < 2; j++) {
            total += m[i][j];
        }
    }
    return total;
}

int main(void) {
    int m[1][2] = {{1,2}};
    printf("%d\n", x2matrix_sum(1,m));
}
