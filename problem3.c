#include "utils/list.h"
#include "utils/list_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Matasano Problem 3; Usage: %s [INPUT STRING1]\n", argv[0]);
        return -1;
    }    

    list_t *list = list_init();

    for (int i = 0; argv[1][i] && argv[1][i+1]; i += 2) {
        uint8_t val     = hex_to_int(argv[1][i]) << 4;
        val             |= hex_to_int(argv[1][i+1]);
        enqueue(list, val);
    }

    float best_score = -1000000;
    uint8_t best_key = 0;
    for (int i = 0; i < 256; i++) {
        list_t *decrypt = single_xor(list, (uint8_t) i);
        float score = score_list(decrypt);
        free_list(decrypt);
        if(score > best_score) {
            best_score = score;
            best_key = i;
        }
    }

    printf("Input String:  ");
    print_raw(list);

    printf("Best Key: %x \n", best_key);
    printf("Output String: ");
    list_t *out = single_xor(list, best_key);
    print_char(out);

    free_list(list);
    free_list(out);
    return 0;
}
