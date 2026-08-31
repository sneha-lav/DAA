// write a program to save the graph in the form of adjajency matrix using kruskal's algorithm.


// C code to implement Kruskal's algorithm

#include <stdio.h>

struct Edge {
    int u, v, w;                   //u- starting vertex, v- ending vertex, w= weight of the edge
};

int parent[20];

int find(int x) {
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

void unionSet(int a, int b) {       // this joins two different sets
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int V, E, i, j;
    int total = 0, count = 0;
    struct Edge e[50], temp;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    // Sort edges by weight
    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    // Initially, every vertex is its own parent
    for (i = 0; i < V; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for (i = 0; i < E && count < V - 1; i++) {                //kruskal's part
        if (find(e[i].u) != find(e[i].v)) {
            printf("%d - %d = %d\n", e[i].u, e[i].v, e[i].w);

            total += e[i].w;
            unionSet(e[i].u, e[i].v);
            count++;
        }
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}