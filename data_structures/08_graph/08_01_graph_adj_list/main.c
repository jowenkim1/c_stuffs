#include <stdio.h>

#include "graph.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  GraphAdjList graph;
  CHECK(graph_adj_list_init(&graph, 4) == DS_OK, "init");

  CHECK(graph_adj_list_add_edge(&graph, 5, 1, 1) == DS_ERR_INVALID, "add invalid");
  CHECK(graph_adj_list_has_edge(&graph, 0, 5) == DS_ERR_INVALID, "has invalid");

  CHECK(graph_adj_list_add_edge(&graph, 0, 1, 1) == DS_OK, "add 0-1");
  CHECK(graph_adj_list_add_edge(&graph, 0, 2, 1) == DS_OK, "add 0-2");
  CHECK(graph_adj_list_add_edge(&graph, 2, 3, 1) == DS_OK, "add 2-3");

  CHECK(graph_adj_list_has_edge(&graph, 0, 2) == 1, "has 0-2");
  CHECK(graph_adj_list_edge_count(&graph) == 3, "edge count");

  CHECK(graph_adj_list_remove_edge(&graph, 0, 2, 1) == DS_OK, "remove 0-2");
  CHECK(graph_adj_list_has_edge(&graph, 0, 2) == 0, "no 0-2");
  CHECK(graph_adj_list_remove_edge(&graph, 0, 2, 1) == DS_ERR_NOT_FOUND,
        "remove missing");

  graph_adj_list_destroy(&graph);
  printf("graph_adj_list ok\n");
  return 0;
}
