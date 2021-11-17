#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void switch_(int *a) {
    *a = (*a + 1) % 2;
}

int main() {

    int m = 0, n = 0;
    int i, j, t;
    int num, count, process;
    int flag = 0;
    Array E, A, C, R, F;

    initArray(&E, 3);
    initArray(&A, 3);
    initArray(&C, 5*3);
    initArray(&R, 5*3);
    initArray(&F, 5);

    FILE *fptr = fopen("input_dl.txt", "r");
    //FILE *fptr = fopen("input_ok.txt", "r");

    t = 0;
    while (1) {
        num = fgetc(fptr);
        if (num == '\n') {
            break;
        }
        if (t == 0) {
            m += 1;
            insertArray(&E, num - '0');
        }
        switch_(&t);
    }

    num = fgetc(fptr);
    t = 0;
    for (i = 0; i < 2*m; i++) {
        num = fgetc(fptr);
        if (t == 0) {
            insertArray(&A, num - '0');
        }
        switch_(&t);
    }

    num = fgetc(fptr);
    while (1) {
        n += 1;
        t = 0;
        for (i = 0; i < 2*m; i++) {
            num = fgetc(fptr);
            
            if (i == 0 && num == '\n') {
                flag = 1;
                break;
            }
            if (t == 0) {
                insertArray(&C, num - '0');
            }
            switch_(&t);
        }
        if (flag == 1) break;
    }
    n -= 1;

    for (i = 0; i < n; i++) {
        t = 0;
        for (j = 0; j < 2*m; j++) {
            num = fgetc(fptr);
            if (t == 0) {
                insertArray(&R, num - '0');
            }
            switch_(&t);
        }
    }

    for (i = 0; i < n; i++) {
        insertArray(&F, 0);
    }
    
    for (i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < m; j++) {
            if (R.array[i*m + j] != 0) {
                count += 1;
            }
        }
        if (count == 0) {
            F.array[i] = 1;
        }
    }
    
    count = 0;
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 0; j < m; j++){
            if (R.array[i*m + j] > A.array[j]) {
                t += 1;
            }
            if (t == 0 && F.array[i] == 0) {
                count += 1;
                process =  i;
            }
        }
    }
    
    if (count == 0) {
        process = -1;
    }

    while (process != -1) {
        F.array[process] = 1;
        for (j = 0; j < m; j++) {
            A.array[i] += C.array[process*m + j];
        }
        count = 0;
        for (i = 0; i < n; i++) {
            t = 0;
            for (j = 0; j < m; j++) {
                if (R.array[i*m + j] > A.array[j]) {
                    t += 1;
                }
                if (t == 0 && F.array[i] == 0) {
                    count += 1;
                    process =  i;
                }
            }
        }
        if (count == 0) {
            process = -1;
        }
    }
    
    count = 0;
    for (int i = 0; i < n; i++) {
        if (F.array[i] == 0) {
            count += 1;
            printf("Deadlock on process %d\n", i);
        }
    }
    if (count == 0) {
        printf("No deadlocks\n");
    }

    fclose(fptr);
    freeArray(&E);
    freeArray(&A);
    freeArray(&C);
    freeArray(&R);
    freeArray(&F);

    return 0;
}
