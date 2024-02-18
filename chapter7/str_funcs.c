#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check for memory leaks using valgrind

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    char *str = malloc(MAX(strlen("Hello World") + 1, sizeof("Goodbye World")));

    strcpy(str, "Hello");
    strcat(str, " World");
    printf("%s\n", str);

    putchar('\n');

    printf("strchr'ed 'l':\t");
    printf("%s\n", strchr(str, 'l'));;
    printf("strrchr'ed 'l':\t");
    printf("%s\n", strrchr(str, 'l'));;

    printf("strstr'ed \"Wo\":\t");
    printf("%s\n", strstr(str, "Wo"));;

    printf("strpbrk \"lW\":\t");
    printf("%s\n", strpbrk(str, "lW"));

    printf("strcspn \"lW\":\t");
    printf("%zu (index)\n", strcspn(str, "lW"));

    printf("strspn \"Heyo\":\t");
    printf("%zu (length)\n", strspn(str, "Heyo"));

    // note to self: strcmp does not compare length. read the docs for more info.
    printf("The strings are not equal to each other: %s\n",
           strcmp("Hello World", "Goodbye World") != 0 ? "true" : "false");

    putchar('\n');

    strcpy(str, "Goodbye");
    strcat(str, " World");
    printf("%s\n", str);

    free(str);
    return 0;
}
