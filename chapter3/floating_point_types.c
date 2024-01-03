#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h> // note: use gcc -lm to use this library.

// refer to:
// https://stackoverflow.com/questions/44609743/obtaining-bit-representation-of-a-float-in-c
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)FloatingPoint.html
// https://www.geeksforgeeks.org/introduction-of-floating-point-representation/

void printf_info(float x) {
    // floating point is represented as:
    // 1 signed bit + 8 exponent bit + 23 mantissa bit.

    union {
        float x;
        uint32_t ui;
    } xu = { .x = x };

    printf("for floating number: %f\n\n", x);
    int neg_sign = (xu.ui >> 31) & 0x1;
    printf (" %d", neg_sign);

    int exponent = 0;
    for (int i = 30; i > 22; i--) {
        int b = (xu.ui >> i) & 0x1;
        printf (" %d", b);
        exponent = exponent * 2 + b;
    }
    exponent -= 127; // as it's a two complement 8-bit number.

    float mantissa = 1;
    int denom = 2;
    for (int i = 22; i >= 0; i--) {
        int b = (xu.ui >> i) & 0x1;
        printf (" %d", b);
        mantissa = mantissa + ((float) b) / denom;
        denom *= 2;
    }

    putchar('\n');
    printf("|-");
    for (int i = 0; i < 31; i++) {
        printf(" -");
    }
    printf("|\n");
    printf("|s|      exp      |                  mantissa                   |\n");
    printf(" %c", neg_sign ? '-' : '+');
    printf(" 2^%-12d * %f", exponent, mantissa);
    putchar('\n');
    putchar('\n');
}

const char *show_classification(double x) {
  switch(fpclassify(x)) {
    case FP_INFINITE:  return "Inf";
    case FP_NAN:       return "NaN";
    case FP_NORMAL:    return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO:      return "zero";
    default:           return "unknown";
  }
}

int main(void) {
    printf("Floating point size assumed is correct: %d == 32\n", sizeof(float) * 8);
    putchar('\n');

    printf_info(0.F);
    printf_info(-0.F);

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(0.125F);
    printf_info(0.25F);
    printf_info(0.5F);
    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(1.F);
    printf_info(2.F);
    printf_info(4.F);
    printf_info(8.F);
    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(1.F);
    printf_info(2.F);
    printf_info(4.F);
    printf_info(8.F);
    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(0.375F);
    printf_info(0.75F);
    printf_info(1.5F);
    printf_info(3.F);
    printf_info(6.F);

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(0.1F);
    printf_info(0.2F);
    printf_info(0.4F);
    printf_info(0.8F);

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(1e+12F);
    printf_info(1e+24F);
    printf_info(1e+36F);
    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');

    printf_info(1.F/0.F);
    printf_info(-1.F/0.F);
    printf_info(0.F/0.F);

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');
    printf("denormalised values range (excluding both values and 0):\n -FLT_MIN: %e, FLT_MIN: %e\n", -FLT_MIN, FLT_MIN);
    putchar('\n');
    printf("max float range (including both values):\n -FLT_MAX: %e, FLT_MAX: %e\n", -FLT_MAX, FLT_MAX);

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');
    printf("does infinity propogate?\n inf == %f", (1.F/0.F) * 5.F);
    putchar('\n');
    printf("does -infinity propogate?\n inf == %f", (-1.F/0.F) * 5.F);
    putchar('\n');
    printf("does nan propogate?\n nan == %f", (0.F/0.F) * 0.5F);
    putchar('\n');

    for (int i = 0; i < 32*2+1; i++)
        putchar('-');
    putchar('\n');
    printf("infinity classification:\n %s", show_classification(1.F/0.F));
    putchar('\n');
    printf("nan classification:\n %s", show_classification(0.F/0.F));
    putchar('\n');

    return 0;
}
