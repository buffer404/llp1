#include "ui/interactive.h"
#include "interface/basic_crud.h"
#include "interface/crud_interface.h"
#include "data/test_data.h"


int main(int argc, char** argv) {
    FILE *file;
    open_empty_file("simple.txt", &file);

    size_t* pattern_size = malloc(sizeof(size_t));

    int type_data = get_string_count(pattern_size);

    char **pattern = malloc(sizeof(char *) * (*pattern_size));
    uint32_t *types = malloc(sizeof (uint32_t) * 1);
    size_t *sizes = malloc(sizeof (size_t) * (*pattern_size));
    uint64_t* fields = malloc(sizeof(uint64_t) * (*pattern_size));
    uint64_t* parent_id = malloc(sizeof(uint64_t) * (*pattern_size));

    types[0] = type_data;

    get_test_data(pattern, sizes, fields, parent_id, type_data);

    init_empty_file(file, &pattern[0], types, 1, &sizes[0]);



    //uint64_t* test = malloc(sizeof(uint64_t) );
    //test[0] = 1025;
//

    add_tuple(file, &fields[0], parent_id[0]);

    for (int i = 0; i < *pattern_size-1; ++i) {
        add_tuple(file, &fields[i], parent_id[i]);
    }

    print_tree_header_from_file(file);
    print_tuple_array_from_file(file);


//    uint64_t* test = malloc(sizeof(uint64_t) * 1);
//    test[0] = 1024;
//
//    for (int i = 0; i < *pattern_size; ++i) {
//        printf("%lu\n", parent_id[i]);
//        //add_tuple(file, test, parent_id[i]);
//    }




   // printf("%lu", strlen(data_name));
   // char **pattern = malloc(sizeof(char *) * strlen(data_name));


//    // init header
//    char *par1 = "Code";
//    char *par2 = "Name";
//    char **pattern = malloc(sizeof(char *) * 2);
//    pattern[0] = par1;
//    pattern[1] = par2;
//    size_t pattern_size = 2;
//    size_t *sizes = malloc(sizeof (size_t) * 2);
//    sizes[0] = 4; //len 1st par
//    sizes[1] = 4; //len 2nd par
//    uint32_t *types = malloc(sizeof (uint32_t) * 2);
//    types[0] = 1; // int
//    types[1] = 3; // string
//    init_empty_file(file, pattern, types, pattern_size, sizes);
//
//
//
//
//
//
//    // tuple data
//    uint64_t* fields = malloc(sizeof(uint64_t) * 2);
//
//    // init 1st tuple
//    fields[0] = 1024;
//    char* str = "Мега";
//    fields[1] = (uint64_t) str;
//    add_tuple(file, fields, 1298);
//
//    // init 2nd tuple
//    fields[0] = 123;
//    str = "Чепух";
//    fields[1] = (uint64_t) str;
//    add_tuple(file, fields, 3);
//
//    fields[0] = 666;
//    update_tuple(file, 0, &fields[0], 0);
//
//
//    print_tree_header_from_file(file);
//    print_tuple_array_from_file(file);
//






//    uint64_t *fieldss;
//    get_tuple(file, &fieldss, 0);
//
//    struct result_list_tuple *result = NULL;
//    uint64_t cond = 123;
//    find_by_field(file, 0, &cond, &result);
//    printf("--- FIND RESULT ---\n");
//    if (result != NULL) printf("%lu\n", (uint64_t) (*result).value->header.parent);
//    else printf("no result present\n");
//
//    result = NULL;
//    find_by_field(file, 1, (uint64_t *) str, &result);
//    printf("--- FIND RESULT ---\n");
//    if (result != NULL) printf("%lu\n", (uint64_t) (*result).value->header.parent);
//    else printf("No result present\n");
//
//    result = NULL;
//    cond = 1024;
//    find_by_field(file, 0, &cond, &result);
//    printf("--- FIND RESULT ---\n");
//    if (result != NULL) printf("%lu\n", (uint64_t) (*result).value->header.parent);
//    else printf("No result present\n");
//
//    result = NULL;
//    find_by_parent(file, 3, &result);
//    printf("--- FIND RESULT ---\n");
//    if (result != NULL) printf("%lu\n", (uint64_t) (*result).value->header.parent);
//    else printf("No result present\n");
//
//    result = NULL;
//    find_by_parent(file, 1298, &result);
//    printf("--- FIND RESULT ---\n");
//    if (result != NULL) printf("%lu\n", (uint64_t) (*result).value->header.parent);
//    else printf("No result present\n");
//
//    cond = 10;
//    update_tuple(file, 0, &cond, 0);
//
//    char *new_string = "Точно не Чепух";
//    update_tuple(file, 1, (uint64_t *) new_string, 1);
//
//    print_tuple_array_from_file(file);
    /*int flag = 0;
    char* filename;
    if (argc > 3){
        printf("Too many args!");
        return 0;
    }
    for (size_t i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (flag > 0) {
                printf("Too many flags!");
                return 0;
            } else {
                flag = argv[i][1];
            }
        } else {
            filename = argv[i];
        }
    }
    if (flag == 'i'){
        interactive_mode(filename);
    }*/
    return 0;
}
