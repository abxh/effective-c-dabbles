#include <stdio.h>

int main(void) {
    int i = 5;
    int e;
    printf("// e: %d, i: %d\n", e, i);
    e = i++; // e = i; i+= 1;
    printf("e = i++; // e: %d, i: %d (i.e. e = i; i+= 1)\n", e, i);
    e = i--; // e = i; i-= 1;
    printf("e = i--; // e: %d, i: %d (i.e. e = i; i-= 1)\n", e, i);
    e = ++i; // e = (i+=1);
    printf("e = ++i; // e: %d, i: %d (i.e. e = (i+=1))\n", e, i);
    e = --i; // e = (i-=1);
    printf("e = --i; // e: %d, i: %d (i.e. e = (i-=1))\n", e, i);

    // some weird rules:
    // (when in doubt, put parenthesis)
    char s[] = "nope";
    char s1[] = "yes";
    char *p = s;
    printf("string is %s, and p points to first letter\n", s);
    printf("++*p: %c\n", ++*p);
    p = s1;
    printf("string is %s, and p points to first letter\n", s1);
    printf("*p++: %c\n", *p++);

    return 0;
}
