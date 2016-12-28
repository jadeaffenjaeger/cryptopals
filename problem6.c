#include "utils/list.h"
#include "utils/list_operations.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 1024

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Matasano Problem 6; Usage: %s [FILE]\n", argv[0]);
        return -1;
    }    

    FILE *fd = fopen(argv[1], "r");
    char buffer[BUF_LEN];
    list_t *list = list_init();

    /*read file into list*/
    while (fgets(buffer, BUF_LEN, fd)) {
        list_t *temp = read_char(buffer);
        list = merge(list, temp);
    }

    /*test key lengths*/
    for (int i = 1; i < 41; i++) {
        list_t *temp1 = list_init();
        list_t *temp2 = list_init();
        list_t *temp3 = list_init();
        list_t *temp4 = list_init();
        for (int j = 0; j < i; j++) {
           enqueue(temp1, get_Idx(list, j));
           enqueue(temp2, get_Idx(list, i + j));
           enqueue(temp3, get_Idx(list, 2*i + j));
           enqueue(temp4, get_Idx(list, 3*i + j));
        }          
        float dist1 = (float) list_hamming_dist(temp1, temp2)/i;
        float dist2 = (float) list_hamming_dist(temp3, temp4)/i;
        printf("Lenght: %d, norm: %f v1: %f v2 %f\n", i, (dist1 + dist2)/2, dist1, dist2);
        free_list(temp1);
        free_list(temp2);
        free_list(temp3);
        free_list(temp4);
    }



    free_list(list);
    return 0;
}
