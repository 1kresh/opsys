#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) return 0;
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 1 + i*2; j++) {
            printf("*");
        }
        for (int j = 0; j < n-1-i; j++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
