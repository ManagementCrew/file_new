#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <unistd.h>
#include <conio.h>
#include "store.h"
#include "hospital.h"

int i, a, b, j;
int exit_menu;

struct date
{
    int month, day, year;
};

struct user
{
    char user_name[50];
    char gender[10];
    char email[50];
    int account_number, age;
    char user_address[40];
    char user_citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit_amt;
    struct date withdraw_amt;
} _insert, _edit, _cheak, _delete, _amount;

void _quit();
void _manipulate_user();
float bank_interest(float time, float _amount, int rate);
void _view_user_list();
float deposit(float balance);
float withdraw(float balance);
void atm_menu();
void exit_atm_service();
void _end_program(void);
void _error();
void balance_query(float balance);
void _insert_user();
void _edit_user(void);
void transaction_amt(void);
void _delete_user(void);
void _detail_view_user_list();
void atm();
void rectangle_format_wd();
void choose_bhs();
int password();
void rect_username();
void rect_password();
void _main_menu();
void main_menu_();

void _insert_user()

{

    int choice;
    FILE *fp;

    fp = fopen("bank_info.dat", "a+");
account_number:
    system("cls");

    gotoxy(71, 6);
    printf(UWHITE "             INSERT USER DETAILS             ");
    fflush(stdin);
    gotoxy(71, 9);
    printf(YELLOW "ENTER TODAY'S DATE (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &_insert.deposit_amt.year, &_insert.deposit_amt.month, &_insert.deposit_amt.day);
    fflush(stdin);

    int A = 71;
    gotoxy(A, 10);
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%d", &_cheak.account_number);
    fflush(stdin);

    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
        if (_cheak.account_number == _insert.account_number)
        {
            printf("ACCOUNT NUMBER IS ALREADY IN USE :)");
            getch();
            goto account_number;
        }
    }
    _insert.account_number = _cheak.account_number;

    gotoxy(A, 11);
    printf("ENTER USERNAME : ");
    gets(_insert.user_name);
    fflush(stdin);

    gotoxy(A, 12);
    printf("ENTER DATE OF BIRTH (YYYY//MM/DD) : ");
    scanf("%d/%d/%d", &_insert.dob.year, &_insert.dob.month, &_insert.dob.day);
    fflush(stdin);

    gotoxy(A, 13);
    printf("ENTER GENDER : ");
    gets(_insert.gender);
    fflush(stdin);

    gotoxy(A, 14);
    printf("Enter AGE : ");
    scanf("%d", &_insert.age);
    fflush(stdin);

    gotoxy(A, 15);
    printf("ENTER ADDRESS : ");
    gets(_insert.user_address);
    fflush(stdin);

    gotoxy(A, 16);
    printf("ENTER E-MAIL : ");
    gets(_insert.email);
    fflush(stdin);

    gotoxy(A, 17);
    printf("ENTER PHONE NUMBER : ");
    scanf("%lf", &_insert.phone);
    fflush(stdin);

    gotoxy(A, 18);
    printf("ENTER YOUR CITIZENSHIP NUMBER : ");
    scanf("%s", _insert.user_citizenship);
    fflush(stdin);

    gotoxy(A, 19);
    printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT : RS. ");
    scanf("%f", &_insert.amt);
    fflush(stdin);

    gotoxy(A, 20);
    printf("TYPE OF ACCOUNT : ");

    gotoxy(A, 21);
    printf("$ SAVING ");

    gotoxy(A, 22);
    printf("$ CURRENT ");

    gotoxy(A, 23);
    printf("$ FIXED1 (FOR 1 YEAR) ");

    gotoxy(A, 24);
    printf("$ FIXED2 (FOR 2 YEAR) ");

    gotoxy(A, 25);
    printf("$ FIXED1 (FOR 3 YEAR) ");

    gotoxy(A, 26);
    printf("ENTER YOUR CHOICE : ");
    gets(_insert.acc_type);

    fprintf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
    fclose(fp);
    gotoxy(A, 27);
    printf("ACCOUNT CREATED SUCCESSFULLY !!");

INVALID:
    gotoxy(A, 29);
    printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
    scanf("%d", &exit_menu);

    system("cls");
    if (exit_menu == 1)
        _main_menu();
    else if (exit_menu == 0)
    {
        _end_program();
    }
    else
    {
        gotoxy(A, 30);
        printf("INVALID INPUT !! ");
        goto INVALID;
    }
}

void _delete_user(void)
{
    char yn[2];
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("bank_info.dat", "r");
    newrec = fopen("new.dat", "w");
    system("cls");
    //_HEADER(0);
    gotoxy(65, 7);
    printf("ENTER THE ACCOUNT NUMBER OF THE CUSTOMER : ");
    scanf("%d", &_delete.account_number);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
        if (_insert.account_number == _delete.account_number)
        {
            gotoxy(71, 10);
            printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
            gotoxy(71, 11);
            printf("USER NAME : %s ", _insert.user_name);
            gotoxy(71, 12);
            printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
            gotoxy(71, 13);
            printf("ADDRESS : %s ", _insert.user_address);
            gotoxy(71, 14);
            printf("EMAIL : %s ", _insert.email);
            gotoxy(71, 15);
            printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
            gotoxy(71, 16);
            printf("AGE : %d ", _insert.age);
            gotoxy(71, 17);
            printf("PHONE NUMBER : %.0lf ", _insert.phone);
            gotoxy(71, 18);
            printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);

            gotoxy(70, 20);
            printf(RED "DO YOU WANT OT DELETE THE USER ID (y/n) : ");
            scanf("%s", yn);

            if (strcmpi(yn, "Y") == 0)
            {
                test++;
                gotoxy(70, 22);
                printf(RED "RECORD DELETED SUCCESSFULLY !!");
                printf(RESET);
            }
            else
            {
                _main_menu();
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");
    if (test == 0)
    {
        gotoxy(65, 8);
        printf("RECORD NOT FOUND !! ");
    erase_invalid:
        gotoxy(65, 24);
        printf("ENTER [0] TO TRY AGAIN [1] TO GO BACK [2] TO EXIT !! ");
        scanf("%d", &exit_menu);

        if (exit_menu == 1)
            _main_menu();
        else if (exit_menu == 2)
            _end_program();
        else if (exit_menu == 0)
            _delete_user();
        else
        {
            gotoxy(65, 25);
            printf("INVALID !!");
            goto erase_invalid;
        }
    }
    else
    {
        gotoxy(65, 25);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else
            _end_program();
    }
}

void transaction_amt(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("bank_info.dat", "r");
    newrec = fopen("new.dat", "w");
    system("cls");
    //_HEADER(0);
    gotoxy(70, 6);
    printf(YELLOW "ENTER THE ACCOUNT NUMBER OF THE CUSTOMER : ");
    scanf("%d", &_amount.account_number);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {

        if (_insert.account_number == _amount.account_number)
        {
            test = 1;
            if (strcmpi(_insert.acc_type, "fixed1") == 0 || strcmpi(_insert.acc_type, "fixed2") == 0 || strcmpi(_insert.acc_type, "fixed3") == 0)
            {
                gotoxy(70, 7);
                printf("YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS !!!!!");
                system("cls");
                _main_menu();
            }
            rectangle_format();
            gotoxy(71, 10);
            printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
            gotoxy(71, 11);
            printf("USER NAME : %s ", _insert.user_name);
            gotoxy(71, 12);
            printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
            gotoxy(71, 13);
            printf("ADDRESS : %s ", _insert.user_address);
            gotoxy(71, 14);
            printf("EMAIL : %s ", _insert.email);
            gotoxy(71, 15);
            printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
            gotoxy(71, 16);
            printf("AGE : %d ", _insert.age);
            gotoxy(71, 17);
            printf("PHONE NUMBER : %.0lf ", _insert.phone);
            gotoxy(71, 18);
            printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
            gotoxy(71, 19);
            printf("CURRENT BALANCE : %.2f ", _insert.amt);
            gotoxy(70, 22);
            printf("WHAT DO YOU WANT TO DO ?");
            gotoxy(70, 24);
            printf("[1]. DEPOSIT ");
            gotoxy(70, 25);
            printf("[2]. WITHDRAW ");
            gotoxy(70, 26);
            printf("ENTER A CHOICE : ");

            scanf("%d", &choice);
            if (choice == 1)
            {
                gotoxy(70, 29);
                printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT : RS. ");
                scanf("%f", &_amount.amt);
                _insert.amt += _amount.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(70, 31);
                printf("SUCCESSFULLY DEPOSITED !!");
            }
            else if (choice == 2)
            {
                gotoxy(70, 29);
                printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW : RS. ");
                scanf("%f", &_amount.amt);
                _insert.amt -= _amount.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(70, 31);
                printf("SUCCESSFULLY WITHDRAWN !! ");
            }
            else
            {
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(71, 10);
                printf(RED "RECORD NOT FOUND ");
                getch();
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");
    if (test != 1)
    {
        gotoxy(71, 10);
        printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
        gotoxy(71, 11);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);

        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else if (exit_menu == 0)
        {
            _end_program();
        }
        else
        {
            gotoxy(71, 10);
            printf("INVALID INPUT !! ");
            goto EDIT_INVALID;
        }
    }
    else
    {

        gotoxy(68, 32);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else
            _end_program();
    }
}

void _edit_user(void)
{
    int choice, test = 0;
    FILE *fp, *fp2;
    fp = fopen("bank_info.dat", "r");
    fp2 = fopen("new.dat", "w");
_edit_loop:
    system("cls");
    gotoxy(68, 6);
    printf(UWHITE "ENTER THE ACCOUNT NUMBER YOU WANT TO MODIFY : ");
    scanf("%d", &_edit.account_number);

    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
        if (_insert.account_number == _edit.account_number)
        {
            gotoxy(71, 10);
            printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
            gotoxy(71, 11);
            printf("USER NAME : %s ", _insert.user_name);
            gotoxy(71, 12);
            printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
            gotoxy(71, 13);
            printf("ADDRESS : %s ", _insert.user_address);
            gotoxy(71, 14);
            printf("EMAIL : %s ", _insert.email);
            gotoxy(71, 15);
            printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
            gotoxy(71, 16);
            printf("AGE : %d ", _insert.age);
            gotoxy(71, 17);
            printf("PHONE NUMBER : %.0lf ", _insert.phone);
            gotoxy(71, 18);
            printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
            test = 1;
            gotoxy(68, 23);
            printf("WHICH INFORMATION DO YOU WANT TO CHANGE ?");
            rectangle_format();
            gotoxy(68, 24);
            printf("[1]. ADDRESS");
            gotoxy(68, 25);
            printf("[2]. E-MAIL");
            gotoxy(68, 26);
            printf("[3]. PHONE");
            gotoxy(68, 28);
            printf("ENTER YOUR CHOICE : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                gotoxy(68, 30);
                fflush(stdin);
                printf("ENTER THE NEW ADDRESS : ");
                gets(_edit.user_address);
                fflush(stdin);
                fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _edit.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(68, 31);
                printf("CHANGES SAVED !!");
            }
            else if (choice == 2)
            {
                gotoxy(68, 29);
                printf("ENTER THE NEW E-MAIL : ");
                scanf("%s", &_edit.email);
                fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _edit.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(68, 31);
                printf("CHANGES SAVED !!");
            }
            else if (choice == 3)
            {
                gotoxy(68, 29);
                printf("ENTER THE NEW PHONE NUMBER :");
                scanf("%lf", &_edit.phone);
                fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _edit.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(68, 31);
                printf("CHANGES SAVED !!");
            }
        }
        else
        {
            fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
        }
    }
    fclose(fp);
    fclose(fp2);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");
    if (test != 1)
    {
        gotoxy(71, 10);
        printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
        gotoxy(71, 11);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);

        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else if (exit_menu == 0)
        {
            _end_program();
        }
        else
        {
            gotoxy(71, 10);
            printf("INVALID INPUT !! ");
            goto EDIT_INVALID;
        }
    }
    else
    {

        gotoxy(68, 32);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else
            _end_program();
    }
}

float bank_interest(float time, float _amount, int rate)
{
    float SI;
    SI = (rate * time * _amount) / 100.0;
    return (SI);
}

void _view_user_list()
{
    FILE *fp;
    fp = fopen("bank_info.dat", "r");
    int test = 0;
    system("cls");
    gotoxy(70, 1);
    printf(BYELLOW);
    printf("CUSTOMER INFORMATION LIST\n");
    for (i = 1; i <= 168; i++)
    {
        printf("-");
    }

    a = 3;
    gotoxy(1, a);
    printf("AC_NO");
    gotoxy(25, a);
    printf("USER NAME");
    gotoxy(50, a);
    printf("ADDRESS");
    gotoxy(75, a);
    printf("PHONE_NO");
    gotoxy(100, a);
    printf("AGE");
    gotoxy(125, a);
    printf("EMAIL");
    gotoxy(150, a);
    printf("BALANCE");
    printf("\n");
    for (i = 1; i <= 168; i++)
    {
        printf("-");
    }

    i = 6;
    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
        test = 1;
        gotoxy(1, i);
        printf("%d", _insert.account_number);
        gotoxy(25, i);
        printf("%s", _insert.user_name);
        gotoxy(50, i);
        printf("%s", _insert.user_address);
        gotoxy(75, i);
        printf("%lf", _insert.phone);
        gotoxy(100, i);
        printf("%d", _insert.age);
        gotoxy(125, i);
        printf("%s", _insert.email);
        gotoxy(150, i);
        printf("%f", _insert.amt);
        i++;
    }

    fclose(fp);
    if (test == 0)
    {
        system("cls");
        printf("\n\nNO RECORDS FOUND !!");
    }

view_list_invalid:

    printf("\n\nENTER [1] TO GO BACK AND [0] TO EXIT : ");
    scanf("%d", &exit_menu);
    system("cls");
    if (exit_menu == 1)
        _main_menu();
    else if (exit_menu == 0)
        _end_program();
    else
    {
        printf("INVALID INPUT !!\a");
        goto view_list_invalid;
    }
}

void _end_program(void)
{
    printf("\n\n\n\nThank You!");
}

void _manipulate_user()
{

    int ch;
    system("cls");
    content_2();
    rect_bsh1();
    rect_bsh2();
    rect_bsh3();
    rect_bsh5();
    gotoab(58, 11);
    puts("##### WHAT DO YOU WANT TO DO HERE ??? #####");
    gotoab(15, 14);
    printf(" (1).  INSERT      ");
    gotoab(15, 17);
    printf("    USER DETAILS   ");
    gotoab(70, 14);
    printf("   (2).  EDIT      ");
    gotoab(70, 17);
    printf("     USER DETAILS  ");
    gotoab(120, 14);
    printf("      (3). DO      ");
    gotoab(120, 17);
    printf("     TRANSACTIONS  ");
    gotoab(70, 27);
    printf(" (4).  DELETE      ");
    gotoab(70, 29);
    printf("    USER DETAILS   ");
    gotoab(70, 35);
    printf("[  (5).  EXIT     ]");

    gotoab(70, 37);
    printf("PLEASE, ENTER YOUR CHOICE : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        _insert_user(); 
        break;
    case 2:
        _edit_user(); 
        break;
    case 3:
        transaction_amt();
                break;
    case 4:
        _delete_user();
        break;
    case 5:
        _main_menu();
        break;
    }
}

void withdrawn()
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("bank_info.dat", "r");
    newrec = fopen("new.dat", "w");
    system("cls");
    //_HEADER(0);
    gotoxy(70, 6);
    printf(YELLOW "ENTER THE ACCOUNT NUMBER OF THE CUSTOMER : ");
    scanf("%d", &_amount.account_number);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {

        if (_insert.account_number == _amount.account_number)
        {
            test = 1;
            if (strcmpi(_insert.acc_type, "fixed1") == 0 || strcmpi(_insert.acc_type, "fixed2") == 0 || strcmpi(_insert.acc_type, "fixed3") == 0)
            {
                gotoxy(70, 7);
                printf("YOU CANNOT WITHDRAW CASH IN FIXED ACCOUNTS !!!!!");
                system("cls");
                _main_menu();
            }
            rectangle_format();
            gotoxy(71, 10);
            printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
            gotoxy(71, 11);
            printf("USER NAME : %s ", _insert.user_name);
            gotoxy(71, 12);
            printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
            gotoxy(71, 13);
            printf("ADDRESS : %s ", _insert.user_address);
            gotoxy(71, 14);
            printf("EMAIL : %s ", _insert.email);
            gotoxy(71, 15);
            printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
            gotoxy(71, 16);
            printf("AGE : %d ", _insert.age);
            gotoxy(71, 17);
            printf("PHONE NUMBER : %.0lf ", _insert.phone);
            gotoxy(71, 18);
            printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
            ;
            gotoxy(70, 24);
            printf("WHAT DO YOU WANT TO DO ?");
            gotoxy(70, 25);
            printf("[1]. SEE BALANCE ");
            gotoxy(70, 26);
            printf("[2]. WITHDRAW ");
            gotoxy(70, 27);
            printf("ENTER A CHOICE : ");

            scanf("%d", &choice);
            if (choice == 1)
            {
                system("cls");
                //_HEADER(0);
                gotoxy(66, 10);
                printf(UWHITE "HI !! YOU WANT TO CHECK BALANCE OF YOUR ACCOUNT ");
                gotoxy(66, 12);
                printf(GREEN "YOUR AVAILABLE BALANCE IS : RS.%.2f", _insert.amt);
                printf(RESET);
            }
            else if (choice == 2)
            {
                gotoxy(70, 29);
                printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW : RS. ");
                scanf("%f", &_amount.amt);
                _insert.amt -= _amount.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(70, 31);
                printf("SUCCESSFULLY WITHDRAWN !! ");
            }
            else
            {
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
                gotoxy(71, 10);
                printf(RED "RECORD NOT FOUND ");
                getch();
                fclose(old);
                fclose(newrec);
                remove("bank_info.dat");
                rename("new.dat", "bank_info.dat");
                break;
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n", _insert.account_number, _insert.user_name, _insert.dob.day, _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone, _insert.acc_type, _insert.amt, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year);
            fclose(old);
            fclose(newrec);
            remove("bank_info.dat");
            rename("new.dat", "bank_info.dat");
            break;
        }
    }

    if (test != 1)
    {
        gotoxy(71, 10);
        printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
        gotoxy(71, 11);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);

        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else if (exit_menu == 0)
        {
            _end_program();
        }
        else
        {
            gotoxy(71, 10);
            printf("INVALID INPUT !! ");
            goto EDIT_INVALID;
        }
    }
    else
    {

        gotoxy(68, 32);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else
            _end_program();
    }
}

void exit_atm_service()
{
    system("cls");
    gotoxy(70, 17);
    printf(" THANKS FOR VISITING ATM SERVICE ");
    gotoxy(70, 19);
    printf(" I AM VERY PLEASED TO SEE YOU HERE... ");

} // exit menu

void _error()
{
    printf("SORRY !! YOU HAVE SELECTED INVALID NUMBER ,PRESS ANY KEY...");
}

void _detail_view_user_list()
{
    system("cls");
    //_HEADER(0);
    FILE *old;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    old = fopen("bank_info.dat", "r");

    rectangle_format();
    printf(YELLOW);
    gotoxy(77, 10);
    printf("DO YOU WANT TO CHEAK BY :");
    gotoxy(71, 12);
    printf("[1]. ACCOUNT NUMBER");
    gotoxy(71, 13);
    printf("[2]. NAME ");
    gotoxy(71, 15);
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        gotoxy(71, 17);
        printf("ENTER THE ACCOUNT NUMBER :");
        scanf("%d", &_cheak.account_number);

        while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
        {
            if (_insert.account_number == _cheak.account_number)
            {
                system("cls");
                //_HEADER(0);
                test = 1;
                rectangle_format();
                gotoxy(71, 9);
                printf(UWHITE "         USER INFORMATION            ");
                gotoxy(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
                gotoxy(71, 11);
                printf("USER NAME : %s ", _insert.user_name);
                gotoxy(71, 12);
                printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
                gotoxy(71, 13);
                printf("ADDRESS : %s ", _insert.user_address);
                gotoxy(71, 14);
                printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
                gotoxy(71, 15);
                printf("AGE : %d ", _insert.age);
                gotoxy(71, 16);
                printf("PHONE NUMBER : %.0lf ", _insert.phone);
                gotoxy(71, 17);
                printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
                gotoxy(71, 18);
                printf("BALANCE AMOUNT : %.2f", _insert.amt);
                if (strcmpi(_insert.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 1);
                }
                else if (strcmpi(_insert.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 2);
                }
                else if (strcmpi(_insert.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 3);
                }
                else if (strcmpi(_insert.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(68, 20);
                    printf("INTEREST AMOUNT ON %dth OF EVERY MONTH : %.2f", _insert.deposit_amt.day, intrst);
                }
                else if (strcmpi(_insert.acc_type, "current") == 0)
                {

                    gotoxy(71, 20);
                    printf("YOU WILL NOT GET BANK INTEREST.");
                }
            }
        }
    }
    else if (choice == 2)
    {
        gotoxy(71, 17);
        printf("ENTER THE USER NAME :");
        scanf("%s", &_cheak.user_name);
        while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d", &_insert.account_number, _insert.user_name, &_insert.dob.day, &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address, _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone, _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month, &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
        {
            if (strcmpi(_insert.user_name, _cheak.user_name) == 0)
            {
                system("cls");
                test = 1;
                rectangle_format();
                gotoxy(71, 9);
                printf(UWHITE "         USER INFORMATION            ");
                gotoxy(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
                gotoxy(71, 11);
                printf("USER NAME : %s ", _insert.user_name);
                gotoxy(71, 12);
                printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year, _insert.dob.month, _insert.dob.day);
                gotoxy(71, 13);
                printf("ADDRESS : %s ", _insert.user_address);
                gotoxy(71, 14);
                printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
                gotoxy(71, 15);
                printf("AGE : %d ", _insert.age);
                gotoxy(71, 16);
                printf("PHONE NUMBER : %.0lf ", _insert.phone);
                gotoxy(71, 17);
                printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
                gotoxy(71, 18);
                printf("AMOUNT DEPOSITED : %d ", _insert.amt);
                gotoxy(71, 19);
                printf("DATE OF DEPOSIT : %d / %d / %d ", _insert.deposit_amt.year, _insert.deposit_amt.month, _insert.deposit_amt.day);

                if (strcmpi(_insert.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 1);
                }
                else if (strcmpi(_insert.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 2);
                }
                else if (strcmpi(_insert.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(66, 20);
                    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d", intrst, _insert.deposit_amt.month, _insert.deposit_amt.day, _insert.deposit_amt.year + 3);
                }
                else if (strcmpi(_insert.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = bank_interest(time, _insert.amt, rate);
                    gotoxy(68, 20);
                    printf("INTEREST AMOUNT ON %dth OF EVERY MONTH : %.2f", _insert.deposit_amt.day, intrst);
                }
                else if (strcmpi(_insert.acc_type, "current") == 0)
                {
                    gotoxy(71, 20);
                    printf("YOU WILL NOT GET BANK INTEREST");
                }
            }
        }
    }

    fclose(old);
    if (test != 1)
    {
        system("cls");
        gotoxy(71, 8);
        printf("RECORD NOT FOUND !!");
    see_invalid:
        gotoxy(71, 8);
        printf("ENTER [0] TO TRY AGAIN [1] TO RETURN TO MAIN MENU AND [2] TO EXIT :");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            _main_menu();
        else if (exit_menu == 2)
            _end_program();
        else if (exit_menu == 0)
            _detail_view_user_list();
        else
        {
            system("cls");
            gotoxy(70, 5);
            printf("INVALID !!");
            goto see_invalid;
        }
    }
    else
    {
        gotoxy(65, 23);
        printf("ENTER [1] TO RETURN TO MAIN MENU AND [2] TO EXIT :");
        scanf("%d", &exit_menu);
    }
    if (exit_menu == 1)
    {
        system("cls");
        _main_menu();
    }

    else
    {

        system("cls");
        _end_program();
    }
}

void _quit()
{
    FILE *fp;
    system("cls");
    //_HEADER(0);
    system("color B1");
    char c;
    gotoxy(69, 11);
    printf("THANKS FOR YOUR PRECIOUS TIME");
    gotoxy(68, 13);
    printf("WE ARE PLEASED TO SEE YOU HERE :)");
    gotoxy(67, 15);
    printf("HOW WAS YOUR EXPERIENCE WITH US ??");
    gotoxy(66, 17);
    printf("DO YOU WANT TO GIVE US RATING [y/n] :");
    scanf("%s", &c);

    while (c = 'y')
    {
        int x;
        fp = fopen("rating.txt", "ab");
        gotoxy(60, 19);
        printf(" YOU CAN GIVE US RATING (should not exceed 5 ratings) :");
        scanf("%d", &x);
        putw(x, fp);
        fclose(fp);

        gotoxy(70, 21);
        printf("THANKS FOR GIVING US RATING...");
        gotoxy(75, 23);
        printf("PRESS ANY KEY...");
        getch();
        exit(0);
    }
}

int main()
{
    system("cls");
    HEADER();
    content_1();
    password();
}

int password()
{
    fflush(stdin);
    char username[20];
    static char password[6];
    int b;
    int s = 58;
    gotoab(s, 13);
    puts("####### Welcome Users !! Please verify login page to continue #######");

    rect_username();
    int a;
    a = 16;
    char name[20];
psw:
    gotoab(58, a);
    printf("UserName : |                                       |");
    gotoab(71, a);
    scanf("%s", &username);
    if (strcmpi(username, "bikash") == 0 || strcmpi(username, "managementcrew") == 0)
    {
        sleep(1);
        gotoab(58, 18);
        printf(GREEN "Username Verified ...");
        printf(RESET);
        a = 20;
        int i = 0;
        char character, pass[20], password[20];
        rect_password();
        gotoab(58, a);
        printf("Password :   ");

        while (1)
        {

            printf(WHITE);
            //   gotoab(70, a);
            character = _getch();

            if (character == 13)
            {
                password[i] = '\0';
                break;
            }

            else if (character == 8)
            {
                i--;
                printf("\b \b");
            }
            else
            {
                password[i] = character;
                i++;
                printf("*");
            }
        }
        if (strcmp(password, "bikash") == 0 || strcmp(password, "managementcrew") == 0)
        {
            b = 1;
            choose_bhs();
        }
        else
        {
            gotoab(60, 24);
            puts(BRED "OOPS !!");
            gotoab(60, 26);
            puts(BRED "YOU ENTERED INCORRECT USERNAME/PASSWORD...");
            sleep(1);
            gotoab(60, 28);
            puts("PRESS ANY KEY AND TRY AGAIN...");
            getch();
            goto psw;
        }
    }
}

void rect_username()
{
    int i;
    int a = 15;
    gotoab(69, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(69, a);
    printf("%c", 213);
    gotoab(109, a);
    printf("%c", 184);

    a = 17;
    // top
    gotoab(69, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(69, a);
    printf("%c", 212);
    gotoab(109, a);
    printf("%c", 190);
}

void rect_password()
{
    int i;
    int a = 19;
    gotoab(69, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(69, a);
    printf("%c", 213);
    gotoab(109, a);
    printf("%c", 184);

    a = 21;
    gotoab(69, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(69, a);
    printf("%c", 212);
    gotoab(109, a);
    printf("%c", 190);
}

void choose_bhs(){
    int ch;
    system("cls");
    content_1();
    rect_bsh1();
    rect_bsh2();
    rect_bsh3();
    gotoab(58, 11);
    puts("##### Which field you are related from ??? #####");
    gotoab(15, 14);
    printf("  (1).  BANK       ");
    gotoab(15, 17);
    printf(" MANAGEMENT SYSTEM ");
    gotoab(70, 14);
    printf("  (2).  HOSPITAL   ");
    gotoab(70, 17);
    printf(" MANAGEMENT SYSTEM ");
    gotoab(120, 14);
    printf("  (3).  STORE      ");
    gotoab(120, 17);
    printf(" MANAGEMENT SYSTEM ");
    gotoab(70, 24);
    printf("[  (4).  EXIT    ] ");

    gotoab(70, 28);
    printf("ENTER A CHOICE : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("cls");
        _main_menu();

        break;
    case 2:
        main_menu_();
        break;
    case 3:
        int choice;
        system("cls");
        gotoab(71, 6);
        int A = 68; // given contant value to x-coordinate
        gotoab(A, 6);
        printf(RESET);
        printf(" HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask user that what he/she want to do...
        gotoab(A, 10);
        printf(YELLOW "[1]. EXPLORE PRODUCTS "); //[6] View customer's list
        gotoab(A, 11);
        printf("[2]. EXPLORE CUSTOMERS "); //[4] Check the account details
        gotoab(A, 12);
        printf("[3]. EXIT ");
        gotoab(A, 15);
        printf(BWHITE "PLEASE, ENTER YOUR CHOICE : "); // ask user to choose "one" among 1 to 5
        scanf("%d", &choice);

        system("cls");
        switch (choice)
        {
        case 1:
            department_menu();
            break;
        case 2:
            main_menu();
            break;
        case 3:
            _end_program();
        }
    case 4:
        system("cls");
        exit(0);
        break;
    default:
        exit(0);
    }
    getch();
}

void _main_menu()
{
    int ch;
    system("cls");
    content_2();
    rect_bsh1();
    rect_bsh2();
    rect_bsh3();
    gotoab(58, 11);
    puts("##### WHAT DO YOU WANT TO DO HERE ??? #####");
    gotoab(15, 14);
    printf("  (1).  VIEW       ");
    gotoab(15, 17);
    printf("    USER DETAILS   ");
    gotoab(70, 14);
    printf("  (2).  SEARCH     ");
    gotoab(70, 17);
    printf("     USER DETAILS  ");
    gotoab(120, 14);
    printf(" (3). MANIPULATE   ");
    gotoab(120, 17);
    printf("    USER  DETAILS  ");
    gotoab(70, 24);
    printf("[  (4).  EXIT     ]");

    gotoab(70, 28);
    printf("PLEASE, ENTER YOUR CHOICE : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        _view_user_list();
        break;
    case 2:
        _detail_view_user_list();
        break;
    case 3:
        _manipulate_user();
        break;
    case 4:
        exit(0);
        break;
    }
}

void main_menu_()
{
    int ch;
    system("cls");
    content_3();
    rect_bsh1();
    rect_bsh2();
    rect_bsh3();
    gotoab(58, 11);
    puts("##### WHAT DO YOU WANT TO DO HERE ??? #####");
    gotoab(15, 14);
    printf("  (1).  VIEW       ");
    gotoab(15, 17);
    printf("    PATIENT DETAILS   ");
    gotoab(70, 14);
    printf("  (2).  SEARCH     ");
    gotoab(70, 17);
    printf("     PATIENT DETAILS  ");
    gotoab(120, 14);
    printf(" (3). MANIPULATE   ");
    gotoab(120, 17);
    printf("    PATIENT  DETAILS  ");
    gotoab(70, 24);
    printf("[  (4).  EXIT     ]");

    gotoab(70, 28);
    printf("PLEASE, ENTER YOUR CHOICE : ");
    scanf("%d", &ch);

    system("cls");
    switch (ch)
    {
    case 1:
        view_patient_list_();
        break;
    case 2:
        detail_view_patient_list_();
        break;
    case 3:
        manipulate_patient_();
        break;
    case 4:
        exit(0);
        break;
    }
}