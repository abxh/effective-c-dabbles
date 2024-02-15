#include <stdlib.h>

int main(void) {
    {
    void* p; // p is in the stack with some default value
    p = malloc(1); // 1 byte of memory is allocated in the heap,
                   // and 'p' is set to "point" to that memory address
    free(p); // the 1 byte of memory is freed
    }
}
