#ifndef LIST_OPERATIONS_H_
#define LIST_OPERATIONS_H_
#include "list.h"

list_t * base64_encode(list_t *list);
list_t * list_xor(list_t *list1, list_t *list2);
list_t * single_xor(list_t *list1, uint8_t key);
void print_raw(list_t *list);
void print_char(list_t *list);

#endif
