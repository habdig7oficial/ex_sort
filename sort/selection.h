#include "stdbool.h"

int *min(int arr[], int len){
    int *min = &arr[0];
    for(int i = 0; i < len; i++)
        if(arr[i] < *min)
            min = &arr[i];
    return min;
}

int *max(int arr[], int len){
    int *v_max = &arr[0];
    for(int i = 0; i < len; i++)
        if(arr[i] > *v_max)
            v_max = &arr[i];
    return v_max;
}


void selection_sort(int arr[], int len, bool is_asc){
    if(is_asc){
        for(int i = 0; i < len - 1; i++){
            int *v_min = min(&arr[i], len-i);
            if(*v_min < arr[i]){
                int aux = *v_min;
                *v_min = arr[i];
                arr[i] = aux;
            }
        }
    }
    else {
        for(int i = 0; i < len - 1; i++){
            int *v_max = max(&arr[i], len-i);
            if(*v_max > arr[i]){
                int aux = *v_max;
                *v_max = arr[i];
                arr[i] = aux;
            }
        }
    }
}