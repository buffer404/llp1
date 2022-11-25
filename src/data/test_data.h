#ifndef LLP1_TEST_DATA_H
#define LLP1_TEST_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "../interface/configuration.h"

void get_test_data(char **pattern, size_t *sizes, uint64_t* fields, uint64_t* parent_id, int type);

FILE *open_file();

void get_input(FILE *df, char **pattern, size_t *sizes, uint64_t* fields, uint64_t* parent_id, int type);

void check_input();

int get_string_count(size_t* pattern_size);

char* substr(const char *src, int m, int n);

int get_type(char* str_type);

uint64_t get_field(int type, char* str);

#endif //LLP1_TEST_DATA_H
