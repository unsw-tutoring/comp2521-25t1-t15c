#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void dfs(Graph g, Vertex curr, Set visited) {
    SetInsert(visited, curr);

    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (GraphIsAdjacent(g, curr, i) && !SetContains(visited, i)) {
            dfs(g, i, visited);
        }
    }
}

Set reachable(Graph g, Vertex src) {
    Set s = SetNew();

    dfs(g, src, s);

    return s;
}
