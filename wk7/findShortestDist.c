#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// returns an array of length nV containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    int *dist = calloc(GraphNumVertices(g), sizeof(int));

    Queue q = QueueNew();

    QueueEnqueue(q, src);
    visited[src] = true;

    while (!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);

        for (Vertex w = 0; w < GraphNumVertices(g); w++) {
            if (!visited[w] && GraphIsAdjacent(g, v, w)) {
                QueueEnqueue(q, w);
                visited[w] = true;
                dist[w] = dist[v] + 1;
            }
        }
    }

    return dist;
}
