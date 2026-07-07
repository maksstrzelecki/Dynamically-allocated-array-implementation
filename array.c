#include "array.h"


darray* create_darray(int cap) {
    darray* array = malloc(sizeof(darray));
    if (array == NULL) {
        perror("darray allocation failed");
        return NULL;
    }
    array->size = 0;
    if (cap == 0) array->capacity = 1;
    else {
        array->capacity = cap;
    }
    array->data = malloc(sizeof(int) * array->capacity);
    if (array->data == NULL) {
        perror("data allocation failed");
        free(array);
        return NULL;
    }
    return array;
}

int get(darray** array, int idx) {
    if (idx >= (*array)->size) {
        printf("Index out of range\n");
        return -1;
    }
    return (*array)->data[idx];
}

void append(darray** array, int el) {
    if ((*array)->size == (*array)->capacity) {
        int* temp_arr_data = malloc(sizeof(int) * (*array)->capacity * 2);
        if (temp_arr_data == NULL) {
            perror("Failed to append element");
            return;
        }

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
    if ((*array)->size == 0) printf("[]");
    else {
        printf("[");
        for (int i = 0; i < (*array)->size-1; i++) {
            printf("%d, ", (*array)->data[i]);
        }
        printf("%d", (*array)->data[(*array)->size-1]);
        printf("]");
        printf("\n");
    }
}