#include "utils/list.h"
#include "utils/list_operations.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 1024

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Matasano Problem 4; Usage: %s [FILE PATH]\n", argv[0]);
        return -1;
    }    

    FILE *fd = fopen(argv[1], "r");

    list_t *best_candidate;
    float best_score = -1000000;
    uint8_t best_key = 0;
    char buffer[BUF_LEN];

    while(fgets(buffer, BUF_LEN, fd)) {

        list_t *list = list_init();

        /*read buffer into list*/
        for (int i = 0; buffer[i] && buffer[i+1]; i += 2) {
            uint8_t val     = hex_to_int(buffer[i]) << 4;
            val             |= hex_to_int(buffer[i+1]);
            enqueue(list, val);
        }

        /*try decryption*/
        for (int i = 0; i < 256; i++) {
            list_t *decrypt = single_xor(list, (uint8_t) i);
            float score = score_list(decrypt);
            if(score > best_score) {
                if(best_candidate) free_list(best_candidate);
                best_candidate = decrypt;
                best_score = score;
                best_key = i;
            } else {
                free_list(decrypt);
            }
        }
        free_list(list);
    }

    printf("Best Key: %x \n", best_key);
    printf("Output String: ");
    print_char(best_candidate);
    free_list(best_candidate);
    return 0;
}
