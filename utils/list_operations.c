#include <stdio.h>
#include "list_operations.h"
#include "list.h"

const char base64_arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

list_t * base64_encode(list_t *list) {
    if(!list) return 0;
    
    list_t *b64 = list_init();

    for (uint32_t i = 0; i < list->length; i +=3 ) {
       uint8_t b1 = get_Idx(list, i);
       uint8_t b2 = get_Idx(list, i+1);
       uint8_t b3 = get_Idx(list, i+2);

       uint8_t ch1 = (b1 << 2) | (b2 >> 2);
       uint8_t ch2 = ((b2 & 0b11) << 4) | b3;

       if(ch1 < 64) enqueue(b64, (uint8_t) base64_arr[ch1]);
       if(ch2 < 64) enqueue(b64, (uint8_t) base64_arr[ch2]);
    }

    return b64;

}

list_t * single_xor(list_t *list1, uint8_t key) {
    if(!list1) return 0;

    list_t *ret = list_init();

    for (uint32_t i = 0; i < list1->length; i++ ) {
        enqueue(ret, get_Idx(list1, i) ^ key);
    }

    return ret;
}

list_t * list_xor(list_t *list1, list_t *list2) {
    if(!list1 || !list2) return 0;

    list_t *ret = list_init();

    for (uint32_t i = 0; i < list1->length; i++ ) {
        enqueue(ret, get_Idx(list1, i) ^ get_Idx(list2, i));
    }

    return ret;
}

void print_char(list_t *list) {
    if(!list) return;

    for (uint32_t i = 0; i < list->length; i++) {
        printf("%c", (char)get_Idx(list, i));
    }
    printf("\n");
}

void print_raw(list_t *list) {
    if(!list) return;

    for (uint32_t i = 0; i < list->length; i++) {
        printf("%X", get_Idx(list, i));
    }
    printf("\n");
}
