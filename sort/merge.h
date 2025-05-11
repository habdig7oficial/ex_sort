#include "pthread.h"
#include "stdlib.h"

struct ArrArgs {
    int *arr;
    int len;
};

void merge(int v1[], int len_left, int v2[], int len_right, int new_arr[]) {
    int i_left = 0;
    int i_right = 0;
    int i = 0;
    while (i_left < len_left && i_right < len_right) {
        if (v1[i_left] < v2[i_right]) {
            new_arr[i] = v1[i_left];
            i_left++;
        } else {
            new_arr[i] = v2[i_right];
            i_right++;
        }
        i++;
    }
    while (i_left < len_left) {
        new_arr[i] = v1[i_left];
        i_left++;
        i++;
    }
    while (i_right < len_right) {
        new_arr[i] = v2[i_right];
        i_right++;
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

void merge_sort_iter(int arr[], int len) {
  int* tmp = (int*)malloc(len * sizeof(int));

  int width = 1;
  while (width < len) {
    for (int i = 0; i < len; i += (2 * width)) {
      int len_left = width;
      int len_right = (i + (2 * width) > len) ? len - i - width : width;

      merge(&arr[i], len_left, &arr[i + len_left], len_right, &tmp[i]);

    }

    for (int i = 0; i < len; i++) {
      arr[i] = tmp[i];
    }

    width *= 2;
  }

  free(tmp);
}