#include <stdlib.h>
#include <stddef.h> // offsetof

typedef struct {
  int i;
  int j;
  int arr[];
} S;

int main(void) {
  size_t array_size = 5;
  S* foo = malloc(offsetof(S, j) + array_size * sizeof(int));
  free(foo);
  return 0;
}
