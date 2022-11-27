#include "../include/interface/basic_crud.h"
#include "../include/data/test_data.h"


int main(int argc, char** argv) {
    FILE *file;
    open_empty_file("simple.txt", &file);

    size_t* pattern_size = malloc(sizeof(size_t));
    size_t* tuple_count = malloc(sizeof(size_t));
    char **pattern;
    uint32_t *types;
    size_t *sizes;

    get_test_header(&pattern, &types, pattern_size, &sizes, tuple_count);

    get_test_data(file, *tuple_count, *pattern_size, types);

    print_tree_header_from_file(file);

    print_tuple_array_from_file(file);

    return 0;
}
