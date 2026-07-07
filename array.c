#include "array.h"

darray* create_darray() {
    darray* array = malloc(sizeof(darray));
    if (array == -1) return NULL;
    array->size = 0;
    array->capacity = 0;
    array->data = malloc(sizeof(int) * array->capacity);
    if (array->data == -1) return NULL;
    return array;
}

int get(darray** array, int idx) {
    if (idx >= (*array)->size) {
        printf("Index out of range");
        return -1;
    }
    return (*array)->data[idx];
}

void append(darray** array, int el) {
    if ((*array)->size == (*array)->capacity) {
        int* temp_arr_data = malloc(sizeof(int) * (*array)->capacity * 2);
        for (int i = 0; i < (*array)->size; i++) {
            temp_arr_data[i] = (*array)->data[i];
        }
        free((*array)->data);
        (*array)->data = temp_arr_data;
        (*array)->data[(*array)->size] = el;
        (*array)->size++;
        (*array)->capacity *= 2;
    }
    else {
        (*array)->data[(*array)->size] = el;
        (*array)->size++;
    }
}

void destroy(darray** array) {
    free((*array)->data);
    free((*array));
}

void print_darray(darray** array) {
    printf("[");
    for (int i = 0; i < (*array)->size-1; i++) {
        printf("%d, ", (*array)->data[i]);
    }
    printf("%d", (*array)->data[(*array)->size-1]);
    printf("]");
    printf("\n");
}