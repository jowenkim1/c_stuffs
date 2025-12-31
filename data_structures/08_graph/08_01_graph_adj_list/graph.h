#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H

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

typedef struct GraphAdjListNode {
  size_t vertex;
  struct GraphAdjListNode *next;
} GraphAdjListNode;

typedef struct {
  size_t vertex_count;
  size_t edge_count;
  GraphAdjListNode **adj;
} GraphAdjList;

int graph_adj_list_init(GraphAdjList *graph, size_t vertex_count);
void graph_adj_list_destroy(GraphAdjList *graph);

size_t graph_adj_list_vertex_count(const GraphAdjList *graph);
size_t graph_adj_list_edge_count(const GraphAdjList *graph);

int graph_adj_list_add_edge(GraphAdjList *graph, size_t from, size_t to,
                            int undirected);
int graph_adj_list_remove_edge(GraphAdjList *graph, size_t from, size_t to,
                               int undirected);
int graph_adj_list_has_edge(const GraphAdjList *graph, size_t from, size_t to);

#endif
