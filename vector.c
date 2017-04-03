#include "vector.h"

/**
 * @todo faut gérer les erreurs
 */
Vector* vector_new()
{
	Vector* v;

	v = malloc(sizeof(*v));
	v->length = 0;
	v->allocated_size = 0;
	v->data = NULL;

	return v;
}

/**
 * @todo faut gérer les erreurs
 */
int vector_push(Vector* v, void* value)
{
	if (v->length == v->allocated_size)
	{
		v->allocated_size *= 2;
		v->data = realloc(v->data, v->allocated_size);
	}

	v->length += 1;
	v->data[v->length-1] = value;

	return 0;
}

int vector_pop(Vector* v, void** value)
{
	*value = v->data[--v->length];
	if (v->length < v->allocated_size/4)
	{
		v->data = realloc(v->data, v->allocated_size/4);
		v->allocated_size = v->allocated_size/4;
	}

	return 0;
}

void vector_free(Vector* v)
{
	free (v->data);
	return;
}

int vector_get(Vector* v, size_t index, void** value)
{
	if (index >= v->length)
	{
		return 1;
	}

	*value=(v->data[v->length-1]);
	return 0;
}
