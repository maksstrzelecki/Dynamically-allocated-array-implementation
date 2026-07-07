#include "array.h"

int main() {
    darray* my_array = create_darray(2);
    for (int i = 0; i < 10; i++) {
        append(&my_array, i);
    }
    printf("%d\n", get(&my_array, 3));
    print_darray(&my_array);
    destroy(&my_array);
    return 0;
}