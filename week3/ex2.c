#include <stdio.h>

#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0])) 


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int arr[], int arr_len) {
    for (int i = 0 ; i < arr_len - 1; i++) {
        for (int j = 0 ; j < arr_len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {0, 4, 2, 5, 1, 8, 3, 9, 7, 6};
    printf("Initial array:\n");
    print_array(arr, ARR_SIZE(arr));
    bubble_sort(arr, ARR_SIZE(arr));
    printf("Sorted array:\n");
    print_array(arr, ARR_SIZE(arr));
    return 0;   
}
