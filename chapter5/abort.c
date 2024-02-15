#include <stdio.h>
#include <stdlib.h>

typedef enum { ABC, CDE, EFG } gagh;

int main(void) {
    gagh x = EFG;
    switch (x) {
        case ABC:
            printf("ABC\n");
            break;
        case CDE:
            printf("CDE\n");
            break;
        default:
            printf("aborting\n");
            abort();
    }
}
