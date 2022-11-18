#ifndef CRUD_INTERFACE_H
#define CRUD_INTERFACE_H
#include "basic_crud.h"

/**
 * Структура хранящая
 */
struct result_list_tuple {
    struct result_list_tuple *prev;
    struct tuple *value;
    uint64_t id;
    struct result_list_tuple *next;
};

/**
 * Добавление нового tuple
 * @param file файл
 * @param fields массив полей согласно шаблону
 * @param parent_id кто родитель данного tuple
 * @return
 */
enum crud_operation_status add_tuple(FILE *file, uint64_t *fields, uint64_t parent_id);

/**
 * Удалить tuple по его id
 * @param file файл
 * @param id
 * @param str_flag 0 = default tuple, 1 = tuple contain string
 * @return
 */
enum crud_operation_status remove_tuple(FILE *file, uint64_t id, uint8_t str_flag);

enum crud_operation_status get_tuple(FILE *file, uint64_t **fields, uint64_t id);


enum crud_operation_status find_by_field(FILE *file, uint64_t field_number, uint64_t *condition, struct result_list_tuple **result);
enum crud_operation_status find_by_parent(FILE *file, uint64_t parent_id, struct result_list_tuple **result);
/**
 * Обновить одно значение параметра
 * @param file файл
 * @param field_number номер поля паттерна
 * @param new_value адрес нового значения
 * @param id tuple
 * @return
 */
enum crud_operation_status update_tuple(FILE *file, uint64_t field_number, uint64_t *new_value, uint64_t id);

#endif

