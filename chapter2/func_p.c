#include <stdio.h>

int one(void) {
    return 1;
}

int two(void) {
    return 2;
}

int three(void) {
    return 3;
}

int five(void) {
    return 5;
}

int main(void) {
    int func(void);
    // func = one; // invalid

    int (* func_p)(void);
    func_p = two;
    printf("%d\n", func_p());


    typedef int(*funcp_t)(void);
    funcp_t func_p1 = &two;
    printf("%d\n", func_p());

    printf("%d\n", (three)());
    printf("%d\n", (*&three)());
    printf("%d\n", (&*three)());
    printf("%d\n", (*three)());
    printf("%d\n", (**three)());
    printf("%d\n", (*************five)());
    //printf("%d\n", (&&three)()); // Does not work.

    int(*func_p_list[4])(void);
    func_p_list[0] = one;
    func_p_list[1] = two;
    func_p_list[2] = three;
    func_p_list[3] = five;

    int (**func_p_list_of_list[1])(void);
    *func_p_list_of_list = func_p_list;

    printf("calling functions in the first function list in list of lists.\n");
    for (int i; i < 4; i++) {
        printf("%d\n", (*func_p_list_of_list)[i]());
    }
    return 0;
}
