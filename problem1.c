#include "list.h"
#include "list_operations.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Matasano Problem 1; Usage: %s [INPUT STRING]\n", argv[0]);
    }    

    list_t *list = list_init();

    for (int i = 0; argv[1][i]; i++) {
        enqueue(list, hex_to_int(argv[1][i]));
    }

    printf("Input String:  ");
    print_raw(list);

    printf("Output String: ");
    list_t *b64 = base64_encode(list);
    print_char(b64);

    free_list(b64);
    free_list(list);
    return 0;
}
