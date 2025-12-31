#ifndef HASH_OPEN_ADDRESSING_H
#define HASH_OPEN_ADDRESSING_H

#include <stddef.h>

#ifndef DS_STATUS_H
#define DS_STATUS_H
#define DS_OK 0
#define DS_ERR_INVALID -1
#define DS_ERR_EMPTY -2
#define DS_ERR_FULL -3
#define DS_ERR_NOMEM -4
#define DS_ERR_NOT_FOUND -5
#endif

/*
 * ADT conventions:
 * - Status functions return DS_OK on success, negative DS_ERR_* on failure.
 * - Boolean queries return 1 (true), 0 (false), or DS_ERR_INVALID for bad args.
 * - out_value must be non-NULL; it is unchanged on failure.
 * - insert updates the value if key already exists.
 * - capacity is fixed; insert returns DS_ERR_FULL when table is full.
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

int hash_oa_init(HashOpenAddressing *table, size_t capacity);
void hash_oa_destroy(HashOpenAddressing *table);
size_t hash_oa_size(const HashOpenAddressing *table);
int hash_oa_is_empty(const HashOpenAddressing *table);

int hash_oa_insert(HashOpenAddressing *table, hash_oa_key_t key,
                   hash_oa_value_t value);
int hash_oa_find(const HashOpenAddressing *table, hash_oa_key_t key,
                 hash_oa_value_t *out_value);
int hash_oa_remove(HashOpenAddressing *table, hash_oa_key_t key,
                   hash_oa_value_t *out_value);
void hash_oa_clear(HashOpenAddressing *table);

#endif
