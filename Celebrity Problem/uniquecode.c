#include <stdio.h>

int findCelebrity(int M[][100], int n)
{
    int inDegree[100] = {0};
    int outDegree[100] = {0};

    // Calculate in-degree and out-degree
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    // Find a person who satisfies celebrity conditions
    for (int i = 0; i < n; i++)
    {
        if (outDegree[i] == 0 && inDegree[i] == n - 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    int M[100][100];

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    int result = findCelebrity(M, n);

    if (result == -1)
        printf("No celebrity exists.\n");
    else
        printf("Celebrity is person %d.\n", result);

    return 0;
}