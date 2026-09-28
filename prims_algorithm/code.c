#include <stdio.h>

#define INF 9999
#define MAX 10

void prim(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int edges = 0;
    int totalCost = 0;

    // Start from vertex 0
    selected[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        int min = INF;
        int x = -1, y = -1;

        // Find minimum edge connecting selected to unselected vertex
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, min);

        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", totalCost);
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, n);

    return 0;
}