#include "stdio.h"


#include "../include_lib.h"
#include "include_tests.h"


typedef void (*Test)(void);
int main(){
    Test tests[] = {ex1};
    for(int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        tests[i]();
    return 0;
}