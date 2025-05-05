#include "stdio.h"


#include "../include_lib.h"
#include "include_tests.h"


typedef void (*Test)(void);
int main(){
    Test tests[] = { find_min, ex4};
    for(int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        tests[i]();
    return 0;
}