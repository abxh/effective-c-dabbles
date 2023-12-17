#include <stdio.h>

enum Day {
    MON = 1,
    TIR,
    WED = 5,
    TOR,
    FRE,
    SAT,
    SUN,
};

int main(void) {
    enum Day day = SAT;
    printf("%d\n", day);
    return 0;
// }
