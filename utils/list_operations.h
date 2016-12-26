#ifndef LIST_OPERATIONS_H_
#define LIST_OPERATIONS_H_
#include "list.h"

list_t * base64_encode(list_t *list);
list_t * base64_decode(list_t *list);
void base64_decode_frame(char input[4], uint8_t output[3]);

list_t * list_xor(list_t *list1, list_t *list2);
list_t * single_xor(list_t *list1, uint8_t key);

list_t * read_char(const char * buffer);
list_t * read_hex(const char * buffer);

uint8_t hamming_weight(uint8_t val);
uint8_t byte_hamming_dist(uint8_t b1, uint8_t b2);
uint32_t list_hamming_dist(list_t *list1, list_t *list2);

float score_list(list_t *list);
float score_char(char c);

list_t * merge(list_t *list1, list_t *list2);

void print_raw(list_t *list);
void print_char(list_t *list);

#endif
