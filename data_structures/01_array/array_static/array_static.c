#include <stdlib.h>
#include <assert.h>
#include "array_static.h"

// #define ARRAY_STATIC_CAPACITY 128
// typedef int array_static_value_t;
// typedef struct {
//   array_static_value_t data[ARRAY_STATIC_CAPACITY];
//   size_t size;
// } ArrayStatic;

void array_static_init(ArrayStatic *arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;
}
size_t array_static_size(const ArrayStatic *arr)
{
	assert(arr != NULL);
	return arr->size;
}
size_t array_static_capacity(const ArrayStatic *arr)
{
	assert(arr != NULL);
	return sizeof(arr->data) / sizeof(arr->data[0]);
}
bool array_static_is_empty(const ArrayStatic *arr)
{
	assert(arr != NULL);
	return (arr->size == 0) ? true : false;
}
bool array_static_is_full(const ArrayStatic *arr)
{
	assert(arr != NULL);
	size_t full_size = sizeof(arr->data) / sizeof(arr->data[0]);
	return (arr->size == full_size) ? true : false;
}
bool array_static_get(const ArrayStatic *arr, size_t index, array_static_value_t *out_value)
{
	if (arr == NULL || arr->size <= index || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[index];
	return true;
}
bool array_static_set(ArrayStatic *arr, size_t index, array_static_value_t value)
{
	if (arr == NULL || arr->size <= index)
	{
		return false;
	}
	arr->data[index] = value;
	return true;
}

bool array_static_front(const ArrayStatic *arr, array_static_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[0];
	return true;
}

bool array_static_back(const ArrayStatic *arr, array_static_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[arr->size - 1];
	return true;
}

bool array_static_push_back(ArrayStatic *arr, array_static_value_t value)
{
	if (arr == NULL)
	{
		return false;
	}
	size_t full_size = sizeof(arr->data) / sizeof(arr->data[0]);
	if (arr->size == full_size)
	{
		return false;
	}
	arr->data[arr->size++] = value;
	return true;
}
bool array_static_pop_back(ArrayStatic *arr, array_static_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[--arr->size];
	return true;
}
bool array_static_insert(ArrayStatic *arr, size_t index, array_static_value_t value)
{
	if (arr == NULL)
	{
		return false;
	}
	size_t full_size = sizeof(arr->data) / sizeof(arr->data[0]);
	if (arr->size == full_size)
	{
		return false;
	}

	if (arr->size <= index)
	{
		arr->data[arr->size++] = value;
	}
	else if (index < arr->size)
	{
		for (size_t i = arr->size; index < i; i--)
		{
			arr->data[i] = arr->data[i - 1];
		}
		arr->data[index] = value;
		arr->size += 1;
	}
	return true;
}
bool array_static_remove(ArrayStatic *arr, size_t index, array_static_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || arr->size <= index || out_value == NULL)
	{
		return false;
	}
	if (arr->size == index + 1)
	{
		*out_value = arr->data[--arr->size];
	}
	else
	{
		*out_value = arr->data[index];
		for (size_t i = index; i < arr->size - 1; i++)
		{
			arr->data[i] = arr->data[i + 1];
		}
		arr->size -= 1;
	}
	return true;
}
void array_static_clear(ArrayStatic *arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;
}
