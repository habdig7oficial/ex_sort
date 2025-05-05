

int *min(int arr[], int len){
    int *min = &arr[0];
    for(int i = 0; i < len; i++)
        if(arr[i] < *min)
            min = &arr[i];
    return min;
}

void selection_sort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        int *v_min = min(&arr[i], len-i);
        if(*v_min < arr[i]){
            int aux = *v_min;
            *v_min = arr[i];
            arr[i] = aux;
        }

    }
}