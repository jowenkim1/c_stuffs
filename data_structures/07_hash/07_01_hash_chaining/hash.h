#ifndef HASH_CHAINING_H
#define HASH_CHAINING_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
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

bool hash_chaining_init(HashChaining *table, size_t bucket_count);
void hash_chaining_destroy(HashChaining *table);
size_t hash_chaining_size(const HashChaining *table);
bool hash_chaining_is_empty(const HashChaining *table);

bool hash_chaining_insert(HashChaining *table, hash_chaining_key_t key,
                          hash_chaining_value_t value);
bool hash_chaining_find(const HashChaining *table, hash_chaining_key_t key,
                        hash_chaining_value_t *out_value);
bool hash_chaining_remove(HashChaining *table, hash_chaining_key_t key,
                          hash_chaining_value_t *out_value);
void hash_chaining_clear(HashChaining *table);

#endif
