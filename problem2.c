#include "utils/list.h"
#include "utils/list_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        printf("Matasano Problem 2; Usage: %s [INPUT STRING1] [INPUT STRING2]\n", argv[0]);
        return -1;
    }    

    list_t *list1 = list_init();
    list_t *list2 = list_init();

    for (int i = 0; argv[1][i] && argv[2][i]; i++) {
        enqueue(list1, hex_to_int(argv[1][i]));
        enqueue(list2, hex_to_int(argv[2][i]));
    }

    printf("Input String 1: ");
    print_raw(list1);

    printf("Input String 2: ");
    print_raw(list2);

    printf("Output String:  ");
    list_t *elem_xor = list_xor(list1, list2);
    print_raw(elem_xor);

    free_list(list1);
    free_list(list2);
    free_list(elem_xor);
    return 0;
}
