#include <stdio.h>
// it's a "compound" literal, that is a bunch of
// literals combined together.

typedef union {
    int arr[3];
    struct {
        int x;
        int y;
        int z;
    };
} vec;

int main(void) {
    int* arr = (int[]) {5,4,3};
    int arr1[3] = {5,4,3};
    vec v = {1,2,3}; // can be implicit (vec)
    char *s = (char[]){'9', '8', '7'};
    char t[] = "567";

    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    printf("%d %d %d\n", v.arr[0], v.arr[1], v.arr[2]);
    printf("%d %d %d\n", v.x, v.y, v.z);
    printf("%c %c %c\n", s[0], s[1], s[2]);
    printf("%c %c %c\n", t[0], t[1], t[2]);

    return 0;
}
