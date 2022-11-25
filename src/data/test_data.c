#include "test_data.h"

int get_string_count(size_t* pattern_size){
    FILE *df = open_file();

    char* cur_line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&cur_line, &len, df);

    char* space = strchr(cur_line, ' ');
    *pattern_size = atoi(substr(cur_line, space-cur_line, strlen(cur_line)));

    int result = get_type(substr(cur_line, 0, space-cur_line));

    fclose(df);

    return result;
}

void get_test_data(char **pattern, size_t *sizes, uint64_t* fields, uint64_t* parent_id, int type){
    FILE *df = open_file();
    get_input(df, pattern,  sizes, fields, parent_id, type);

    fclose(df);
}

FILE *open_file(){
    FILE *df;
    df = fopen ("data.txt","r");
    if (df == NULL) {
        printf ("Файл не существует \n");
        _Exit (EXIT_FAILURE);
    }
}

void get_input(FILE *df, char **pattern, size_t *sizes, uint64_t* fields, uint64_t* parent_id, int type){
    char* cur_line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t m_size = 1;
    int first_string = -1;

    while ((read = getline(&cur_line, &len, df)) != -1) {
        if (first_string != -1){
            char* first_space = strchr(cur_line, ' ');
            char* second_space = strrchr(cur_line, ' ');
            char* equally = strchr(cur_line, '=');
            char* second_equally = strrchr(cur_line, '=');

            parent_id[first_string] = atoi(substr(cur_line, 0, first_space-cur_line));

            fields[first_string] = get_field(type, substr(cur_line, equally-cur_line+1, second_space-cur_line));

            sizes[first_string] = strlen(substr(cur_line, second_equally-cur_line+1, strlen(cur_line)-2));

            pattern[first_string] = substr(cur_line, second_equally-cur_line+1, strlen(cur_line)-1);

        }
        first_string++;
    }

}

char* substr(const char *src, int m, int n) {
    // get the length of the destination string
    int len = n - m;

    // allocate (len + 1) chars for destination (+1 for extra null character)
    char *dest = (char*)malloc(sizeof(char) * (len + 1));

    // extracts characters between m'th and n'th index from source string
    // and copy them into the destination string
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }

    // null-terminate the destination string
    *dest = '\0';

    // return the destination string
    return dest - len;
}

uint64_t get_field(int type, char* str){
    switch (type) {
        case 0:
            return (uint64_t) str;
        case 1:
            return (uint64_t) atoi(str);
        case 2:
            return (uint64_t) atof(str);
        case 3:
            return (uint64_t) str;
        default:
            printf ("Неверный формат входных данных \n");
            _Exit (EXIT_FAILURE);
    }
}

int get_type(char* str_type){
    if (!strcmp(str_type, "Boolean")){
        return 0;
    } else if (!strcmp(str_type, "Integer")){
        return 1;
    } else if (!strcmp(str_type, "Float")){
        return 2;
    } else if (!strcmp(str_type, "String")){
        return 3;
    } else{
        printf ("Неверный формат входных данных \n");
        _Exit (EXIT_FAILURE);
    }
}

void check_input();
