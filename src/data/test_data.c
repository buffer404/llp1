#include "test_data.h"

char* get_test_data(int data_type, int count){
    FILE *mf;
    mf = fopen ("data.txt","r");
    if (mf == NULL) {
        printf ("Файл не существует \n");
        _Exit (EXIT_FAILURE);
    }

    char str[count * sizeof(char) * 20];
    return 0;
}

FILE *open_file(){

}

char* get_input();

void check_input();
