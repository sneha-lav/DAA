/*Write a C program to rotate an array to the right by K positions without using another array.
 Array: 1 2 3 4 5 6 K = 2 
 Output: 5 6 1 2 3 4
 */

 #include <stdio.h>

void reverse(int a[], int start, int end)
{
    while (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 2;

    k = k % n;

    // Reverse the whole array
    reverse(a, 0, n - 1);

    // Reverse first k elements
    reverse(a, 0, k - 1);

    // Reverse remaining elements
    reverse(a, k, n - 1);

    printf("Rotated array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}