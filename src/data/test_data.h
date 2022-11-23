#ifndef LLP1_TEST_DATA_H
#define LLP1_TEST_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "../interface/configuration.h"

char** get_test_data_name();

FILE *open_file();

char* get_input();

void check_input();

char get_string_count(char *data);


#endif //LLP1_TEST_DATA_H
