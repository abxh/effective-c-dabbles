#include <stdio.h>

void swap_xor(int *p1, int *p2) {
    // swap xor is incorrect if p1 = p2.
    // then:
    *p1 ^= *p2; // p1=p2: v^v=0
    *p2 ^= *p1; // p1=p2: 0^0=1
    *p1 ^= *p2; // p1=p2: 1^1=0
}

void swap_xor_restrict(int * restrict p1, int * restrict p2) {
    // therefore we explicitly declare restrict.
    // this allows the compiler to assume they are pointer
    // to distinct objects.
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
}

void swap_w_tempvar(int* p1, int* p2) {
    int t = *p2;
    *p2 = *p1;
    *p1 = t;
}

int main(void) {
    int a=5;
    swap_xor_restrict(&a, &a); // but this does not prevent the programmer from using the same object.
    printf("%d\n", a);
    return 0;
}
