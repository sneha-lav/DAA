#include<stdio.h>

int main()
{

     int arr[100], n, key;
     int i, found=0;

     printf("Enter the number of elements: ");
     scanf("%d", &n);

     printf("Enter elements in the array: ");
     for (i=0 ; i<n; i++)
     {
        scanf("%d", &arr[i]);
     }

     printf("Enter the element to be searched:");
     scanf("%d", &key);

     for(i=0; i<n; i++)
     {
        if(arr[i] == key)
        { 
            found = 1;
            break;
        }
     
     }
    if (found == 1)
        printf("Element found at position %d", i+1);

    else
       printf("Element not found in the array");

    return 0;
    
}