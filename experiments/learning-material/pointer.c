#include <stdio.h>
#include <stdlib.h>

int *foo(void)
{
    static int x = 10;  /* effecitive, well-defined behavior (x: static storage class)*/
    // int x = 10; /* undefined behavior, accessing an object outside of its lifetime (x: automatic storage class)*/
    return &x;
}

int main(void)
{
    printf("printing pointer (raw address)...\n"
           "foo() == %p\n", (void *)foo());
    printf("printing value at pointer (dereferenced address)...\n"
           "*(foo()) == %d\n", *(foo()));
    return EXIT_SUCCESS;
}
