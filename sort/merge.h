#include "pthread.h"

struct ArrArgs {
    int *arr;
    int len;
};

void *merge_sort(void *ptr_args){

    printf("Lorem %d\n\n\n", ((struct ArrArgs *) ptr_args) -> len);

    /*
        printf("bg: \n");
    for(int i = 0; i < len; i++)
        printf("%d\n", arr[i]);
    printf("end: \n");
    
    if(len == 1)
        return &arr[0];

    merge_sort(&arr[0], len / 2);             //direita
    merge_sort(&arr[(len / 2) + 1], len / 2);              //right

 */

    /*
    for(int i = 0; i < len - 1; i++){
        if(arr[i] < arr[(i + len / 2)]){

        }
    }
    */
    
}