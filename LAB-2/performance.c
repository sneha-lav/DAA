#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define REPETITIONS 10000

// ==================== BUBBLE SORT ====================

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ==================== SELECTION SORT ====================

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// ==================== INSERTION SORT ====================

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// ==================== MERGE SORT ====================

void merge(int arr[], int low, int mid, int high)
{
    int temp[SIZE];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// ==================== QUICK SORT ====================

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ==================== LINEAR SEARCH ====================

int linearSearch(int arr[], int n, int target)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// ==================== BINARY SEARCH ====================

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// ==================== MAIN ====================

int main()
{
    int original[SIZE];
    int arr[SIZE];
    int sorted[SIZE];

    int i, j;
    int target;

    clock_t start, end;
    double timeTaken;

    volatile int result;

    // Generate 100 random numbers
    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        original[i] = rand() % 1000;
    }

    printf("============================================\n");
    printf(" PERFORMANCE COMPARISON OF ALGORITHMS\n");
    printf("============================================\n");
    printf("Number of elements: %d\n", SIZE);
    printf("Repetitions: %d\n\n", REPETITIONS);

    // ==================================================
    // BUBBLE SORT
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        for (i = 0; i < SIZE; i++)
            arr[i] = original[i];

        bubbleSort(arr, SIZE);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble Sort    : %.6f seconds\n", timeTaken);


    // ==================================================
    // SELECTION SORT
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        for (i = 0; i < SIZE; i++)
            arr[i] = original[i];

        selectionSort(arr, SIZE);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Selection Sort : %.6f seconds\n", timeTaken);


    // ==================================================
    // INSERTION SORT
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        for (i = 0; i < SIZE; i++)
            arr[i] = original[i];

        insertionSort(arr, SIZE);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort : %.6f seconds\n", timeTaken);


    // ==================================================
    // MERGE SORT
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        for (i = 0; i < SIZE; i++)
            arr[i] = original[i];

        mergeSort(arr, 0, SIZE - 1);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Merge Sort     : %.6f seconds\n", timeTaken);


    // ==================================================
    // QUICK SORT
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        for (i = 0; i < SIZE; i++)
            arr[i] = original[i];

        quickSort(arr, 0, SIZE - 1);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Quick Sort     : %.6f seconds\n", timeTaken);


    // ==================================================
    // PREPARE SORTED ARRAY FOR BINARY SEARCH
    // ==================================================

    for (i = 0; i < SIZE; i++)
        sorted[i] = original[i];

    bubbleSort(sorted, SIZE);

    // Use an element that definitely exists
    target = sorted[SIZE / 2];


    // ==================================================
    // LINEAR SEARCH
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        result = linearSearch(sorted, SIZE, target);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Linear Search  : %.6f seconds\n", timeTaken);


    // ==================================================
    // BINARY SEARCH
    // ==================================================

    start = clock();

    for (j = 0; j < REPETITIONS; j++)
    {
        result = binarySearch(sorted, SIZE, target);
    }

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Binary Search  : %.6f seconds\n", timeTaken);

    printf("\n============================================\n");
    printf("             END OF COMPARISON\n");
    printf("============================================\n");

    return 0;
}