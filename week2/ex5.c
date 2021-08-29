#include <stdio.h>
#include <stdlib.h>

void chris_tree(int n) {
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
}

void right_triang(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void horis_triang(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n-1; i != 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }   
}

void rectangle(int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    /* 
    christmas tree`s args format: ./filename 1 a
    right triangle`s args format: ./filename 2 a
    horizontal triangle`s args format: ./filename 3 a
    rectangle`s args format: ./filename 4 a b
                             ./filename 4 a (for square)
    */

    if (argc > 2) {
        int i = atoi(argv[1]);
        int a = atoi(argv[2]);
        if (i == 1) {
            chris_tree(a);
        } else if (i == 2) {
            right_triang(a);
        } else if (i == 3) {
            horis_triang(a);
        } else if (i == 4) {
            if (argc == 4) {
                rectangle(a, atoi(argv[3]));
            } else {
                rectangle(a, a);
            }
        }
    }
    return 0;
}
