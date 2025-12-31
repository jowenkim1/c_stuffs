#ifndef HASH_CHAINING_H
#define HASH_CHAINING_H

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
 */

typedef int hash_chaining_key_t;
typedef int hash_chaining_value_t;

typedef struct HashChainingNode {
  hash_chaining_key_t key;
  hash_chaining_value_t value;
  struct HashChainingNode *next;
} HashChainingNode;

typedef struct {
  HashChainingNode **buckets;
  size_t bucket_count;
  size_t size;
} HashChaining;

int hash_chaining_init(HashChaining *table, size_t bucket_count);
void hash_chaining_destroy(HashChaining *table);
size_t hash_chaining_size(const HashChaining *table);
int hash_chaining_is_empty(const HashChaining *table);

int hash_chaining_insert(HashChaining *table, hash_chaining_key_t key,
                         hash_chaining_value_t value);
int hash_chaining_find(const HashChaining *table, hash_chaining_key_t key,
                       hash_chaining_value_t *out_value);
int hash_chaining_remove(HashChaining *table, hash_chaining_key_t key,
                         hash_chaining_value_t *out_value);
void hash_chaining_clear(HashChaining *table);

#endif
