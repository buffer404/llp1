#ifndef LLP1_TEST_DATA_H
#define LLP1_TEST_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char* get_test_data(int data_type, int count);

FILE *open_file();

char* get_input();

void check_input();


#endif //LLP1_TEST_DATA_H
