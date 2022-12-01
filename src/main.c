#include "../include/interface/basic_crud.h"
#include "../include/data/test_data.h"

int main(int argc, char** argv) {
    FILE *file;
    open_file_anyway(&file, "simple.txt");

    size_t* pattern_size = malloc(sizeof(size_t));
    size_t* tuple_count = malloc(sizeof(size_t));
    char **pattern;
    uint32_t *types;
    size_t *sizes;

    get_test_header(&pattern, &types, pattern_size, &sizes, tuple_count);

//    printf("%zu\n", *pattern_size);
//    printf("%zu\n", *tuple_count);


    init_empty_file(file, pattern, types, *pattern_size, sizes);


//    char * line = NULL;
//    size_t len = 0;
//    ssize_t read;
//    while ((read = getline(&line, &len, fp)) != -1) {
//        printf("Retrieved line of length %zu:\n", read);
//        printf("%s", line);
//    }

//    char* header_line2;
//    size_t len2 = 0;
//    getline(&header_line2, &len2, fd);
//    printf("%s\n", header_line2);
//    fclose(fd);
//    printf("%d", 0);
    get_test_data(file, *tuple_count, *pattern_size, types);

    //uint64_t n = 86;
    //struct result_list_tuple *result;

    //find_by_parent(file, 0, &result);

    //print_result_list_tuple(result);

    //remove_tuple(file, 4, 0);

    //update_tuple(file, 1, &n, 1);

    print_tree_header_from_file(file);

    print_tuple_array_from_file(file);

    free(pattern_size);
    free(tuple_count);
    free(pattern);
    free(types);
    free(sizes);

    return 0;
}


