#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
    int size;
    int capacity;
    int* data;
} darray;

darray* create_darray(int cap);
int get(darray** array, int idx);
void append(darray** array, int el);
void destroy(darray** array);
void print_darray(darray** array);