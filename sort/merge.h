#include "pthread.h"

struct ArrArgs {
    int *arr;
    int len;
};

void *merge_sort(void *ptr_args){

    struct ArrArgs args = *(struct ArrArgs *) ptr_args;

    printf("bg: %d \n", args.len);
    for(int i = 0; i < args.len; i++)
        printf("%d\n", args.arr[i]);
    printf("end: \n");

    if(args.len == 1)
        return &args.arr[0];

    struct ArrArgs args_left = {
        .arr = &args.arr[0],
        .len = args.len / 2
    };
    struct ArrArgs args_right = {
        .arr = &args.arr[(args.len / 2) + 1],
        .len = args.len / 2
    };
    pthread_t th_1, th_2;

    pthread_create(&th_1, NULL, &merge_sort, &args_left); // left
    pthread_create(&th_2, NULL, &merge_sort, &args_right); // right

    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);


    /*
    for(int i = 0; i < len - 1; i++){
        if(arr[i] < arr[(i + len / 2)]){

        }
    }
    */
    
}