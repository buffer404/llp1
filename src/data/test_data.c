#include "test_data.h"

char** get_test_data_name(void){

    FILE *df = open_file();
    char* data = get_input(df);

    int len_count = get_string_count(data);

    char** data_name;

    const size_t row_pointers_bytes = MAX_STRING_LEN * sizeof *data_name;
    const size_t row_elements_bytes = len_count * sizeof **data_name;
    data_name = malloc(row_pointers_bytes + MAX_STRING_LEN * row_elements_bytes);

    printf("%d", 1);
    int cur_pos = 0;
    for (int i = 0; i < len_count; ++i) {
        int k = 0;
        while (data[cur_pos] != '='){
            cur_pos++;
        }
        cur_pos++;
        while (data[cur_pos] != '='){
            cur_pos++;
        }
        printf("1");
        cur_pos++;
        while (data[cur_pos] != '\n'){
            data_name[i][k] = data[cur_pos];
            cur_pos++;
            k++;
            printf("%c\n", data_name[i][k]);
        }
    }


    free(data);
    return data_name;
}

FILE *open_file(){
    FILE *df;
    df = fopen ("data.txt","r");
    if (df == NULL) {
        printf ("Файл не существует \n");
        _Exit (EXIT_FAILURE);
    }
}

char* get_input(FILE *df){
    char* cur_line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t m_size = 1;

    char *result = malloc(1);

    while ((read = getline(&cur_line, &len, df)) != -1) {
        m_size += read;
        result = realloc(result, m_size * sizeof (char));
        strcat(result, cur_line);
    }

    return result;
}

char get_string_count(char *data){
    int position = 0;

    while (data[position] != ' '){
        position++;
    }
    position++;
    int p2 = position;
    while (data[position] != '\n'){
        position++;
    }
    char result[position - p2];
    for (int i = 0; i < strlen(result); ++i) {
        result[i] = data[p2];
        p2++;
    }
    //printf("%s", result);
    return atoi(result);
}

void check_input();
