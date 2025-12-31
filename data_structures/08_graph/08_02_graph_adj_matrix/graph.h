#ifndef GRAPH_ADJ_MATRIX_H
#define GRAPH_ADJ_MATRIX_H

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
 * - undirected != 0 adds/removes both directions; edge_count counts logical edges.
 * - add_edge is idempotent (duplicate add returns DS_OK with no change).
 */

typedef struct {
  size_t vertex_count;
  size_t edge_count;
  int **matrix;
} GraphAdjMatrix;

int graph_adj_matrix_init(GraphAdjMatrix *graph, size_t vertex_count);
void graph_adj_matrix_destroy(GraphAdjMatrix *graph);

size_t graph_adj_matrix_vertex_count(const GraphAdjMatrix *graph);
size_t graph_adj_matrix_edge_count(const GraphAdjMatrix *graph);

int graph_adj_matrix_add_edge(GraphAdjMatrix *graph, size_t from, size_t to,
                              int undirected);
int graph_adj_matrix_remove_edge(GraphAdjMatrix *graph, size_t from, size_t to,
                                 int undirected);
int graph_adj_matrix_has_edge(const GraphAdjMatrix *graph, size_t from,
                              size_t to);

#endif
