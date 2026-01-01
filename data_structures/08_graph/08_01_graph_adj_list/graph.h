#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - undirected != 0 adds/removes both directions; edge_count counts logical edges.
 * - add_edge is idempotent (duplicate add returns true with no change).
 */

typedef struct GraphAdjListNode {
  size_t vertex;
  struct GraphAdjListNode *next;
} GraphAdjListNode;

typedef struct {
  size_t vertex_count;
  size_t edge_count;
  GraphAdjListNode **adj;
} GraphAdjList;

bool graph_adj_list_init(GraphAdjList *graph, size_t vertex_count);
void graph_adj_list_destroy(GraphAdjList *graph);

size_t graph_adj_list_vertex_count(const GraphAdjList *graph);
size_t graph_adj_list_edge_count(const GraphAdjList *graph);

bool graph_adj_list_add_edge(GraphAdjList *graph, size_t from, size_t to,
                             int undirected);
bool graph_adj_list_remove_edge(GraphAdjList *graph, size_t from, size_t to,
                                int undirected);
bool graph_adj_list_has_edge(const GraphAdjList *graph, size_t from, size_t to);

#endif
