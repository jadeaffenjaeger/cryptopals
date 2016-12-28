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

typedef struct prio_item_t{
    struct prio_item_t *next;
    uint8_t value;
    float prio;
} prio_item_t;

typedef struct {
    prio_item_t *head;
} prio_list_t;

list_t * list_init();
void enqueue(list_t *list, uint8_t value);
uint8_t dequeue(list_t *list);
void push(list_t *list, uint8_t value);
uint8_t get_Idx(list_t *list, uint32_t idx);
void free_list(list_t *list);
uint8_t hex_to_int(char c);

#endif
