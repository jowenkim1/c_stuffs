#ifndef HASH_OPEN_ADDRESSING_H
#define HASH_OPEN_ADDRESSING_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 * - insert updates the value if key already exists.
 * - capacity is fixed; insert returns false when table is full.
 */

typedef int hash_oa_key_t;
typedef int hash_oa_value_t;

typedef enum {
  HASH_OA_EMPTY = 0,
  HASH_OA_OCCUPIED = 1,
  HASH_OA_DELETED = 2
} HashOAState;

typedef struct {
  hash_oa_key_t key;
  hash_oa_value_t value;
  HashOAState state;
} HashOAEntry;

typedef struct {
  HashOAEntry *entries;
  size_t capacity;
  size_t size;
} HashOpenAddressing;

bool hash_oa_init(HashOpenAddressing *table, size_t capacity);
void hash_oa_destroy(HashOpenAddressing *table);
size_t hash_oa_size(const HashOpenAddressing *table);
bool hash_oa_is_empty(const HashOpenAddressing *table);

bool hash_oa_insert(HashOpenAddressing *table, hash_oa_key_t key,
                    hash_oa_value_t value);
bool hash_oa_find(const HashOpenAddressing *table, hash_oa_key_t key,
                  hash_oa_value_t *out_value);
bool hash_oa_remove(HashOpenAddressing *table, hash_oa_key_t key,
                    hash_oa_value_t *out_value);
void hash_oa_clear(HashOpenAddressing *table);

#endif
