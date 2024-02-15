#include <stdlib.h>
#include <string.h>

void rotleft(unsigned char* bytes, size_t len, size_t data_size, size_t n) {
    unsigned char* buffer = malloc(data_size);
    for (size_t i = 0; i < n; i++) {
        memcpy(buffer, bytes, data_size);
        memmove(bytes, bytes + data_size, len - data_size);
        memcpy(bytes + len - data_size, buffer, data_size);
    }
    free(buffer);
}

// we could perhaps replace it with (though probably it's best to do the former):
void rotleft_alt(unsigned char* bytes, size_t len, size_t data_size, size_t n) {
    unsigned char* buffer = alloca(data_size);
    for (size_t i = 0; i < n; i++) {
        memcpy(buffer, bytes, data_size);
        memmove(bytes, bytes + data_size, len - data_size);
        memcpy(bytes + len - data_size, buffer, data_size);
    }
}
