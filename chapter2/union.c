#include <stdio.h>

// Type definition:
typedef enum {
    Box,
    RoundedBox,
    Cylinder
} ContainerType;

// Type alias:
typedef union Container Container;

// Type definition:
union Container {
    struct {
        ContainerType type;
    } n;
    struct {
        ContainerType type;
        int value;
    } ni;
    struct {
        ContainerType type;
        float value;
    } nf;
    struct {
        ContainerType type;
        Container *value; // container cannot be anonymous.
    } nr;
};

typedef union {
    struct {
        int p1_x;
        int p1_y;
        int p2_x;
        int p2_y;
    };
    struct {
        int p1[2];
        int p2[2];
    };
    int arr[4];
} Line;

int main() {
    Container c, c_inner;
    c.ni.value = 1234;
    printf("%d\n", c.ni.value);
    printf("%f\n", c.nf.value);

    c.nr.value = &c_inner;
    (*c.nr.value).ni.value = 5;
    c.nr.value->ni.value = 5;
    printf("%d\n", c.nr.value->ni.value);

    Line l;
    l.p1_x = 3;
    l.p1_y = 10;
    l.p2_x = 4;
    l.p2_y = 10;

    printf("p1: (%d, %d), p2: (%d, %d)\n", l.p1[0], l.p1[1], l.p2[0], l.p2[1]);

    printf("values: %d", l.arr[0]);
    for (int i = 1; i < 4; i++) {
        printf(", %d", l.arr[i]);
    }
    putchar('\n');
    return 0;
}
