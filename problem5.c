#include "utils/list.h"
#include "utils/list_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        printf("Matasano Problem 5; Usage: %s [PLAINTEXT] [KEY]\n", argv[0]);
        return -1;
    }    

    list_t *plaintext = list_init();
    list_t *key = list_init();

    for (int i = 0; argv[1][i] ; i++) {
        enqueue(plaintext, argv[1][i]);
    }

    for (int i = 0; argv[2][i]; i++) {
        enqueue(key, argv[2][i]);
    }

    printf("Plaintext: ");
    print_char(plaintext);

    printf("Key: ");
    print_char(key);

    printf("Output String:  ");
    list_t *elem_xor = list_xor(plaintext, key);
    print_raw(elem_xor);

    free_list(plaintext);
    free_list(key);
    free_list(elem_xor);
    return 0;
}
