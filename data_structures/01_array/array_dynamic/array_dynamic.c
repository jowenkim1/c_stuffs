#include <assert.h>
#include <stdlib.h>
#include "array_dynamic.h"

bool array_dynamic_init(ArrayDynamic *arr, size_t capacity)
{
	if (arr == NULL || capacity == 0)
	{
		return false;
	}
	arr->data = malloc(sizeof(int) * capacity);
	if (arr->data == NULL)
	{
		return false;
	}
	arr->capacity = capacity;
	arr->size = 0;
	return true;
}
void array_dynamic_destroy(ArrayDynamic *arr)
{
	if (arr == NULL)
	{
		return;
	}
	free(arr->data);
	arr->data = NULL;
	arr->capacity = 0;
	arr->size = 0;
}
size_t array_dynamic_size(const ArrayDynamic *arr)
{
	assert(arr != NULL);
	return arr->size;
}
size_t array_dynamic_capacity(const ArrayDynamic *arr)
{
	assert(arr != NULL);
	return arr->capacity;
}
bool array_dynamic_is_empty(const ArrayDynamic *arr)
{
	assert(arr != NULL);
	if (arr->size == 0)
	{
		return true;
	}
	return false;
}
bool array_dynamic_get(const ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value)
{
	if (arr == NULL || arr->size <= index || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[index];
	return true;
}
bool array_dynamic_set(ArrayDynamic *arr, size_t index, array_dynamic_value_t value)
{
	if (arr == NULL || arr->size <= index)
	{
		return false;
	}
	arr->data[index] = value;
	return true;
}
bool array_dynamic_front(const ArrayDynamic *arr, array_dynamic_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[0];
	return true;
}
bool array_dynamic_back(const ArrayDynamic *arr, array_dynamic_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[arr->size - 1];
	return true;
}
bool array_dynamic_push_back(ArrayDynamic *arr, array_dynamic_value_t value)
{
	if (arr == NULL || arr->size == arr->capacity)
	{
		return false;
	}
	arr->data[arr->size++] = value;
	return true;
}
bool array_dynamic_pop_back(ArrayDynamic *arr, array_dynamic_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || out_value == NULL)
	{
		return false;
	}
	*out_value = arr->data[--arr->size];
	return true;
}
bool array_dynamic_insert(ArrayDynamic *arr, size_t index, array_dynamic_value_t value)
{
	if (arr == NULL || arr->size == arr->capacity)
	{
		return false;
	}
	if (arr->size <= index)
	{
		arr->data[arr->size++] = value;
		return true;
	}
	else
	{
		for (size_t i = arr->size; index < i; i--)
		{
			arr->data[i] = arr->data[i - 1];
		}
		arr->data[index] = value;
		arr->size += 1;
		return true;
	}
}
bool array_dynamic_remove(ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value)
{
	if (arr == NULL || arr->size == 0 || arr->size <= index || out_value == NULL)
	{
		return false;
	}
	if (arr->size - 1 == index)
	{
		*out_value = arr->data[index];
		arr->size -= 1;
		return true;
	}
	else
	{
		*out_value = arr->data[index];
		for (size_t i = index; i + 1 < arr->size; i++)
		{
			arr->data[i] = arr->data[i + 1];
		}
		arr->size -= 1;
		return true;
	}
}
bool array_dynamic_reserve(ArrayDynamic *arr, size_t new_capacity)
{
	if (arr == NULL || new_capacity <= arr->capacity)
	{
		return false;
	}
	array_dynamic_value_t *p = realloc(arr->data, sizeof(int)*new_capacity);
	if (p == NULL)
	{
		return false;
	}
	arr->data = p;
	arr->capacity = new_capacity;
	return true;
}
void array_dynamic_clear(ArrayDynamic *arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;
}
