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

    printf("Hamming Distance: %d\n", list_hamming_dist(plaintext, key));

    free_list(plaintext);
    free_list(key);
    return 0;
}
