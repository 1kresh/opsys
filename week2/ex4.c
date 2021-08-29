#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2) {
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

int main() {
    char s[256];
    printf("Enter the 1st number:\n");
    fgets(s, 256, stdin);
    int n1 = atoi(s);
    printf("Enter the 2nd number:\n");
    fgets(s, 256, stdin);
    int n2 = atoi(s);
    printf("1st number: %d | 2nd number: %d\n", n1, n2);
    swap(&n1, &n2);
    printf("Swap\n");
    printf("1st number: %d | 2nd number: %d\n", n1, n2);
    return 0;
}
