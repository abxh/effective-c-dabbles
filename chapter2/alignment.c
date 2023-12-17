#include <stdio.h>
#include <stdalign.h>

// Read for more info:
// https://learn.microsoft.com/en-us/cpp/c-language/alignment-c?view=msvc-170

struct S {
    int i;    // 4 bytes
    double d; // 8 bytes
    char c;   // 1 byte
};

int main(void) {
    unsigned char bad_buff[sizeof(struct S)];
    struct S *bad_s_ptr = (struct S *) bad_buff;
    printf("bad_pointer: %p\n", bad_s_ptr);
    printf("bad_size: %d\n", sizeof(bad_buff));
    printf("bad_alignof: %d\n", alignof(bad_buff));

    alignas (struct S) unsigned char good_buff[sizeof(struct S)];
    struct S *good_s_ptr = (struct S *)good_buff;
    printf("good_pointer: %p\n", good_s_ptr);
    printf("good_size: %d\n", sizeof(good_buff));
    printf("good_alignof: %d\n", alignof(good_buff));

    size_t alignment = alignof(short);
    printf("alignof(char) = %d\n", alignof(char)); // 1
    printf("alignof(short) = %d\n", alignment); // 2
    printf("alignof(int) = %d\n", alignof(int)); // 4
    printf("alignof(long) = %d\n", alignof(long)); // 4
    printf("alignof(float) = %d\n", alignof(float)); // 4
    printf("alignof(double) = %d\n", alignof(double)); // 8

    return 0;
}

