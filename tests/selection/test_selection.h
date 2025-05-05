#include "assert.h"
#include "stdio.h"

void find_min(){
    int arr[] = {5, 2, 4, 10, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *v_min = min(arr, len);

    printf("%d", *v_min);
}

/*
void ex4(){
    int arr[] = {5, 2, 4, 10, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, len);
    for(int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }
}*/