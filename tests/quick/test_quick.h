#include "assert.h"
#include "stdio.h"
#include "../../helpers/delimiter.h"

void ex12(){
    hr("QUICK", 15);
    int arr[] = {5, 2, 4, 10, 1, -1};
    int sorted[] = {-1, 1, 2, 4, 5, 10};


    int len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, len, false);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
        assert(arr[i] == sorted[i]);
    }
}
void ex13(){
    hr("QUICK rand", 15);
    int arr[] = {5, 2, 4, 10, 1, -1};
    int sorted[] = {-1, 1, 2, 4, 5, 10};


    int len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, len, true);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
        assert(arr[i] == sorted[i]);
    }
}