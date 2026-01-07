#include <stdlib.h>
#include <assert.h>
#include "graph.h"

bool graph_adj_matrix_init(GraphAdjMatrix *graph, size_t vertex_count)
{
    if (graph == NULL || vertex_count == 0)
    {
        return false;
    }
    graph->matrix = malloc(sizeof(int *) * vertex_count);
    if (graph->matrix == NULL)
    {
        return false;
    }
    for (size_t i = 0; i < vertex_count; i++)
    {
        graph->matrix[i] = calloc(vertex_count, sizeof(int));
        if (graph->matrix[i] == NULL)
        {
            // rollback
            for (size_t j = 0; j < i; j++)
            {
                free(graph->matrix[j]);
            }
            free(graph->matrix);
            graph->matrix = NULL;
            graph->vertex_count = 0;
            graph->edge_count = 0;
            return false;
        }
    }
    graph->vertex_count = vertex_count;
    graph->edge_count = 0;
    return true;
}
void graph_adj_matrix_destroy(GraphAdjMatrix *graph)
{
    if (graph == NULL || graph->matrix == NULL)
    {
        return;
    }

    for (size_t i = 0; i < graph->vertex_count; i++)
    {
        free(graph->matrix[i]);
    }
    free(graph->matrix);

    graph->matrix = NULL;
    graph->vertex_count = 0;
    graph->edge_count = 0;
}

size_t graph_adj_matrix_vertex_count(const GraphAdjMatrix *graph)
{
    assert(graph != NULL);
    return graph->vertex_count;
}
size_t graph_adj_matrix_edge_count(const GraphAdjMatrix *graph)
{
    assert(graph != NULL);
    return graph->edge_count;
}

bool graph_adj_matrix_add_edge(GraphAdjMatrix *graph,
                               size_t from,
                               size_t to,
                               int undirected)
{
    if (graph == NULL || graph->matrix == NULL)
    {
        return false;
    }
    if (from >= graph->vertex_count || to >= graph->vertex_count)
        return false;

    if (!undirected)
    {
        if (graph->matrix[from][to] == 0)
        {
            graph->matrix[from][to] = 1;
            graph->edge_count += 1;
        }
        return true; // idempotent
    }

    // undirected: 이미 양방향이면 변화 없음
    if (graph->matrix[from][to] == 1 && graph->matrix[to][from] == 1)
        return true;

    // 반쪽만 있던 경우도 포함해서 쌍으로 맞춤
    graph->matrix[from][to] = 1;
    graph->matrix[to][from] = 1;

    graph->edge_count += 1; // logical edge는 1개
    return true;
}
bool graph_adj_matrix_remove_edge(GraphAdjMatrix *graph, size_t from, size_t to,
                                  int undirected)
{
    if (graph == NULL || graph->matrix == NULL)
    {
        return false;
    }

    if (from >= graph->vertex_count || to >= graph->vertex_count)
        return false;

    if (!undirected)
    {
        if (graph->matrix[from][to] == 1)
        {
            graph->matrix[from][to] = 0;
            graph->edge_count -= 1;
        }
        return true; // idempotent
    }

    int existed = (graph->matrix[from][to] == 1) || (graph->matrix[to][from] == 1);

    graph->matrix[from][to] = 0;
    graph->matrix[to][from] = 0;

    if (existed)
        graph->edge_count -= 1;

    return true;
}
bool graph_adj_matrix_has_edge(const GraphAdjMatrix *graph,
                               size_t from,
                               size_t to)
{
    if (graph == NULL || graph->matrix == NULL)
        return false;
    if (from >= graph->vertex_count || to >= graph->vertex_count)
        return false;

    return graph->matrix[from][to] == 1;
}
