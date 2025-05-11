#include "pthread.h"
#include "stdlib.h"

struct ArrArgs {
    int *arr;
    int len;
};

void merge(int v1[], int len_left, int v2[], int len_right, int new_arr[]) {
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    while (i1 < len_left && i2 < len_right) {
        if (v1[i1] < v2[i2]) {
        new_arr[i] = v1[i1];
        i1++;
        } else {
        new_arr[i] = v2[i2];
        i2++;
        }
        i++;
    }
    while (i1 < len_left) {
        new_arr[i] = v1[i1];
        i1++;
        i++;
    }
    while (i2 < len_right) {
        new_arr[i] = v2[i2];
        i2++;
        i++;
    }
}

void *merge_sort(void *ptr_args){

    struct ArrArgs args = *(struct ArrArgs *) ptr_args;

    printf("bg: %d \n", args.len);
    for(int i = 0; i < args.len; i++)
        printf("%d\n", args.arr[i]);
    printf("end: \n");

    if(args.len == 1)
        return &args.arr[0];

    int div = args.len / 2;

    struct ArrArgs args_left = {
        .arr = &args.arr[0],
        .len = div
    };
    struct ArrArgs args_right = {
        .arr = &args.arr[div],
        .len = args.len - div
    };
    pthread_t th_1, th_2;

    pthread_create(&th_1, NULL, &merge_sort, &args_left); // left
    pthread_create(&th_2, NULL, &merge_sort, &args_right); // right

    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);

    int *new_arr = malloc(args.len * sizeof(args.arr[0]));

    merge(args_left.arr, args_left.len, args_right.arr, args_right.len, new_arr);

    printf("\n");
    for(int i = 0; i < args.len; i++){
        args.arr[i] = new_arr[i];
    }
    printf("\n");

    free(new_arr);

    return new_arr;
    
}