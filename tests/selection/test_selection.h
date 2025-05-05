#include "assert.h"
#include "stdio.h"

void find_min(){
    printf("--------------- FIND MIN ---------------");
    int arr[] = {5, 2, 4, 10, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *v_min = min(arr, len);

    printf("\n%d", *v_min);
}

void ex4(){
    printf("------------- SELECTION -------------\n");
    int arr[] = {5, 11, 4, 10, 1};
    int sorted[] = {1, 2, 4, 5, 10,};
    int len = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, len);
    for(int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
      //  assert(arr[i] == sorted[i]);
    }
}