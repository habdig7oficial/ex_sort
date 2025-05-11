void ex9(){

    printf("\nJá Utiliza memoria otimizada, criando somente um novo vetor auxiliar pro merge \n");
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
       assert(arr[i] == sorted[i]);
    }
}

void ex8(){
    hr("MERGE TWO ARRAYS", 15);
    int arr1[] = {10, 20, 30 ,40};
    int arr2[] = {15, 25, 35 ,45, 55};

    int merged[] = {10, 15, 20, 25, 30, 35, 40, 45, 55};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);


    int *res = malloc(sizeof(arr1) + sizeof(arr2));

    merge(arr1, len1, arr2, len2, res);
    for(int i = 0; i < sizeof(merged) / sizeof(merged[0]); i++){
        printf("%d - %d\n", res[i], merged[i]);
        assert(res[i] == merged[i]);
    }
}

void ex11(){
    hr("MERGE ITERATIVO", 15);
    int arr[] = {5, 2, 4, 10, 1, 2, 2,};
    int sorted[] = { 1, 2, 2, 2, 4, 5, 10};

    int len = sizeof(arr) / sizeof(arr[0]);

    merge_sort_iter(arr, len);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", arr[i], sorted[i]);
       assert(arr[i] == sorted[i]);
    }
}