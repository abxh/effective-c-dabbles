#include <stdio.h>
#include <math.h>

int main(void) {
    printf("%.2f %% %.2f = %.2f\n", 2.5F, 0.5F, (float) fmod(2.5F, 0.5F));
    return 0;
}
