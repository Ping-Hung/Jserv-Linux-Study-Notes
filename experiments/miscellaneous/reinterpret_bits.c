#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    /* Given a (binary) pattern 0x80, write code to reinterpret it as different
     * data types (signed and unsigned char in this example) */

    assert((char)0x80 == (char)(1 << 7));

    unsigned value = 0x80;
    printf("value = 0x%x\n", value);

    printf("\nAccessing casted address (UB, potentially degerous trick)\n");
    printf("value as char %d\nvalue as unsigned char %u\n",
           *(char *)&value, *(unsigned char *)&value);

    union {
        char as_char;
        unsigned char as_uchar;
    } u_value = {.as_char = (char)0x80};
    printf("\nUnion trick\n"
           "value as char %d\nvalue as unsigned char %u\n", 
           u_value.as_char, u_value.as_uchar);

    union {int as_int; float as_float;} u_test = {.as_float = 1.0f};
    printf("u_test = {\n"
           "           .as_int = %d\n"
           "           .as_float = %f\n"
           "         }\n",
           u_test.as_int, u_test.as_float);

    return EXIT_SUCCESS;
}
