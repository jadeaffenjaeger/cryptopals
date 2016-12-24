#include <stdio.h>
#include <ctype.h>
#include "list_operations.h"
#include "list.h"

const char base64_arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const float letter_freq[] = {8.2, 1.4, 2.8, 4.3, 12.7, 2.2, 2, 6, 7, 0.2, 0.8, 4, 2.4, 6.8, 7.5, 2, 0.01, 6, 6.3, 9, 2.7, 1, 2.4, 0.1, 2, 0.07};

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

float score_list(list_t *list) {
    float score = 0;
    for (uint32_t i = 0; i < list->length; i++ ) {
        score += score_char(get_Idx(list, i));
    }
    return score;
}

float score_char(char c) {
    /*Weird ASCII*/
    if(c < ' ' || c > '~') return -20;

    /*Spaces:*/
    if (c == ' ') return 20;

    /*Printable ASCII*/
    if((c < 'A')|| (c > 'Z' && c < 'a') || (c > 'z')) return 5;

    float score = 5;
    /*reduce score for uppercase*/
    if(c >= 'A' && c <= 'Z') {
        score = 3;
        c = tolower(c);
    }

    score *= letter_freq[c - 'a'];
    return score;
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

