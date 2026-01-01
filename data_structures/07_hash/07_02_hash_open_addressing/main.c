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
  HashOpenAddressing table;
  CHECK(hash_oa_init(&table, 2), "init");

  hash_oa_value_t value = 0;
  CHECK(!hash_oa_find(&table, 1, &value), "find empty");
  CHECK(!hash_oa_remove(&table, 1, &value), "remove empty");

  CHECK(hash_oa_insert(&table, 1, 100), "insert 1");
  CHECK(hash_oa_insert(&table, 9, 900), "insert 9");
  CHECK(hash_oa_insert(&table, 1, 111), "update 1");

  CHECK(hash_oa_find(&table, 1, &value) && value == 111, "find updated");
  CHECK(!hash_oa_insert(&table, 2, 200), "insert full");

  CHECK(hash_oa_remove(&table, 9, &value) && value == 900, "remove 9");
  CHECK(hash_oa_size(&table) == 1, "size after remove");

  hash_oa_clear(&table);
  CHECK(hash_oa_is_empty(&table) == true, "clear empty");

  hash_oa_destroy(&table);
  printf("hash_open_addressing ok\n");
  return 0;
}
