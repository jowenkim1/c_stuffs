#ifndef GRAPH_ADJ_MATRIX_H
#define GRAPH_ADJ_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - undirected != 0 adds/removes both directions; edge_count counts logical edges.
 * - add_edge is idempotent (duplicate add returns true with no change).
 */

typedef struct {
  size_t vertex_count;
  size_t edge_count;
  int **matrix;
} GraphAdjMatrix;

bool graph_adj_matrix_init(GraphAdjMatrix *graph, size_t vertex_count);
void graph_adj_matrix_destroy(GraphAdjMatrix *graph);

size_t graph_adj_matrix_vertex_count(const GraphAdjMatrix *graph);
size_t graph_adj_matrix_edge_count(const GraphAdjMatrix *graph);

bool graph_adj_matrix_add_edge(GraphAdjMatrix *graph, size_t from, size_t to,
                               int undirected);
bool graph_adj_matrix_remove_edge(GraphAdjMatrix *graph, size_t from, size_t to,
                                  int undirected);
bool graph_adj_matrix_has_edge(const GraphAdjMatrix *graph, size_t from,
                               size_t to);

#endif
