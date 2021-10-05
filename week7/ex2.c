#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array = calloc(0, sizeof(int));
    printf("Enter N: ");
    scanf("%d", &n);
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            printf("Allocating memory for %d-th elem\n", i + 1);
            array = realloc(array, (i + 1) * sizeof(int));
            printf("%d-th element is %d\n", i + 1, i);
            array[i] = i;
        }
    }
    printf("Free memory\n");
    free(array);
    return 0;
}
