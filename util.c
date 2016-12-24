#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char base64_arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

list_t * list_init() {
    list_t *list = calloc(1, sizeof(list_t));
    list->head = list->tail = 0;
    list->length = 0;
    return list;
}

void enqueue(list_t *list, uint8_t value) {
    if(!list) return;

    item_t *item = calloc(1, sizeof(item_t));
    item->value = value;

    if(!list->head) {
        list->head = list->tail = item;
    } else {
        list->tail->next = item;
        list->tail = item;
    }
    list->length++;
}

uint8_t get_Idx(list_t *list, uint32_t idx) {
    if(!list) return 0;

    item_t *item;
    for (item = list->head; item && idx; idx--) item = item->next;

    if (item) {
        return item->value; 
    } else {
        return 0;
    }
}

uint8_t dequeue(list_t *list) {
    if(!list || !list->head) return 0;

    item_t *item = list->head;
    list->head = item->next;
    list->length--;
    uint8_t ret = item->value;
    free(item);
    return ret;
}

void push(list_t *list, uint8_t value) {
    if(!list) return;

    item_t *item = calloc(1, sizeof(item_t));
    item->value = value;

    if(!list->head) {
        list->head = list->tail = item;
    } else {
        item->next = list->head;
        list->head = item;
    }
    list->length++;
}

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

uint8_t hex_to_int(char c) {
    if(c >= 'a' && c <= 'f') return 10 + c-'a';
    if(c >= 'A' && c <= 'F') return 10 + c-'A';
    if(c >= '0' && c <= '9') return c-'0';
    return 0;
}

void free_list(list_t *list) {
    while(list->head) {
        dequeue(list);
    }
    free(list);
}
