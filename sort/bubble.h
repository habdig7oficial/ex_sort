void bubble_sort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - 1; j++){
            int aux = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = aux;
        }
    }
}