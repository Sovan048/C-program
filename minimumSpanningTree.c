#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int n, e;
} Graph;

Graph graph, MST;

int parent[MAX];

// Function to find the root of the set in which element `i` belongs
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to unite two subsets `i` and `j`
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Function to sort edges by weight
void sortEdges() {
    Edge temp;
    for (int i = 0; i < graph.e - 1; i++) {
        for (int j = 0; j < graph.e - i - 1; j++) {
            if (graph.edges[j].weight > graph.edges[j + 1].weight) {
                temp = graph.edges[j];
                graph.edges[j] = graph.edges[j + 1];
                graph.edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's algorithm to find MST
void kruskal() {
    int i, uRep, vRep;

    // Initialize parent array
    for (i = 0; i < graph.n; i++) {
        parent[i] = i;
    }

    sortEdges();

    MST.e = 0;

    for (i = 0; i < graph.e; i++) {
        uRep = find(graph.edges[i].u);
        vRep = find(graph.edges[i].v);

        if (uRep != vRep) {
            MST.edges[MST.e++] = graph.edges[i];
            unionSets(uRep, vRep);
        }
    }
}

int main() {
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &graph.n);

    printf("Enter the number of edges: ");
    scanf("%d", &graph.e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < graph.e; i++) {
        scanf("%d %d %d", &graph.edges[i].u, &graph.edges[i].v, &graph.edges[i].weight);
    }

    kruskal();

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < MST.e; i++) {
        printf("%d - %d: %d\n", MST.edges[i].u, MST.edges[i].v, MST.edges[i].weight);
    }

    return 0;
}
