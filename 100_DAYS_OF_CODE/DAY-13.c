#include <stdio.h>

int main()
{
    int m, n;

    printf("Enter size of nums1: ");
    scanf("%d", &m);

    int nums1[m];

    printf("Enter elements of nums1: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &nums1[i]);
    }

    printf("Enter size of nums2: ");
    scanf("%d", &n);

    int nums2[n];

    printf("Enter elements of nums2: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums2[i]);
    }

    int merged[m + n];

    int i = 0, j = 0, k = 0;

    // Merge both sorted arrays
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            merged[k] = nums1[i];
            i++;
        }
        else
        {
            merged[k] = nums2[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of nums1
    while (i < m)
    {
        merged[k] = nums1[i];
        i++;
        k++;
    }

    // Copy remaining elements of nums2
    while (j < n)
    {
        merged[k] = nums2[j];
        j++;
        k++;
    }

    int total = m + n;
    double median;

    if (total % 2 == 0)
    {
        median = (merged[total / 2 - 1] +
                  merged[total / 2]) / 2.0;
    }
    else
    {
        median = merged[total / 2];
    }

    printf("Median = %.2f\n", median);

    return 0;
}