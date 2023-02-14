#include "color.h"

#define CNN 15
#define CBN 4
int i, a, b, j;
int exit_menu;
struct date_
{
    int month, day, year;
};

struct hospital
{
    int serial_number;
    char name[50];
    char gender[10];
    char email[50];
    char address[40];
    double phone;
    float amount_due;
    float amount_paid;
    float amount_total;
    struct date_ paid_amt;
    struct date_ withdraw_amt;

} insert_, edit_, cheak_, delete_, amount_, trans_;

typedef struct
{
    char name[CNN], code[CBN];
    float rate;
    int quantity;
} hospital_record;
hospital_record _stocks;

void rectangle_format_();
void gotoxy_(int x, int y);
void insert_patient_();
void delete_patient_(void);
void edit_patient_(void);
void main_menu_(void);
void end_program_(void);
void view_patient_list_();
void detail_view_patient_list_();
void _quit_();
void transaction_amt_();
void manipulate_patient_();

void gotoxy_(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void rectangle_format_()
{
    int i;
    gotoxy_(64, 8);
    for (i = 1; i <= 52; i++)
    {
        printf("#");
    }
    a = 64;
    for (i = 9; i <= 20; i++)
    {
        gotoxy_(a, i);
        printf("*");
    }
    a = 115;
    for (i = 9; i <= 20; i++)
    {
        gotoxy_(a, i);
        printf("*");
    }
    gotoxy_(64, 21);
    for (i = 1; i <= 52; i++)
    {
        printf("*");
    }
}

int SUBHEADER_(int bal)
{
    int i;
    system("cls");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }
    printf("\n");
    gotoxy_(88, 1);
    printf(BLUE "HOSPITAL");
    gotoxy_(82, 2);
    printf(BLUE "MANAGEMENT SYSTEM\n");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }
}

void insert_patient_()
{
    int choice;
    FILE *fp;
    fp = fopen("hospital.dat", "a+");
serial_number:
    system("cls");
    gotoxy(71, 6);
    printf(UWHITE " INSERT USER DETAILS ");
    fflush(stdin);
    gotoxy(71, 9);
    printf(YELLOW "ENTER TODAY'S DATE (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &insert_.paid_amt.year, &insert_.paid_amt.month,
          &insert_.paid_amt.day);
    fflush(stdin);
    int A = 71;
    gotoxy_(A, 10);
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%d", &cheak_.serial_number);
    fflush(stdin);
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                  &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                  insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                  &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                  &insert_.paid_amt.day) != EOF)
    {
        if (cheak_.serial_number == insert_.serial_number)
        {
            printf("ACCOUNT NUMBER IS ALREADY IN USE :)");
            getch();
            goto serial_number;
        }
    }
    insert_.serial_number = cheak_.serial_number;

    fflush(stdin);
    gotoxy_(A, 11);
    printf("ENTER PATIENT NAME : ");
    gets(insert_.name);
    fflush(stdin);
    gotoxy_(A, 12);
    printf("ENTER ADDRESS : ");
    gets(insert_.address);
    fflush(stdin);
    gotoxy_(A, 13);
    printf("ENTER GENDER : ");
    gets(insert_.gender);
    fflush(stdin);
    gotoxy_(A, 14);
    printf("ENTER E-MAIL : ");
    gets(insert_.email);
    fflush(stdin);
    gotoxy_(A, 15);
    printf("ENTER PHONE NUMBER : ");
    scanf("%lf", &insert_.phone);
    fflush(stdin);
    gotoxy_(A, 16);
    printf("ENTER THE AMOUNT HE NEED TO PAY : RS. ");
    scanf("%f", &insert_.amount_total);
    fflush(stdin);
    fprintf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
            insert_.serial_number, insert_.name, insert_.address, insert_.gender,
            insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
            insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
            insert_.paid_amt.day);
    fclose(fp);
    gotoxy_(A, 18);
    printf("ACCOUNT CREATED SUCCESSFULLY !!");
INVALID:

    gotoxy_(A, 22);
    printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
    scanf("%d", &exit_menu);
    system("cls");
    if (exit_menu == 1)
        main_menu_();
    else if (exit_menu == 0)
    {
        end_program_();
    }
    else
    {
        gotoxy_(76, 7);
        printf("INVALID INPUT !! ");
        goto INVALID;
    }
}

void delete_patient_(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("hospital.dat", "r");
    newrec = fopen("hospital_new.dat", "w");
    printf("ENTER THE PATIENT'S SERIAL NUMBER OF THE PATIENT : ");
    scanf("%d", &delete_.serial_number);
    while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                  &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                  insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                  &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                  &insert_.paid_amt.day) != EOF)
    {

        if (insert_.serial_number != delete_.serial_number)
            fprintf(newrec, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                    insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                    insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                    insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                    insert_.paid_amt.day);

        else
        {
            test++;
            printf("RECORD DELETE SUCCESSFULLY !!");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("hospital.dat");
    rename("hospital_new.dat", "hospital.dat");
    if (test == 0)
    {
        printf("RECORD NOT FOUND !! ");
    erase_invalid:
        printf("ENTER [0] TO TRY AGAIN [1] TO GO BACK [2] TO EXIT !! ");
        scanf("%d", &exit_menu);
        if (exit_menu == 1)
            main_menu_();
        else if (exit_menu == 2)
            end_program_();
        else if (exit_menu == 0)
            delete_patient_();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);

        system("cls");
        if (exit_menu == 1)
            main_menu_();
        else
            end_program_();
    }
}

void edit_patient_(void)
{
    SUBHEADER_(0);
    rectangle_format_();
    int choice, test = 0;
    FILE *fp, *fp2;
    fp = fopen("hospital.dat", "r");
    fp2 = fopen("hospital_new.dat", "w");
    gotoxy(60, 6);
    printf("ENTER THE PATIENT'S SERIAL NUMBER YOU WANT TO MODIFY : ");
    scanf("%d", &edit_.serial_number);
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                  &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                  insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                  &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                  &insert_.paid_amt.day) != EOF)
    {
        if (insert_.serial_number == edit_.serial_number)
        {
            test = 1;
            gotoxy(70, 10);
            printf(YELLOW "WHICH INFORMATION DO YOU WANT TO CHANGE ?");
            gotoxy(70, 12);
            printf("[1] .ADDRESS");
            gotoxy(70, 13);
            printf("[2] .E-MAIL");

            gotoxy(70, 14);
            printf("[3] .PHONE");
            gotoxy(70, 16);
            printf("ENTER YOUR CHOICE : ");
            scanf("%d", &choice);
            system("cls");
            SUBHEADER_(0);
            rectangle_format_();
            if (choice == 1)
            {
                gotoxy(70, 12);
                printf("ENTER THE NEW ADDRESS : ");
                scanf("%s", edit_.address);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                        insert_.serial_number, insert_.name, edit_.address, insert_.gender,
                        insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                        insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                        insert_.paid_amt.day);

                gotoxy(70, 13);
                printf("CHANGES SAVED !!");
            }
            else if (choice == 2)
            {
                gotoxy(70, 12);
                printf("ENTER THE NEW E-MAIL : ");
                scanf("%s", &edit_.email);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                        insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                        edit_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                        insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                        insert_.paid_amt.day);

                gotoxy(70, 13);
                printf("CHANGES SAVED !!");
            }
            else if (choice == 3)
            {
                gotoxy(70, 12);
                printf("ENTER THE NEW PHONE NUMBER :");

                scanf("%lf", &edit_.phone);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                        insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                        insert_.email, edit_.phone, insert_.amount_due, insert_.amount_paid,
                        insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                        insert_.paid_amt.day);
                gotoxy(70, 13);
                printf("CHANGES SAVED !!");
            }
        }
        else
            fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                    insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                    insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                    insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                    insert_.paid_amt.day);
    }
    fclose(fp);
    fclose(fp2);
    remove("hospital.dat");
    rename("hospital_new.dat", "hospital.dat");
    if (test != 1)
    {
        system("cls");
        gotoxy(70, 8);
        printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
        gotoxy(70, 15);
        printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu_();
        else if (exit_menu == 0)
        {
            end_program_();
        }

        else
        {
            gotoxy(70, 9);
            printf("INVALID INPUT !! ");
            goto EDIT_INVALID;
        }
    }
    else
    {
        gotoxy(70, 15);
        printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu_();
        else
            end_program_();
    }
}

void view_patient_list_()
{
    FILE *fp;
    fp = fopen("hospital.dat", "r");
    int test = 0;
    system("cls");
    gotoxy_(70, 1);
    printf(BYELLOW);
    printf("PATIENT INFORMATION LIST\n");
    for (i = 1; i <= 168; i++)
    {
        printf("-");
    }

    a = 3;
    gotoxy_(1, a);
    printf("S.N.");
    gotoxy_(15, a);
    printf("NAME");
    gotoxy_(50, a);
    printf("ADDRESS");
    gotoxy_(75, a);
    printf("PHONE_NO");
    gotoxy_(100, a);
    printf("EMAIL");
    gotoxy_(125, a);
    printf("DUE AMOUNT");
    printf("\n");
    for (i = 1; i <= 168; i++)
    {
        printf("-");
    }
    i = 6;
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                  &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                  insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                  &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                  &insert_.paid_amt.day) != EOF)
    {
        test = 1;
        gotoxy_(1, i);
        printf("%d", insert_.serial_number);
        gotoxy_(15, i);
        printf("%s", insert_.name);
        gotoxy_(50, i);
        printf("%s", insert_.address);
        gotoxy_(75, i);
        printf("%lf", insert_.phone);
        gotoxy_(100, i);
        printf("%s", insert_.email);
        gotoxy_(125, i);
        printf("%.2f", insert_.amount_due);
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
        main_menu_();
    else if (exit_menu == 0)
        end_program_();
    else
    {
        printf("INVALID INPUT !!\a");
        goto view_list_invalid;
    }
}

void end_program_(void)
{
    printf("\nnTHANK YOU !!");
}

void _error_()
{
    printf("SORRY !! YOU HAVE SELECTED INVALID NUMBER ,PRESS ANY KEY...");
}

void detail_view_patient_list_()
{
    system("cls");
    SUBHEADER_(0);
    FILE *old;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;

    old = fopen("hospital.dat", "r");
    rectangle_format_();
    gotoxy_(77, 10);
    printf(YELLOW);
    printf("DO YOU WANT TO CHEAK BY :");
    gotoxy_(71, 12);
    printf("[1]. ACCOUNT NUMBER");
    gotoxy_(71, 13);
    printf("[2]. NAME ");
    gotoxy_(71, 15);
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        gotoxy_(71, 17);
        printf("ENTER THE ACCOUNT NUMBER :");
        scanf("%d", &cheak_.serial_number);
        while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                      &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                      insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                      &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                      &insert_.paid_amt.day) != EOF)

        {
            if (insert_.serial_number == cheak_.serial_number)
            {
                system("cls");
                SUBHEADER_(0);
                test = 1;
                rectangle_format_();
                gotoxy_(71, 8);
                printf(UWHITE " PATIENT INFORMATION ");
                gotoxy_(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", insert_.serial_number);
                gotoxy_(71, 11);
                printf("PATIENT NAME : %s ", insert_.name);
                gotoxy_(71, 12);
                printf("ADDRESS : %s ", insert_.address);
                gotoxy_(71, 13);

                printf("PHONE NUMBER : %.0lf ", insert_.phone);
                gotoxy_(71, 14);
                printf("PHONE NUMBER : %s ", insert_.email);
                gotoxy_(71, 15);
                printf("TOTAL AMOUNT : %.2f ", insert_.amount_total);
                gotoxy_(71, 16);
                printf("AMOUNT TO BE PAID : %.2f ", insert_.amount_due);
                gotoxy_(71, 17);
                printf("TOTAL PAID AMOUNT : %.2f ", insert_.amount_paid);
                gotoxy_(71, 18);
                printf("DATE OF PAYMENT : %d / %d / %d ", insert_.paid_amt.year, insert_.paid_amt.month, insert_.paid_amt.day);
            }
        }
    }
    else if (choice == 2)
    {
        gotoxy_(71, 17);
        printf("ENTER THE PATIENT NAME :");
        scanf("%d", &cheak_.name);
        while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                      &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                      insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                      &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                      &insert_.paid_amt.day) != EOF)

        {
            if (insert_.serial_number == cheak_.serial_number)
            {
                system("cls");
                SUBHEADER_(0);
                test = 1;
                rectangle_format_();
                gotoxy_(71, 8);
                printf(UWHITE " PATIENT INFORMATION ");
                gotoxy_(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", insert_.serial_number);
                gotoxy_(71, 11);
                printf("PATIENT NAME : %s ", insert_.name);
                gotoxy_(71, 12);

                printf("ADDRESS : %s ", insert_.address);
                gotoxy_(71, 13);
                printf("PHONE NUMBER : %.0lf ", insert_.phone);
                gotoxy_(71, 14);
                printf("PHONE NUMBER : %s ", insert_.email);
                gotoxy_(71, 15);
                printf("TOTAL AMOUNT : %s ", insert_.amount_total);
                gotoxy_(71, 16);
                printf("AMOUNT TO BE PAID : %s ", insert_.amount_due);
                gotoxy_(71, 17);
                printf("TOTAL PAID AMOUNT : %s ", insert_.amount_paid);
                gotoxy_(71, 18);
                printf("DATE OF PAYMENT : %d / %d / %d ",

                       insert_.paid_amt.year, insert_.paid_amt.month, insert_.paid_amt.day);
            }
        }
    }
    fclose(old);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu_();
        else if (exit_menu == 2)
            end_program_();
        else if (exit_menu == 0)
            detail_view_patient_list_();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &exit_menu);
    }
    if (exit_menu == 1)
    {
        system("cls");
        main_menu_();
    }
    else
    {
        system("cls");
        end_program_();
    }
}

void _quit_()
{
    FILE *fp;
    system("cls");
    SUBHEADER_(0);
    system("color B1");
    char c;
    gotoxy_(69, 11);
    printf("THANKS FOR YOUR PRECIOUS TIME");
    gotoxy_(68, 13);
    printf("WE ARE PLEASED TO SEE YOU HERE :)");
    gotoxy_(67, 15);
    printf("HOW WAS YOUR EXPERIENCE WITH US ??");
    gotoxy_(66, 17);
    printf("DO YOU WANT TO GIVE US RATING [y/n] :");

    scanf("%s", &c);
    while (c = 'y')
    {
        int x;
        fp = fopen("rating.txt", "ab");
        gotoxy_(60, 19);
        printf(" YOU CAN GIVE US RATING (should not exceed 5 ratings) :");
        scanf("%d", &x);
        putw(x, fp);
        fclose(fp);
        gotoxy_(70, 21);
        printf("THANKS FOR GIVING US RATING...");
        gotoxy_(75, 23);
        printf("PRESS ANY KEY...");
        getch();
        exit(0);
    }
}

void manipulate_patient_()
{
    int ch;
    system("cls");
    content_3();
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
        insert_patient_();
        break;
    case 2:
        edit_patient_();
        break;
    case 3:
        transaction_amt_();
        break;
    case 4:
        delete_patient_();
        break;
    case 5:
        end_program_();
        break;
    }
}

void transaction_amt_(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("hospital.dat", "r");
    newrec = fopen("hospital_new.dat", "w");
    system("cls");
    gotoxy(70, 6);
    printf(YELLOW "ENTER THE SERIAL NUMBER OF THE PATIENT : ");
    scanf("%d", &amount_.serial_number);

    while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                  &insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                  insert_.email, &insert_.phone, &insert_.amount_due, &insert_.amount_paid,
                  &insert_.amount_total, &insert_.paid_amt.year, &insert_.paid_amt.month,
                  &insert_.paid_amt.day) != EOF)
    {
        if (insert_.serial_number == amount_.serial_number)
        {
            test = 1;
            rectangle_format();
            gotoxy_(71, 9);
            printf(UWHITE " PATIENT INFORMATION ");
            gotoxy_(71, 10);
            printf(YELLOW "ACCOUNT NO : %d ", insert_.serial_number);
            gotoxy_(71, 11);
            printf("PATIENT NAME : %s ", insert_.name);
            gotoxy_(71, 12);
            printf("ADDRESS : %s ", insert_.address);
            gotoxy_(71, 13);
            printf("PHONE NUMBER : %lf ", insert_.phone);
            gotoxy_(71, 14);
            printf("EMAIL : %s ", insert_.email);
            gotoxy_(71, 15);
            printf("TOTAL AMOUNT : %.2f ", insert_.amount_total);
            gotoxy_(71, 16);
            printf("AMOUNT TO BE PAID : %.2f ", insert_.amount_due);
            gotoxy_(71, 17);
            printf("TOTAL PAID AMOUNT : %.2f ", insert_.amount_paid);
            gotoxy_(71, 18);
            printf("DATE OF PAYMENT : %d / %d / %d ", insert_.paid_amt.year, insert_.paid_amt.month, insert_.paid_amt.day);
            gotoxy(70, 22);
            printf("WHAT DO YOU WANT TO DO ?");
            gotoxy(70, 24);
            printf("[1]. PAYMENT ");
            gotoxy(70, 25);
            printf("[2]. GO BACK ");
            gotoxy(70, 26);
            printf("ENTER A CHOICE : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                gotoxy(70, 29);
                printf("ENTER THE PAID AMOUNT : RS. ");
                scanf("%f", &amount_.amount_paid);
                insert_.amount_due = insert_.amount_total - amount_.amount_paid;

                fprintf(newrec, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                        insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                        insert_.email, insert_.phone, insert_.amount_due, amount_.amount_paid,
                        insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                        insert_.paid_amt.day);
                gotoxy(70, 31);
                printf("SUCCESSFULLY DEPOSITED !!");
            }
            else if (choice == 2)
            {
                manipulate_patient_();
            }
            else
            {
                fprintf(newrec, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                        insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                        insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                        insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                        insert_.paid_amt.day);
                gotoxy(71, 10);
                printf(RED "RECORD NOT FOUND ");
                getch();
            }
        }
        else
        {
            fprintf(newrec, "%d %s %s %s %s %lf %f %f %f %d/%d/%d\n",
                    insert_.serial_number, insert_.name, insert_.address, insert_.gender,
                    insert_.email, insert_.phone, insert_.amount_due, insert_.amount_paid,
                    insert_.amount_total, insert_.paid_amt.year, insert_.paid_amt.month,
                    insert_.paid_amt.day);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("hospital.dat");
    rename("hospital_new.dat", "hospital.dat");
    int exit_menu;
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
            main_menu_();
        else if (exit_menu == 0)
        {
            end_program_();
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
            main_menu_();
        else
            end_program_();
    }
}
