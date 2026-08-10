// Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, j, palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        // Ignore spaces
        if (str[i] == ' ')
        {
            i++;
            continue;
        }

        if (str[j] == ' ' || str[j] == '\n')
        {
            j--;
            continue;
        }

        // Ignore uppercase/lowercase difference
        if (tolower(str[i]) != tolower(str[j]))
        {
            palindrome = 0;
            break;
        }

        i++;
        j--;
    }

    if (palindrome)
        printf("The string is a palindrome.");
    else
        printf("The string is not a palindrome.");

    return 0;
}