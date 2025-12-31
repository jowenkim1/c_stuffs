#include <stdio.h>

#include "hash.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  HashChaining table;
  CHECK(hash_chaining_init(&table, 8) == DS_OK, "init");

  hash_chaining_value_t value = 0;
  CHECK(hash_chaining_find(&table, 1, &value) == DS_ERR_NOT_FOUND, "find empty");
  CHECK(hash_chaining_remove(&table, 1, &value) == DS_ERR_NOT_FOUND, "remove empty");

  CHECK(hash_chaining_insert(&table, 1, 100) == DS_OK, "insert 1");
  CHECK(hash_chaining_insert(&table, 9, 900) == DS_OK, "insert 9");
  CHECK(hash_chaining_insert(&table, 1, 111) == DS_OK, "update 1");

  CHECK(hash_chaining_find(&table, 1, &value) == DS_OK && value == 111,
        "find updated");

  CHECK(hash_chaining_remove(&table, 1, &value) == DS_OK && value == 111,
        "remove 1");
  CHECK(hash_chaining_size(&table) == 1, "size after remove");

  hash_chaining_clear(&table);
  CHECK(hash_chaining_is_empty(&table) == 1, "clear empty");

  hash_chaining_destroy(&table);
  printf("hash_chaining ok\n");
  return 0;
}
