# Dynamic Array in C

A simple implementation of a dynamic array (similar to C++ `std::vector`) written in C.

## Features

* Dynamic memory allocation
* Automatic capacity growth
* Element insertion
* Random access by index
* Array printing
* Proper memory deallocation

## Project Structure

```text
.
├── array.h      # Public API
├── array.c      # Implementation
└── main.c       # Example usage
```

## API

### Create a dynamic array

```c
darray *create_darray(int capacity);
```

Creates a new dynamic array with the specified initial capacity.

---

### Append an element

```c
void append(darray *array, int element);
```

Adds an element to the end of the array. If the array is full, its capacity is automatically increased.

---

### Get an element

```c
int get(darray *array, int index);
```

Returns the element stored at the specified index.

---

### Print the array

```c
void print_darray(const darray *array);
```

Prints the contents of the array in a readable format.

Example:

```text
[1, 5, 8, 13]
```

---

### Destroy the array

```c
void destroy(darray **array);
```

Releases all allocated memory associated with the array.

## Example

```c
darray *arr = create_darray(4);

append(arr, 10);
append(arr, 20);
append(arr, 30);

print_darray(arr);

destroy(&arr);
```

## Complexity

| Operation          | Time Complexity |
| ------------------ | --------------- |
| Append (amortized) | O(1)            |
| Append (resize)    | O(n)            |
| Get                | O(1)            |
| Print              | O(n)            |
| Destroy            | O(n)            |

## Future Improvements

* Remove elements
* Insert at arbitrary positions
* Shrink capacity automatically
* Generic implementation using `void *`
* Iterator support
* Better error handling
* Unit tests

## License

This project is available under the MIT License.
