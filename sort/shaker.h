#include "stdbool.h"

void shaker_sort(int arr[], int len){
    int start = 0;
    int end = len - 1;
    bool swaped = true;

    while(swaped){
        swaped = false;
        for(int j = start; j < len - 1; j++){
            if(arr[j] > arr[j + 1]){
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                swaped = true;
            }
        }

        if(!swaped)
            break;

        swaped = false;
        end--;

        for(int j = end - 1; j > start; j--){
            if(arr[j] < arr[j - 1]){
                int aux = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = aux;
                swaped = true;
            }
        }
        start++;

    }


}