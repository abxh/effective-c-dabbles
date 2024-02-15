#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    switch (i) {
        case 0:
            // declarations cannot be made here:
            // int j = 5; fails for some reason
            j = 5;
            [[fallthrough]]; // C2X attribute
        case 1:
            if (j == 0) {
                j = 6;
            }
            printf("%d\n", j);
            break;
    }
    return 0;
}
