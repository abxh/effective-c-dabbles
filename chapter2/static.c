#include <stdio.h>

static unsigned int counter = 0;

void increment(void) {
    counter++;
}
int retrieve(void) {
    return counter;
}

void func(int i) {
    const int j = i;  // ok
    // static int k = j; // error
    // return &k;
    // return &j; // complains
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        increment();
        printf("%d\n", retrieve());
    }
    return 0;
}
