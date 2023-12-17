#include <stdio.h>

// difference between:
// int foo(void); (declaration)
// int foo(void){}; (definition)

void swap(int* pa, int* pb) { // pa -> a: 1; pb -> b: 2;
    int t = *pa;              // t : pa -> a = 1;
    *pa = *pb;                // pa -> a: 2; pb -> b: 2;
    *pb = t;                  // pb -> b: t = 1;
    printf("(swap) upon swap: \n a = %d, b = %d\n", *pa, *pb);
    return;
}

#define SWAP(a, b)                                                             \
    {                                                                          \
        int temp = a;                                                          \
        a = b;                                                                 \
        b = temp;                                                              \
    }

int main(void) {
    int a = 1;
    int b = 2;

    printf("(main) before swap:\n a = %d, b = %d\n", a, b);
    // swap(&a, &b);
    int temp = 3;
    SWAP(a, b);
    printf("%d\n", temp);
    printf("(main) after swap:\n a = %d, b = %d\n", a, b);
    return 0;
}
