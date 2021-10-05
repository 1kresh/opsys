#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc(void *ptr, size_t size) {
    printf("test\n");
    char *buff;
    if (size == 0) {
        free(ptr);
    } else {
        buff = malloc(size);
        if (ptr != NULL) {
            if (buff) { memcpy(buff, (char*) ptr, size); }
            free(ptr);
        }
    }
    return buff;
}

int main() {
    int* a = realloc(NULL, 3 * sizeof(int));
    a = realloc(a, 0);
    return 0;
}
