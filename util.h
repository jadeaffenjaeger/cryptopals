#ifndef UTIL_H_
#define UTIL_H_ 
#include <stdint.h>

typedef struct item_t{
    struct item_t *next;
    uint8_t value;
} item_t;

typedef struct {
    item_t *head;
    item_t *tail;
    uint32_t length;
} list_t;


list_t * list_init();
void enqueue(list_t *list, uint8_t value);
uint8_t dequeue(list_t *list);
void push(list_t *list, uint8_t value);
void free_list(list_t *list);
list_t * base64_encode(list_t *list);
void print_raw(list_t *list);
void print_char(list_t *list);
uint8_t hex_to_int(char c);

#endif
