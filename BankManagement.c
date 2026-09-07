#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
char name[20];
int dip_amt, amt = 100000, acc_no, ac, count = 0;
int trans_amt;
int with_amt;

void divider()
{
    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
}

void menu()
{
    system("cls");
    divider();
    printf("\n\tMENU\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account Details\n");
    printf("5.Transaction Details\n");
    printf("6.Exit\n");
    divider();
}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("-----DEPOSITING  MONEY-----\n");
    divider();
    printf("\nEnter the amount you want to deposit:\n");
    scanf("%d", &dip_amt);
    amt = amt + dip_amt;
    printf("-----MONEY DEPOSITED-----\n");
    divider();
    printf("\nNow balance: %d\n", amt);
    fprintf(ptr, "Rs.%d had been deposited to your account\n", dip_amt);
    fprintf(ptr, "Date/Time of the transaction: %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Press any key.......");
    getch();
}

void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("-----WITHDRAWING MONEY-----\n");
    divider();
    printf("\nEnter the amount you want to withdraw:\n");
    scanf("%d", &with_amt);
    if (amt < with_amt)
    {
        printf("-----INSUFFICIENT AMOUNT-----\n");
    }
    else
    {
        amt = amt - with_amt;
        printf("-----MONEY WITHDRAWN-----\n");
        divider();
        printf("\nCurrent balance: %d\n", amt);
        fprintf(ptr, "Rs.%d had been withdrawn from your account\n", with_amt);
        fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
        count++;
    }

    fclose(ptr);
    printf("Press any key.......");
    getch();
}

void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("-----TRANFERRING MONEY-----\n");
    divider();
    printf("\nEnter the account no. in which you want to transfer the money:\n");
    scanf("%d", &ac);
    printf("Enter the amount you want to transfer:\n");
    scanf("%d", &trans_amt);
    if (amt < trans_amt)
    {
        printf("-----YOU HAVE INSUFFICIENT BALANCE-----\n");
    }
    else
    {
        amt = amt - trans_amt;
        printf("-----MONEY TRANSFERRED-----\n");
        divider();
        printf("\nCurrent balance: %d\n", amt);
        fprintf(ptr, "Rs.%d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of Transaction: %s\n", ctime(&tm));
        count++;
    }

    fclose(ptr);
    printf("Press any key.......");
    getch();
}

void checkDetail()
{
    printf("-----ACCOUNT DETAILS-----\n");
    divider();
    printf("\nName: %s\n", name);
    printf("Account No.: %d\n", acc_no);
    printf("Total Balance: %d\n", amt);
    printf("%d transactions have been made from your account\n", count);
    printf("Press any key.......");
    getch();
}

void transaction_details()
{
    system("cls");
    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("-----TRANSACTION DETAILS-----\n");
        divider();
        printf("\n-----NO RECENT TRANSACTION-----\n");
    }
    else
    {
        printf("-----TRANSACTION DETAILS-----\n");
        divider();
        printf("\n%d transactions have been made from your account\n", count);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }
    printf("Press any key to exit.......");
    getch();
}

void LastDetail()
{
    printf("-----ACCOUNT DETAILS-----\n");
    divider();
    printf("\nName: %s\n", name);
    printf("Account No.: %d\n", acc_no);
    printf("Total Balance: %d\n", amt);
    printf("%d transactions have been made from your account\n", count);
    printf("Press any key to exit.......");
    getch();
}

int main()
{
    FILE *ptr = fopen("Account.txt", "w");
    int ch;
    printf("Enter your name:\n");
    gets(name);
    fprintf(ptr, "\nName: %s\n", name);
    printf("Enter your account no.:\n");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no.:%d\n", acc_no);
    fclose(ptr);
    while (1)
    {
        menu();
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            deposit_money();
            break;
        case 2:
            system("cls");
            withdraw_money();
            break;
        case 3:
            system("cls");
            transfer_money();
            break;
        case 4:
            system("cls");
            checkDetail();
            break;
        case 5:
            system("cls");
            transaction_details();
            break;
        case 6:
            system("cls");
            LastDetail();
            break;
        default:
            printf("-----INVALID CHOICE-----");
        }
    }
    return 0;
}