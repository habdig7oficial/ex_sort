#include "assert.h"
#include "stdio.h"
#include "stdbool.h"
#include "../../helpers/delimiter.h"


void find_min(){
    hr("FIND MIN", 15);
    int arr[] = {5, 2, 4, 10, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *v_min = min(arr, len);
    assert(*min(arr, len) == 1);
    printf("%d", *min(arr, len));
}

void ex4(){
    hr("SELECTION ASC", 15);
    int arr[] = {5, 2, 4, 10, 1, 2, 2, -1};
    int sorted[] = {-1, 1, 2, 2, 2, 4, 5, 10};


    int len = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, len, true);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
        assert(arr[i] == sorted[i]);
    }
}

void ex5(){
    hr("SELECTION DESC", 15);
    int arr[] = {5, 2, 4, 10, 1, 2, 2, -1};
    int sorted[] = {10, 5, 4, 2, 2, 2, 1, -1};


    int len = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, len, false);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
       assert(arr[i] == sorted[i]);
    }
}