#include "util.h"

void print_arr(int arr[], size_t len, char *name) {
    size_t i = 0;

    while (len > i)
    {
        printf("%s[%ld]: %d\n", name, i, arr[i]);
        i++;
    }
}
