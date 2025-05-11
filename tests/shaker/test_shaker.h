#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "../../helpers/delimiter.h"
#include "string.h"
#include "stdbool.h"


void ex2(){
    hr("SHAKER", 15);
    int init[] = {5, 2, 4, 10, 1, 2, 2};
    int sorted[] = {1, 2, 2, 2, 4, 5, 10};


    int len = sizeof(init) / sizeof(init[0]);

    shaker_sort(init, len);
    for(int i = 0; i < len; i++){
        printf("%d - %d\n", init[i], sorted[i]);
        assert(init[i] == sorted[i]);
    }
}

struct Pacient{
    char *name;
    int priority;
};

struct BuscaBin{
    int min;
    int mid;
    int max;
};

struct Pacient *busca_priority(struct Pacient arr[], int len, int element){
    struct BuscaBin ctrl = {
        .min = 0,
        .max = len
    };
    printf("%d\n", len);
    while(ctrl.min <= ctrl.max){
        ctrl.mid = (ctrl.max + ctrl.min) / 2;
        printf("mid = %d, min = %d, max = %d ctrl = %d, element = %d\n", ctrl.mid,ctrl.min, ctrl.max, arr[ctrl.mid].priority, element);

        if(arr[ctrl.mid].priority >= element){
            ctrl.max = ctrl.mid - 1;
        }
        else if(arr[ctrl.mid].priority < element){
            ctrl.min = ctrl.mid + 1;
        }
    }
    return &arr[ctrl.mid];
}

void shaker_sort_priority(struct Pacient arr[], int len){
    int start = 0;
    int end = len - 1;
    bool swaped = true;

    while(swaped){
        swaped = false;
        for(int j = start; j < len - 1; j++){
            if(arr[j].priority < arr[j + 1].priority){
                struct Pacient aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                swaped = true;
            }
        }

        if(!swaped)
            break;

        swaped = false;
        end--;

        for(int j = end - 1; j < start; j--){
            if(arr[j].priority < arr[j - 1].priority){
                struct Pacient aux = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = aux;
                swaped = true;
            }
        }
        start++;

    }
}



void ex3(){
    hr("SHAKER PRIORIDADE EX 3", 15);

    struct Pacient init[] = {
        {
            .name = "Mateus",
            .priority = 1
        },
        {
            .name = "Cidinha",
            .priority = 10
        },
        {
            .name = "Teste",
            .priority = 3
        }
    } ;
    int len = sizeof(init) / sizeof(init[0]);

    struct Pacient * arr = malloc(len * sizeof(struct Pacient));

    for(int i = 0; i < len; i++)
        arr[i] = init[i];
    

    shaker_sort_priority(arr, len);

    for(int i = 0; i < len; i++){
        printf("%d\n", arr[i].priority);
    }
    // Adiciona nova pessoa

    len++;
    arr = realloc(arr, len * sizeof(struct Pacient));

 
    struct Pacient tmp = {
        .name = "New Name",
        .priority = 5
    };

    struct Pacient *ptr_shift = busca_priority(arr, len - 1, tmp.priority);

    for(int i = len; i < (ptr_shift - arr); i--)
        arr[i] = arr[i - 1];

    arr[ptr_shift - arr] = tmp;



    for(int i = 0; i < len; i++){
        printf("%s\n", arr[i].name);
        printf("%d\n", arr[i].priority);
    }


}