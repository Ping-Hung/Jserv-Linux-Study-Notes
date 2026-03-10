#include <stdio.h>

#define log_sizeof(expr) printf("%s == %lu\n", #expr, expr)

int main(void)
{
    printf("basic types:\n");
    log_sizeof(sizeof(char));
    log_sizeof(sizeof(short));
    log_sizeof(sizeof(int));
    log_sizeof(sizeof(long));

    log_sizeof(sizeof(float));
    log_sizeof(sizeof(double));

    printf("pointers:\n");
    log_sizeof(sizeof(char *));
    log_sizeof(sizeof(void *));
    log_sizeof(sizeof(short *));
    log_sizeof(sizeof(int *));
    log_sizeof(sizeof(long *));

    log_sizeof(sizeof(float *));
    log_sizeof(sizeof(double *));

    return 0;
}

