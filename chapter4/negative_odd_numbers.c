#include <stdbool.h>

bool is_odd(int n) {
    return n % 2 == 1; // fails for negative numbers.
}

// truncating division (which C uses), makes it so the remainder
// has the same sign as the dividend

bool is_odd_v2(int n) {
    return n % 2 == -1 || n % 2 == 1; // correct
}

bool is_odd_v3(int n) {
    return n % 2 != 0; // correct
}
