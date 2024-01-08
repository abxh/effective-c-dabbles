#include <limits.h>
#include <errno.h>
#include <stdio.h>

// as it was previously seen:
//   mapping the types to sizeof, we are garanteed to get:
//   _Bool <= char <= short int <= int <= long int <= long long int

int main(void) {
    // use type conversions like (int) when in doubt.

    // example of implicit conversion:
    unsigned int uint_max = UINT_MAX;
    signed char minus_one_char = -1;
    if (minus_one_char == uint_max) {
        printf("%i equals %u\n", minus_one_char, uint_max);

        printf("This is because signed chars is all ones. It has the bit representation: ");
        for (int i = sizeof(signed char) * 8 - 1; i > 0; i--) {
            printf("%u", (minus_one_char >> i) & 1);
        }
        putchar('\n');
        printf("While uint_max has the bit representation: ");
        for (int i = sizeof(unsigned int) * 8 - 1; i > 0; i--) {
            printf("%u", (uint_max >> i) & 1);
        }
        putchar('\n');
    }
    
    // signedness is preversed in integer conversions,
    // and it is safe to convert to larger types.
    signed char c = -55;
    signed short int si = c;
    signed int i = si;
    signed long int li = i;
    signed long long int lli = li;

    printf("Signedness and value is preserved: %i == %i == %i == %li == %lli\n", c, si, i, li, lli);

    // to convert back, we must check that it falls in the range that a given type can have:
    if (CHAR_MIN <= lli && lli <= CHAR_MAX) {
        printf("-55 is converted back safely: %b\n", (signed char)-55 == (signed char) lli); 
    } else {
        return ERANGE; // seems like this is the appropiate error code to return out of range.
    }


}
