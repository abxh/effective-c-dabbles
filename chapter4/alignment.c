#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>

// Read for more info:
// https://learn.microsoft.com/en-us/cpp/c-language/alignment-c?view=msvc-170

// CPUs favor powers of two to access stuff, and arrays
// of 1-byte to 8 (for 64-bit) processors are accessed quickly.

// Aligning a struct means accessing the data more efficiently.
// That means that the type with the largest number of bytes
// is used as the alignof value. Then the struct is sort of a
// array of alignof size, and the data is accessed more efficiently.
// padding is used to do this. And it makes it more cache friendly.

struct S {
    int i;    // 4 bytes
    double d; // 8 bytes
    char c;   // 1 byte
};

int main(void) {
    unsigned char bad_buff[sizeof(struct S)];
    struct S *bad_s_ptr = (struct S *) bad_buff;
    printf("bad struct size: %d\n", sizeof(bad_buff));
    printf("bad struct alignof: %d\n", alignof(bad_buff));

    alignas (struct S) unsigned char good_buff[sizeof(struct S)];
    struct S *good_s_ptr = (struct S *)good_buff;
    printf("good struct size: %d\n", sizeof(good_buff));
    printf("good struct alignof: %d\n", alignof(good_buff));
    putchar('\n');
    printf("max alignof: %d\n", alignof(max_align_t));
    putchar('\n');

    printf("alignof(char): %d\n", alignof(char)); // 1
    size_t alignment = alignof(short);
    printf("alignof(short): %d\n", alignment); // 2
    printf("alignof(int): %d\n", alignof(int)); // 4
    printf("alignof(long): %d\n", alignof(long)); // 4
    printf("alignof(float): %d\n", alignof(float)); // 4
    printf("alignof(double): %d\n", alignof(double)); // 8

    return 0;
}

