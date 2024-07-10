#include "array.h"

void initArray(array* arr, int capacity, int datatype) {
    arr->buffer=NULL;
    arr->datatype = datatype;
    arr->capacity = capacity;
    arr->length = 0;
    if(capacity>0)
        arr->buffer = malloc(capacity*datatype);
}

void finaArray(array* arr) {
    if(arr->buffer!=NULL)
        free(arr->buffer);
    arr->capacity=0;
    arr->length=0;
}

void* arrayPushBack(array* arr, void* data) {
    if(arr->length==arr->capacity)
        arrayResize(arr, arr->capacity*2+1);
    
    void* pushedElement = arrayAt(arr, arr->length);
    if(data!=NULL)
        memcpy(pushedElement, data, arr->datatype);
    
    arr->length++;
    return pushedElement;
}
void* arrayPopBack(array* arr) {
    if(arr->length==0)
        return NULL;
    
    arr->length--;
    return arrayAt(arr, arr->length);
}
void arrayResize(array* arr, int capacity) {
    arr->buffer = realloc(arr->buffer, capacity*arr->datatype);
    arr->capacity = capacity;
}

void* arrayAt(array* arr, int offset) {
    return arr->buffer + offset*arr->datatype;
}
