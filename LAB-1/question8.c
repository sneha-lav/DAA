// 8. Student Result Analysis • Store the roll number, name, and marks in five subjects for N students using structures. • Calculate the total, percentage, and grade of each student. • Display the class topper, students who failed in one or more subjects, and the class average.

#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

int main()
{
    int n, i, j, topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        printf("Enter marks of 5 subjects: ");

        for (j = 0; j < 5; j++)
        {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5;

        // Calculate grade
        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        classTotal += s[i].percentage;

        // Find topper
        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    // Display results
    printf("\n--- Student Results ---\n");

    for (i = 0; i < n; i++)
    {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %.2f", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Class topper
    printf("\n--- Class Topper ---\n");
    printf("Name: %s", s[topper].name);
    printf("\nRoll No: %d", s[topper].roll);
    printf("\nPercentage: %.2f%%\n", s[topper].percentage);

    // Failed students
    printf("\n--- Students Who Failed ---\n");

    for (i = 0; i < n; i++)
    {
        int failed = 0;

        for (j = 0; j < 5; j++)
        {
            if (s[i].marks[j] < 40)
            {
                failed = 1;
                break;
            }
        }

        if (failed)
            printf("%s (Roll No: %d)\n", s[i].name, s[i].roll);
    }

    // Class average
    printf("\nClass Average: %.2f%%\n", classTotal / n);

    return 0;
}