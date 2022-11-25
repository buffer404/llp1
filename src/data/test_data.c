#include "test_data.h"

void get_test_header(char ***pattern, uint32_t **types, size_t* pattern_size, size_t **sizes, size_t* tuple_count){
    FILE *df = open_file();

    char *cur_line = get_cur_line(df);

    *tuple_count = atoi(substr(cur_line, 0, strchr(cur_line, ' ')-cur_line));
    strcpy(cur_line, substr(cur_line, strchr(cur_line, ' ')-cur_line+1, strlen(cur_line)-1));

    *pattern_size = get_space_count(cur_line)+1;

    *pattern = malloc(sizeof(char *) * (*pattern_size));
    *types = malloc(sizeof (uint32_t) * (*pattern_size));
    *sizes = malloc(sizeof (size_t) * (*pattern_size));

    for (int iter = 0; iter < *pattern_size; ++iter) {
        char* space = strchr(cur_line, ' ');
        if (space == NULL){
            space = strchr(cur_line, '\0')-1;
        }
        char* colon = strchr(cur_line, ':');

        (*types)[iter] = get_type(substr(cur_line, 0, colon-cur_line));
        (*pattern)[iter] = substr(cur_line, colon-cur_line+1, space-cur_line);
        (*sizes)[iter] = strlen(substr(cur_line, colon-cur_line+1, space-cur_line))+1; // todo грануляция

        strcpy(cur_line, substr(cur_line, space-cur_line+1, strlen(cur_line)));
    }

    fclose(df);
}

void get_test_data(FILE *file, size_t tuple_count, size_t pattern_size, uint32_t *types){
    FILE *df = open_file();
    char* cur_line = get_cur_line(df);

    uint64_t* fields = malloc(sizeof(uint64_t *) * (pattern_size));
    uint64_t parent_id;

    for (int tuple_idx = 0; tuple_idx < tuple_count; ++tuple_idx) {
        cur_line = get_cur_line(df);

        parent_id = get_parent_id(cur_line);

        strcpy(cur_line, substr(cur_line, strchr(cur_line, ' ')-cur_line+1, strlen(cur_line)));

        for (int tuple_attr = 0; tuple_attr < pattern_size; ++tuple_attr) {
            char* space = strchr(cur_line, ' ');
            if (space == NULL){
                space = strchr(cur_line, '\0')-1;
            }
            char* equally = strchr(cur_line, '=');

            char* attr = substr(cur_line, equally-cur_line+1, space-cur_line);

            if (types[tuple_attr] == 0){
                fields[tuple_attr] = (uint64_t) get_bool_attr(attr);
            } else if (types[tuple_attr] == 1){
                fields[tuple_attr] = (uint64_t) atoi(attr);
            } else if (types[tuple_attr] == 2){
                fields[tuple_attr] = atof(attr);
            } else {
                fields[tuple_attr] = (uint64_t)attr;
            }

            strcpy(cur_line, substr(cur_line, space-cur_line+1, strlen(cur_line)));
        }

        add_tuple(file, fields, parent_id);

    }


    fclose(df);
}

bool get_bool_attr(char* string){
    if (strcmp(string, "True")){
        return true;
    } return false;
}

int get_parent_id(char* string){
    return atoi(substr(string, 0, strchr(string, ' ')-string));
}

char *get_cur_line(FILE *df) {
    char *cur_line = "";
    size_t len = 0;
    ssize_t read;
    getline(&cur_line, &len, df);
    return cur_line;
}

FILE *open_file(){
    FILE *df;
    df = fopen ("data_generator/data.txt","r");
    if (df == NULL) {
        printf ("Файл не существует \n");
        _Exit (EXIT_FAILURE);
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

int get_space_count(char* string){
    int spaces = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if (string[i] == ' '){
            spaces++;
        }
    }
    return spaces;
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
    if (!strcmp(str_type, "boolean")){
        return 0;
    } else if (!strcmp(str_type, "integer")){
        return 1;
    } else if (!strcmp(str_type, "float")){
        return 2;
    } else if (!strcmp(str_type, "string")){
        return 3;
    } else{
        printf ("Неверный формат входных данных \n");
        _Exit (EXIT_FAILURE);
    }
}

