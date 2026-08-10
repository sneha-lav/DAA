// 10. ATM Transaction System • Create a menu-driven program to check balance, deposit money, withdraw money, and exit. • Prevent a withdrawal when the balance is insufficient. • Maintain and display the last five transactions.

#include <stdio.h>

int main()
{
    float balance = 10000;
    float amount;
    int choice;
    char transactions[5][50];
    int count = 0;

    do
    {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Current Balance: %.2f\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            balance += amount;

            printf("Amount deposited successfully.\n");
            printf("New Balance: %.2f\n", balance);

            sprintf(transactions[count % 5],
                    "Deposited: %.2f", amount);

            count++;
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= balance)
            {
                balance -= amount;

                printf("Withdrawal successful.\n");
                printf("New Balance: %.2f\n", balance);

                sprintf(transactions[count % 5],
                        "Withdrawn: %.2f", amount);

                count++;
            }
            else
            {
                printf("Insufficient balance!\n");
            }

            break;

        case 4:
            printf("\n--- Last 5 Transactions ---\n");

            if (count == 0)
            {
                printf("No transactions yet.\n");
            }
            else
            {
                int start;

                if (count < 5)
                    start = 0;
                else
                    start = count - 5;

                for (int i = start; i < count; i++)
                {
                    printf("%s\n", transactions[i % 5]);
                }
            }

            break;

        case 5:
            printf("Thank you for using the ATM.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
