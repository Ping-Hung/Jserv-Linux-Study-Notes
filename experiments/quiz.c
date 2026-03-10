#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct task_struct_demo {
    int pid;
    int prio;
    struct list_head {
        struct list_head *prev, *next;
    } run_list;
    char comm[16];
};

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int *pi = arr;
    int *end = arr + 4;
    char *pc = (char *)end - (char *)pi;
    struct task_struct_demo tsd = { 0 };

    ptrdiff_t d1 = end - pi;
    ptrdiff_t d2 = (char *)end - (char *)pi;
    size_t offset = offsetof(struct task_struct_demo, run_list);
    return 0;
}
