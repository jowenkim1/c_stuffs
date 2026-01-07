#include <assert.h>
#include <stdlib.h>
#include "hash.h"

bool hash_chaining_init(HashChaining *table, size_t bucket_count)
{
    if (table == NULL || bucket_count == 0)
    {
        return false;
    }
    table->buckets = calloc(bucket_count, sizeof(HashChainingNode *));
    if (table->buckets == NULL)
    {
        table->bucket_count = 0;
        table->size = 0;
        return false;
    }
    table->bucket_count = bucket_count;
    table->size = 0;
    return true;
}

void hash_chaining_destroy(HashChaining *table)
{
    if (table == NULL || table->buckets == NULL)
    {
        return;
    }
    for (size_t i = 0; i < table->bucket_count; i++)
    {
        HashChainingNode *curr = table->buckets[i];
        while (curr != NULL)
        {
            HashChainingNode *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(table->buckets);
    table->buckets = NULL;
    table->bucket_count = 0;
    table->size = 0;
}

size_t hash_chaining_size(const HashChaining *table)
{
    assert(table != NULL);
    return table->size;
}
bool hash_chaining_is_empty(const HashChaining *table)
{
    assert(table != NULL);
    return table->size == 0;
}

bool hash_chaining_insert(HashChaining *table,
                          hash_chaining_key_t key,
                          hash_chaining_value_t value)
{
    if (table == NULL || table->buckets == NULL)
    {
        return false;
    }

    size_t idx = (size_t)(key % (hash_chaining_key_t)table->bucket_count);
    HashChainingNode *curr = table->buckets[idx];

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            curr->value = value;
            return true;
        }
        curr = curr->next;
    }

    HashChainingNode *node = malloc(sizeof(HashChainingNode));
    if (node == NULL)
    {
        return false;
    }

    node->key = key;
    node->value = value;
    node->next = table->buckets[idx];
    table->buckets[idx] = node;

    table->size += 1;
    return true;
}
bool hash_chaining_find(const HashChaining *table, hash_chaining_key_t key, hash_chaining_value_t *out_value)
{
    if (table == NULL || table->buckets == NULL || out_value == NULL)
    {
        return false;
    }
    size_t idx = (size_t)(key % (hash_chaining_key_t)table->bucket_count);
    HashChainingNode *curr = table->buckets[idx];

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            *out_value = curr->value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool hash_chaining_remove(HashChaining *table,
                          hash_chaining_key_t key,
                          hash_chaining_value_t *out_value)
{
    if (table == NULL || table->buckets == NULL || out_value == NULL)
    {
        return false;
    }

    size_t idx = key % table->bucket_count;
    HashChainingNode *curr = table->buckets[idx];
    HashChainingNode *prev = NULL;

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            *out_value = curr->value;

            if (prev == NULL)
            {
                table->buckets[idx] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            free(curr);
            table->size -= 1;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}
void hash_chaining_clear(HashChaining *table)
{
    if (table == NULL || table->buckets == NULL)
    {
        return;
    }

    for (size_t i = 0; i < table->bucket_count; i++)
    {
        HashChainingNode *curr = table->buckets[i];
        while (curr != NULL)
        {
            HashChainingNode *next = curr->next;
            free(curr);
            curr = next;
        }
        table->buckets[i] = NULL;
    }
    table->size = 0;
}