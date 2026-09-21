#include <stdio.h>

int celebrity(int M[][100], int n)
{
    int candidate = 0;

    // Step 1: Find a possible celebrity
    for (int i = 1; i < n; i++)
    {
        if (M[candidate][i] == 1)
        {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            // Celebrity should know nobody
            // Everyone should know the celebrity
            if (M[candidate][i] == 1 || M[i][candidate] == 0)
            {
                return -1;
            }
        }
    }

    return candidate;
}

int main()
{
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int M[100][100];

    printf("Enter the matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    int result = celebrity(M, n);

    if (result == -1)
        printf("No celebrity exists.\n");
    else
        printf("Celebrity is person %d.\n", result);

    return 0;
}