#include "stdio.h"


#include "../include_lib.h"
#include "include_tests.h"


typedef void (*Test)(void);
int main(){
    Test tests[] = {ex1, ex2, ex3, find_min, ex4, ex5, ex9, ex12, ex13};
    for(int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        tests[i]();
    return 0;
}