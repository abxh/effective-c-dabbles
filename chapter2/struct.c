#include <stdio.h>

struct sinewav_r {
    float amplitude;
    float frequency;
} sinewav, *sinewav_p;

typedef struct sinewav_r sinewav_t;

int main() {
    sinewav.amplitude = 5.;
    sinewav.frequency = 6.;

    printf("amplitude: %f\n", sinewav.amplitude);
    printf("frequency: %f\n", sinewav.frequency);

    sinewav_p = &sinewav;

    printf("amplitude: %f\n", sinewav_p->amplitude);
    printf("frequency: %f\n", sinewav_p->frequency);

    sinewav_t sinewav1 = sinewav;

    printf("amplitude: %f\n", sinewav1.amplitude);
    printf("frequency: %f\n", sinewav1.frequency);

    return 0;
}

