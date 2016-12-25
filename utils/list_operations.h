#ifndef LIST_OPERATIONS_H_
#define LIST_OPERATIONS_H_
#include "list.h"

list_t * base64_encode(list_t *list);
list_t * list_xor(list_t *list1, list_t *list2);
list_t * single_xor(list_t *list1, uint8_t key);

uint8_t hamming_weight(uint8_t val);
uint8_t byte_hamming_dist(uint8_t b1, uint8_t b2);
uint32_t list_hamming_dist(list_t *list1, list_t *list2);

float score_list(list_t *list);
float score_char(char c);

void print_raw(list_t *list);
void print_char(list_t *list);

#endif
