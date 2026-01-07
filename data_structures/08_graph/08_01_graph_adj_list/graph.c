#include <assert.h>
#include <stdlib.h>
#include "graph.h"

bool graph_adj_list_init(GraphAdjList *graph, size_t vertex_count)
{
    if (graph == NULL || vertex_count == 0)
    {
        return false;
    }

    graph->adj = calloc(vertex_count, sizeof(GraphAdjListNode *));
    if (graph->adj == NULL)
    {
        return false;
    }

    graph->vertex_count = vertex_count;
    graph->edge_count = 0;
    return true;
}
void graph_adj_list_destroy(GraphAdjList *graph)
{
    if (graph == NULL || graph->adj == NULL)
    {
        return;
    }
    for (size_t i = 0; i < graph->vertex_count; i++)
    {
        GraphAdjListNode *curr = graph->adj[i];
        while (curr != NULL)
        {
            GraphAdjListNode *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(graph->adj);
    graph->adj = NULL;
    graph->vertex_count = 0;
    graph->edge_count = 0;
}

size_t graph_adj_list_vertex_count(const GraphAdjList *graph)
{
    assert(graph != NULL);
    return graph->vertex_count;
}
size_t graph_adj_list_edge_count(const GraphAdjList *graph)
{
    assert(graph != NULL);
    return graph->edge_count;
}

static bool adj_list_has_edge_from(const GraphAdjList *graph, size_t from, size_t to)
{
    GraphAdjListNode *curr = graph->adj[from];
    while (curr != NULL)
    {
        if (curr->vertex == to)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

static bool adj_list_add_directed(GraphAdjList *graph, size_t from, size_t to)
{
    GraphAdjListNode *node = malloc(sizeof(*node));
    if (node == NULL)
    {
        return false;
    }
    node->vertex = to;
    node->next = graph->adj[from];
    graph->adj[from] = node;
    return true;
}

bool graph_adj_list_add_edge(GraphAdjList *graph, size_t from, size_t to, int undirected)
{
    if (graph == NULL || graph->adj == NULL)
    {
        return false;
    }
    if (from >= graph->vertex_count || to >= graph->vertex_count)
    {
        return false;
    }

    // idempotent: 이미 논리 간선이 있으면 변화 없이 true
    if (adj_list_has_edge_from(graph, from, to) &&
        (!undirected || adj_list_has_edge_from(graph, to, from)))
    {
        return true;
    }

    // 방향 간선 추가 (중복 방지)
    if (!adj_list_has_edge_from(graph, from, to))
    {
        if (!adj_list_add_directed(graph, from, to))
        {
            return false;
        }
    }

    if (undirected)
    {
        if (!adj_list_has_edge_from(graph, to, from))
        {
            if (!adj_list_add_directed(graph, to, from))
            {
                // 엄밀히 하려면 여기서 (from->to) 롤백 가능.
                return false;
            }
        }
    }

    // logical edge count: 무방향도 1개로 센다
    graph->edge_count += 1;
    return true;
}
static bool remove_directed(GraphAdjList *graph, size_t from, size_t to)
{
    GraphAdjListNode *curr = graph->adj[from];
    GraphAdjListNode *prev = NULL;

    while (curr != NULL)
    {
        if (curr->vertex == to)
        {
            if (prev == NULL)
            {
                graph->adj[from] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return true; // removed one node
        }
        prev = curr;
        curr = curr->next;
    }
    return false; // not found
}

static bool has_directed(const GraphAdjList *graph, size_t from, size_t to)
{
    GraphAdjListNode *curr = graph->adj[from];
    while (curr != NULL)
    {
        if (curr->vertex == to)
            return true;
        curr = curr->next;
    }
    return false;
}

bool graph_adj_list_remove_edge(GraphAdjList *graph,
                                size_t from,
                                size_t to,
                                int undirected)
{
    if (graph == NULL || graph->adj == NULL)
    {
        return false;
    }
    if (from >= graph->vertex_count || to >= graph->vertex_count)
    {
        return false;
    }

    if (!undirected)
    {
        // directed: from -> to 만 제거, logical edge도 그 1개
        bool removed = remove_directed(graph, from, to);
        if (removed)
        {
            graph->edge_count -= 1;
        }
        return true; // idempotent: 없어도 true
    }

    // undirected: 논리 간선 {from,to}가 존재하면 양방향을 제거
    bool existed_logical =
        has_directed(graph, from, to) || has_directed(graph, to, from);

    // 존재 여부와 상관없이 시도 (idempotent)
    (void)remove_directed(graph, from, to);
    (void)remove_directed(graph, to, from);

    if (existed_logical)
    {
        graph->edge_count -= 1; // logical edge 1개만 감소
    }
    return true;
}

bool graph_adj_list_has_edge(const GraphAdjList *graph,
                             size_t from,
                             size_t to)
{
    if (graph == NULL || graph->adj == NULL)
    {
        return false;
    }
    if (from >= graph->vertex_count || to >= graph->vertex_count)
    {
        return false;
    }

    GraphAdjListNode *curr = graph->adj[from];
    while (curr != NULL)
    {
        if (curr->vertex == to)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}