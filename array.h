#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* buffer; unsigned char datatype;
    unsigned int capacity, length;
} array;


void initArray(array* arr, int capacity, int datatype);
void finaArray(array* arr);

void* arrayPushBack(array* arr, void* data);
void* arrayPopBack(array* arr);
void arrayResize(array* arr, int capacity);

void* arrayAt(array* arr, int offset);

typedef array intArr;
typedef array charArr;
