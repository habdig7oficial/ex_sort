#include "assert.h"
#include "stdio.h"


void ex1(){
    int arr[] = {5, 2, 4, 10, 1};
    int sorted[] = {1, 2, 4, 5, 10,};


    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);
    for(int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
        //assert(arr[i] == sorted[i]);
    }
}