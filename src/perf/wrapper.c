//
// Created by leonid on 30.11.2022.
//

#include "../../include/perf/wrapper.h"

void time_add_wrapper(FILE *file, uint64_t *fields, uint64_t parent_id){

    clock_t start, stop;

    start = clock();
    add_tuple(file, fields, parent_id);

    stop = clock();

    printf("%lu\n", start);
    printf("%lu\n", stop);
}
