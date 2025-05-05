#if !defined __delimiter_header__
#define __delimiter_header__
void hr(char str[], int len){
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("-");
    printf(" %s ", str);
    for(int i = 0; i < len; i++)
        printf("-");

    printf("\n");
}

#endif