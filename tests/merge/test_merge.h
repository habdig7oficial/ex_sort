void ex9(){
    hr("MERGE", 15);
    int arr[] = {5, 2, 4, 10, 1, 2, 2,};
    int sorted[] = { 1, 2, 2, 2, 4, 5, 10};


    int len = sizeof(arr) / sizeof(arr[0]);

    struct ArrArgs props = {
        .arr = arr,
        .len = len
    };

    merge_sort(&props);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
       // assert(arr[i] == sorted[i]);
    }
}