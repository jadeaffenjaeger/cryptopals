#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
