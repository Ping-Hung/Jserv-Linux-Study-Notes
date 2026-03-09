#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[3] = {1,2,3};
    int *p = a;     /* p points to the address of a[0] (&1) */
    int *q = &a[0];
    printf("%zu %zu\n", sizeof(a), sizeof(p));
    printf("%p %p\n", a, &a);   /* can identify that the values are the same,
                                   avoid using '==' operator as it involves
                                   comparing (subtracting) two pointers of
                                   different types */

    printf("p == q is %s\n", p == q ? "true" : "false");

    double x[3]; 
    p = (int *)&x[0]; 
    printf("%d\n", *(p+1));

    return EXIT_SUCCESS;
}
