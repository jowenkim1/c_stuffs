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
  GraphAdjMatrix graph;
  CHECK(graph_adj_matrix_init(&graph, 4), "init");

  CHECK(!graph_adj_matrix_add_edge(&graph, 5, 1, 1), "add invalid");
  CHECK(!graph_adj_matrix_has_edge(&graph, 0, 5), "has invalid");

  CHECK(graph_adj_matrix_add_edge(&graph, 0, 1, 1), "add 0-1");
  CHECK(graph_adj_matrix_add_edge(&graph, 0, 2, 1), "add 0-2");
  CHECK(graph_adj_matrix_add_edge(&graph, 2, 3, 1), "add 2-3");

  CHECK(graph_adj_matrix_has_edge(&graph, 0, 2), "has 0-2");
  CHECK(graph_adj_matrix_edge_count(&graph) == 3, "edge count");

  CHECK(graph_adj_matrix_remove_edge(&graph, 0, 2, 1), "remove 0-2");
  CHECK(!graph_adj_matrix_has_edge(&graph, 0, 2), "no 0-2");
  CHECK(!graph_adj_matrix_remove_edge(&graph, 0, 2, 1), "remove missing");

  graph_adj_matrix_destroy(&graph);
  printf("graph_adj_matrix ok\n");
  return 0;
}
