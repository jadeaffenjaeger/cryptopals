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
    while (fgets(buffer, BUF_LEN, fd)) {
        list_t *temp = read_char(buffer);
        list = merge(list, temp);
    }


    print_char(list);
    list_t *test_out = base64_decode(list);
    printf("Length: %d\n", test_out->length);
    print_raw(test_out);

    /*free_list(test_out);*/
    free_list(list);
    return 0;
}
