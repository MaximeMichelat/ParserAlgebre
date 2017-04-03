#include <stdlib.h>

typedef struct Vector
{
	void** data;
	size_t length;
	size_t allocated_size;
} Vector;

Vector* vector_new();
int vector_push(Vector* v, void* value);
int vector_pop(Vector* v, void** value);
void vector_free(Vector* v);
int vector_get(Vector* v, size_t index, void** value);
