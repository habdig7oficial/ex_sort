

int *min(int arr[], int len){
    int *min = &arr[0];
    for(int i = 0; i < len; i++)
        if(arr[i] < *min)
            min = &arr[i];
    return min;
}

int selection_sort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        int *v_min = min(&arr[i], len-i);
        printf("Vmin: %d\n", *v_min);
        int aux = *v_min;
        *v_min = arr[i];
        arr[i] = aux;

        for(int j = 0; j < len; j++)
        printf("%d ", arr[j]);
    }
}