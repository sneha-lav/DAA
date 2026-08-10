//1. Write a C program to find the second-largest distinct element in an array without sorting it.

#include <stdio.h>

int main()
{
    int n, max, second;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    second = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            second = max;
            max = a[i];
        }
        else if (a[i] > second && a[i] != max)
        {
            second = a[i];
        }
    }

    if (second == max)
        printf("Second-largest distinct element does not exist.");
    else
        printf("Second-largest distinct element = %d", second);

    return 0;
}