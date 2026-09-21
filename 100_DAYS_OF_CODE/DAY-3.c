/*Given an array of daily temperatures, find the length of the longest consecutive strictly increasing streak.


Input:  [10, 12, 15, 14, 16, 18, 20]
Output: 4

Explanation: 14, 16, 18, 20 is the longest increasing streak.
*/

#include <stdio.h>

int longestIncreasingStreak(int arr[], int n)
{
    int maxStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            currentStreak++;
        }
        else
        {
            if (currentStreak > maxStreak)
            {
                maxStreak = currentStreak;
            }

            currentStreak = 1;
        }
    }

    // Check the final streak
    if (currentStreak > maxStreak)
    {
        maxStreak = currentStreak;
    }

    return maxStreak;
}

int main()
{
    int arr[] = {10, 12, 15, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestIncreasingStreak(arr, n);

    printf("Longest increasing streak = %d\n", result);

    return 0;
}