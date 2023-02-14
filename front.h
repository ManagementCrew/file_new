#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h> 
#include <unistd.h> 
#include "color.h"


void gotoab(int x, int y);
void content_1();
void content_2();
void content_3();
void rect_bsh1();
void rect_bsh2();
void rect_bsh3();
void rect_bsh4();
void rect_bsh5();
void rect_bsh6();

void gotoab(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void HEADER()
{
    printf(BBLUE);
    int A=1;
     gotoab(A,0);printf("\n0 0 0     0 0 0");
     gotoab(A,1);printf("\n0   0     0   0");
     gotoab(A,2);printf("\n0   0     0   0");
     gotoab(A,3);printf("\n0   0  0  0   0");
     gotoab(A,4);printf("\n0   0     0   0");
     gotoab(A,5);printf("\n0      0      0");
     gotoab(A,6);printf("\n0   0     0   0");
     gotoab(A,7);printf("\n0 0         0 0");
    sleep(1);
    A=18;
    printf(BYELLOW);
     gotoab(A,1);printf("&  &  &  &  & &");
     gotoab(A,2);printf("&  &  &  &  & &");
     gotoab(A,3);printf("&  &           ");
     gotoab(A,4);printf("&  &  &  &  & &");
     gotoab(A,5);printf("&  &  &  &  & &");
     gotoab(A,6);printf("&  &           ");
     gotoab(A,7);printf("&  &  &  &  & &");
     gotoab(A,8);printf("&  &  &  &  & &");
    sleep(1);
    A=36;
     gotoab(A,1);printf("0  0           ");
     gotoab(A,2);printf("0  0           ");
     gotoab(A,3);printf("0  0           ");
     gotoab(A,4);printf("0  0           ");
     gotoab(A,5);printf("0  0           ");
     gotoab(A,6);printf("0  0           ");
     gotoab(A,7);printf("0  0  0  0  0 0");
     gotoab(A,8);printf("0  0  0  0  0 0");
     sleep(1);
     A=54;
     gotoab(A,1);printf("               ");
     gotoab(A,2);printf("               ");
     gotoab(A,3);printf("               ");
     gotoab(A,4);printf("&  &  &  &  &  ");
     gotoab(A,5);printf("&  &  &  &  &  ");
     gotoab(A,6);printf("               ");
     gotoab(A,7);printf("               ");
     gotoab(A,8);printf("               ");
 sleep(1);
     A=72;
     gotoab(A,1);printf("0  0  0  0  0 0");
     gotoab(A,2);printf("0  0  0  0  0 0");
     gotoab(A,3);printf("0  0           ");
     gotoab(A,4);printf("0  0           ");
     gotoab(A,5);printf("0  0           ");
     gotoab(A,6);printf("0  0           ");
     gotoab(A,7);printf("0  0  0  0  0 0");
     gotoab(A,8);printf("0  0  0  0  0 0");
 sleep(1);
     A=90;
     gotoab(A,1);printf("&  &  &  &  &  &");
     gotoab(A,2);printf("&  &  &  &  &  &");
     gotoab(A,3);printf("&  &        &  &");
     gotoab(A,4);printf("&  &        &  &");
     gotoab(A,5);printf("&  &        &  &");
     gotoab(A,6);printf("&  &        &  &");
     gotoab(A,7);printf("&  &  &  &  &  &");
     gotoab(A,8);printf("&  &  &  &  &  &");
 sleep(1);
      A=108;
     gotoab(A,1);printf("0 0 0        0 0 0");
     gotoab(A,2);printf("0     0     0    0");
     gotoab(A,3);printf("0        0       0");
     gotoab(A,4);printf("0    0       0   0");
     gotoab(A,5);printf("0    0   0   0   0");
     gotoab(A,6);printf("0    0       0   0");
     gotoab(A,7);printf("0    0       0   0");
     gotoab(A,8);printf("0 0 0        0 0 0");
      sleep(1);
    A=128;
     gotoab(A,1);printf("&  &  &  &  & &");
     gotoab(A,2);printf("&  &  &  &  & &");
     gotoab(A,3);printf("&  &           ");
     gotoab(A,4);printf("&  &  &  &  & &");
     gotoab(A,5);printf("&  &  &  &  & &");
     gotoab(A,6);printf("&  &           ");
     gotoab(A,7);printf("&  &  &  &  & &");
     gotoab(A,8);printf("&  &  &  &  & &");
 sleep(1);
    A=1;
    printf(BBLUE);
     gotoab(A,11);printf("0  0  0  0  0 0");
     gotoab(A,12);printf("0  0  0  0  0 0");
     gotoab(A,13);printf("      0  0     ");
     gotoab(A,14);printf("      0  0     ");
     gotoab(A,15);printf("      0  0     ");
     gotoab(A,16);printf("      0  0     ");
     gotoab(A,17);printf("      0  0     ");
     gotoab(A,18);printf("      0  0     ");
      sleep(1);
     A=18;
    printf(BYELLOW);
     gotoab(A,11);printf("&  &  &  &  &  &");
     gotoab(A,12);printf("&  &  &  &  &  &");
     gotoab(A,13);printf("&  &        &  &");
     gotoab(A,14);printf("&  &        &  &");
     gotoab(A,15);printf("&  &        &  &");
     gotoab(A,16);printf("&  &        &  &");
     gotoab(A,17);printf("&  &  &  &  &  &");
     gotoab(A,18);printf("&  &  &  &  &  &");

 sleep(1);
     A=1;
    printf(BBLUE);
     gotoab(A,21);printf("0  0  0  0  0 0");
     gotoab(A,22);printf("0  0  0  0  0 0");
     gotoab(A,23);printf("0  0           ");
     gotoab(A,24);printf("0  0           ");
     gotoab(A,25);printf("0  0           ");
     gotoab(A,26);printf("0  0           ");
     gotoab(A,27);printf("0  0  0  0  0 0");
     gotoab(A,28);printf("0  0  0  0  0 0");
 sleep(1);
     A=18;
    printf(BYELLOW);
     gotoab(A,21);printf("&  &        &  &");
     gotoab(A,22);printf("&  &        &  &");
     gotoab(A,23);printf("&  &        &  &");
     gotoab(A,24);printf("&  &        &  &");
     gotoab(A,25);printf("&  &        &  &");
     gotoab(A,26);printf("&  &        &  &");
     gotoab(A,27);printf("&  &  &  &  &  &");
     gotoab(A,28);printf("&  &  &  &  &  &");
sleep(1);
     A=36;
     gotoab(A,21);printf("0  0  0  0  0 0");
     gotoab(A,22);printf("0  0  0  0  0 0");
     gotoab(A,23);printf("0  0           ");
     gotoab(A,24);printf("0  0  0  0  0 0");
     gotoab(A,25);printf("0  0  0  0  0 0");
     gotoab(A,26);printf("            0 0");
     gotoab(A,27);printf("0  0  0  0  0 0");
     gotoab(A,28);printf("0  0  0  0  0 0");
     sleep(1);
     A=54;
     gotoab(A,21);printf("&  &  &  &  & &");
     gotoab(A,22);printf("&  &  &  &  & &");
     gotoab(A,23);printf("      &  &     ");
     gotoab(A,24);printf("      &  &     ");
     gotoab(A,25);printf("      &  &     ");
     gotoab(A,26);printf("      &  &     ");
     gotoab(A,27);printf("      &  &     ");
     gotoab(A,28);printf("      &  &     ");
     sleep(1);
     A=72;
     gotoab(A,21);printf("0  0  0  0  0  0");
     gotoab(A,22);printf("0  0  0  0  0  0");
     gotoab(A,23);printf("0  0        0  0");
     gotoab(A,24);printf("0  0        0  0");
     gotoab(A,25);printf("0  0        0  0");
     gotoab(A,26);printf("0  0        0  0");
     gotoab(A,27);printf("0  0  0  0  0  0");
     gotoab(A,28);printf("0  0  0  0  0  0");
     sleep(1);
     A=90;
     gotoab(A,21);printf("& & &        & & &");
     gotoab(A,22);printf("&     &     &    &");
     gotoab(A,23);printf("&        &       &");
     gotoab(A,24);printf("&    &       &   &");
     gotoab(A,25);printf("&    &   &   &   &");
     gotoab(A,26);printf("&    &       &   &");
     gotoab(A,27);printf("&    &       &   &");
     gotoab(A,28);printf("& & &        & & &");
          sleep(1);
     A=110;
     gotoab(A,21);printf("0  0  0  0  0 0");
     gotoab(A,22);printf("0  0  0  0  0 0");
     gotoab(A,23);printf("0  0           ");
     gotoab(A,24);printf("0  0  0  0  0 0");
     gotoab(A,25);printf("0  0  0  0  0 0");
     gotoab(A,26);printf("0  0           ");
     gotoab(A,27);printf("0  0  0  0  0 0");
     gotoab(A,28);printf("0  0  0  0  0 0");
     sleep(1);
     A=128;
     gotoab(A,21);printf("&  &  &  &  &  &");
     gotoab(A,22);printf("&  &  &  &  &  &");
     gotoab(A,23);printf("&  &        &  &");
     gotoab(A,24);printf("&  &  &  &  &  &");
     gotoab(A,25);printf("&  &  &  &  &  &");
     gotoab(A,26);printf("&  &  &   &      ");
     gotoab(A,27);printf("&  &     &   &   ");
     gotoab(A,28);printf("&  &        &   &");

     sleep(1);
     A=1;
    printf(BBLUE);
     gotoab(A,31);printf("0 0 0        0 0 0");
     gotoab(A,32);printf("0     0     0    0");
     gotoab(A,33);printf("0        0       0");
     gotoab(A,34);printf("0    0       0   0");
     gotoab(A,35);printf("0    0   0   0   0");
     gotoab(A,36);printf("0    0       0   0");
     gotoab(A,37);printf("0    0       0   0");
     gotoab(A,38);printf("0 0 0        0 0 0");
 sleep(1);
     A=19;
    printf(BYELLOW);
     gotoab(A,31);printf("&  &  &  &  &  &");
     gotoab(A,32);printf("&  &  &  &  &  &");
     gotoab(A,33);printf("&  &        &  &");
     gotoab(A,34);printf("&  &  &  &  &  &");
     gotoab(A,35);printf("&  &  &  &  &  &");
     gotoab(A,36);printf("&  &        &  &");
     gotoab(A,37);printf("&  &        &  &");
     gotoab(A,38);printf("&  &        &  &");
sleep(1);
     A=36;
     gotoab(A,31);printf("0  0       0  0");
     gotoab(A,32);printf("0    0     0  0");
     gotoab(A,33);printf("0  0   0   0  0");
     gotoab(A,34);printf("0  0 0   0 0  0");
     gotoab(A,35);printf("0  0   0   0  0");
     gotoab(A,36);printf("0  0    0     0");
     gotoab(A,37);printf("0  0     0    0");
     gotoab(A,38);printf("0  0       0  0");
     sleep(1);
     A=52;
     gotoab(A,31);printf("&  &  &  &  &  &");
     gotoab(A,32);printf("&  &  &  &  &  &");
     gotoab(A,33);printf("&  &        &  &");
     gotoab(A,34);printf("&  &  &  &  &  &");
     gotoab(A,35);printf("&  &  &  &  &  &");
     gotoab(A,36);printf("&  &        &  &");
     gotoab(A,37);printf("&  &        &  &");
     gotoab(A,38);printf("&  &        &  &");
     sleep(1);
     A=70;
     gotoab(A,31);printf("0  0  0  0  0  0  0");
     gotoab(A,32);printf("0  0  0  0  0  0  0");
     gotoab(A,33);printf("0  0           0  0");
     gotoab(A,34);printf("0  0               ");
     gotoab(A,35);printf("0  0     0  0  0  0");
     gotoab(A,36);printf("0  0     0  0  0  0");
     gotoab(A,37);printf("0  0  0  0  0  0  0");
     gotoab(A,38);printf("0  0  0  0  0  0  0");
     sleep(1);
     A=90;
     gotoab(A,31);printf("&  &  &  &  & &");
     gotoab(A,32);printf("&  &  &  &  & &");
     gotoab(A,33);printf("&  &           ");
     gotoab(A,34);printf("&  &  &  &  & &");
     gotoab(A,35);printf("&  &  &  &  & &");
     gotoab(A,36);printf("&  &           ");
     gotoab(A,37);printf("&  &  &  &  & &");
     gotoab(A,38);printf("&  &  &  &  & &");
     sleep(1);
     A=107;
     gotoab(A,31);printf("0 0 0        0 0 0");
     gotoab(A,32);printf("0     0     0    0");
     gotoab(A,33);printf("0        0       0");
     gotoab(A,34);printf("0    0       0   0");
     gotoab(A,35);printf("0    0   0   0   0");
     gotoab(A,36);printf("0    0       0   0");
     gotoab(A,37);printf("0    0       0   0");
     gotoab(A,38);printf("0 0 0        0 0 0");
          sleep(1);
     A=125;
     gotoab(A,31);printf("&  &  &  & ");
     gotoab(A,32);printf("&  &  &  & ");
     gotoab(A,33);printf("&  &       ");
     gotoab(A,34);printf("&  &  &  & ");
     gotoab(A,35);printf("&  &  &  & ");
     gotoab(A,36);printf("&  &       ");
     gotoab(A,37);printf("&  &  &  & ");
     gotoab(A,38);printf("&  &  &  & ");
sleep(1);
     A=136;
     gotoab(A,31);printf("0  0       0  0");
     gotoab(A,32);printf("0    0     0  0");
     gotoab(A,33);printf("0  0   0   0  0");
     gotoab(A,34);printf("0  0 0   0 0  0");
     gotoab(A,35);printf("0  0   0   0  0");
     gotoab(A,36);printf("0  0    0     0");
     gotoab(A,37);printf("0  0     0    0");
     gotoab(A,38);printf("0  0       0  0");
     sleep(1);
     A=151;
     gotoab(A,31);printf("&  &  &  &  & &");
     gotoab(A,32);printf("&  &  &  &  & &");
     gotoab(A,33);printf("      &  &     ");
     gotoab(A,34);printf("      &  &     ");
     gotoab(A,35);printf("      &  &     ");
     gotoab(A,36);printf("      &  &     ");
     gotoab(A,37);printf("      &  &     ");
     gotoab(A,38);printf("      &  &     ");

     sleep(1);
     A=1;
    printf(BBLUE);
     gotoab(A,41);printf("0  0  0  0  0  0");
     gotoab(A,42);printf("0  0  0  0  0  0");
     gotoab(A,43);printf("0  0            ");
     gotoab(A,44);printf("0  0  0  0  0  0");
     gotoab(A,45);printf("0  0  0  0  0  0");
     gotoab(A,46);printf("            0  0");
     gotoab(A,47);printf("0  0  0  0  0  0");
     gotoab(A,48);printf("0  0  0  0  0  0");
 sleep(1);
     A=18;
    printf(BYELLOW);

     gotoab(A,41);printf("&  &        &  &");
     gotoab(A,42);printf(" &  &      &  & ");
     gotoab(A,43);printf("  &   &   &  &  ");
     gotoab(A,44);printf("     &  &  &    ");
     gotoab(A,45);printf("      &  &      ");
     gotoab(A,46);printf("      &  &      ");
     gotoab(A,47);printf("      &  &      ");
     gotoab(A,48);printf("      &  &      ");
sleep(1);
     A=36;
     gotoab(A,41);printf("0  0  0  0  0  0");
     gotoab(A,42);printf("0  0  0  0  0  0");
     gotoab(A,43);printf("0  0            ");
     gotoab(A,44);printf("0  0  0  0  0  0");
     gotoab(A,45);printf("0  0  0  0  0  0");
     gotoab(A,46);printf("            0  0");
     gotoab(A,47);printf("0  0  0  0  0  0");
     gotoab(A,48);printf("0  0  0  0  0  0");
     sleep(1);
     A=54;
     gotoab(A,41);printf("&  &  &  &  & &");
     gotoab(A,42);printf("&  &  &  &  & &");
     gotoab(A,43);printf("      &  &     ");
     gotoab(A,44);printf("      &  &     ");
     gotoab(A,45);printf("      &  &     ");
     gotoab(A,46);printf("      &  &     ");
     gotoab(A,47);printf("      &  &     ");
     gotoab(A,48);printf("      &  &     ");
     sleep(1);
     A=71;
     gotoab(A,41);printf("0  0  0  0  0");
     gotoab(A,42);printf("0  0  0  0  0");
     gotoab(A,43);printf("0  0         ");
     gotoab(A,44);printf("0  0  0  0  0");
     gotoab(A,45);printf("0  0  0  0  0");
     gotoab(A,46);printf("0  0         ");
     gotoab(A,47);printf("0  0  0  0  0");
     gotoab(A,48);printf("0  0  0  0  0");
     sleep(1);
     A=88;
     gotoab(A,41);printf("& & &        & & &");
     gotoab(A,42);printf("&     &     &    &");
     gotoab(A,43);printf("&        &       &");
     gotoab(A,44);printf("&    &       &   &");
     gotoab(A,45);printf("&    &   &   &   &");
     gotoab(A,46);printf("&    &       &   &");
     gotoab(A,47);printf("&    &       &   &");
     gotoab(A,48);printf("& & &        & & &");
     sleep(1);
}

void content_1()
{
    system("cls");
    int A;
    sleep(1);
    A = 30;
    printf(BBLUE);
    gotoab(A, 1);
    printf("0  0  0  0  0 0");
    gotoab(A, 2);
    printf("0  0  0  0  0 0");
    gotoab(A, 3);
    printf("0  0           ");
    gotoab(A, 4);
    printf("0  0           ");
    gotoab(A, 5);
    printf("0  0           ");
    gotoab(A, 6);
    printf("0  0           ");
    gotoab(A, 7);
    printf("0  0  0  0  0 0");
    gotoab(A, 8);
    printf("0  0  0  0  0 0");
    sleep(1);

    A = 55;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 66;
    gotoab(A, 1);
    printf("0 0 0        0 0 0");
    gotoab(A, 2);
    printf("0     0     0    0");
    gotoab(A, 3);
    printf("0        0       0");
    gotoab(A, 4);
    printf("0    0       0   0");
    gotoab(A, 5);
    printf("0    0   0   0   0");
    gotoab(A, 6);
    printf("0    0       0   0");
    gotoab(A, 7);
    printf("0    0       0   0");
    gotoab(A, 8);
    printf("0 0 0        0 0 0");
    sleep(1);

    A = 94;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 108;
    gotoab(A, 1);
    printf("0  0  0  0  0  0");
    gotoab(A, 2);
    printf("0  0  0  0  0  0");
    gotoab(A, 3);
    printf("0  0            ");
    gotoab(A, 4);
    printf("0  0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0  0");
    gotoab(A, 6);
    printf("            0  0");
    gotoab(A, 7);
    printf("0  0  0  0  0  0");
    gotoab(A, 8);
    printf("0  0  0  0  0  0");
    sleep(1);
    A = 134;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    int i;
    gotoab(0, 9);
    for (i = 0; i <= 167; i++)
    {
        printf(RESET "\xCD");
    }
}

void content_2()
{
    system("cls");
    int A;
    sleep(1);
    A = 30;
    printf(BBLUE);
    gotoab(A, 1);
    printf("0  0  0  0 0");
    gotoab(A, 2);
    printf("0  0  0  0  0 0");
    gotoab(A, 3);
    printf("0  0        0 0");
    gotoab(A, 4);
    printf("0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0");
    gotoab(A, 6);
    printf("0  0        0 0");
    gotoab(A, 7);
    printf("0  0  0  0  0 0");
    gotoab(A, 8);
    printf("0  0  0  0 0");
    sleep(1);

    A = 55;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 66;
    gotoab(A, 1);
    printf("0 0 0        0 0 0");
    gotoab(A, 2);
    printf("0     0     0    0");
    gotoab(A, 3);
    printf("0        0       0");
    gotoab(A, 4);
    printf("0    0       0   0");
    gotoab(A, 5);
    printf("0    0   0   0   0");
    gotoab(A, 6);
    printf("0    0       0   0");
    gotoab(A, 7);
    printf("0    0       0   0");
    gotoab(A, 8);
    printf("0 0 0        0 0 0");
    sleep(1);

    A = 94;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 108;
    gotoab(A, 1);
    printf("0  0  0  0  0  0");
    gotoab(A, 2);
    printf("0  0  0  0  0  0");
    gotoab(A, 3);
    printf("0  0            ");
    gotoab(A, 4);
    printf("0  0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0  0");
    gotoab(A, 6);
    printf("            0  0");
    gotoab(A, 7);
    printf("0  0  0  0  0  0");
    gotoab(A, 8);
    printf("0  0  0  0  0  0");
    sleep(1);
    A = 134;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    int i;
    gotoab(0, 9);
    for (i = 0; i <= 167; i++)
    {
        printf(RESET "\xCD");
    }
}

void content_3()
{
    system("cls");
    int A;
    sleep(1);
    A = 30;
    printf(BBLUE);
    gotoab(A, 1);
    printf("0  0        0  0");
    gotoab(A, 2);
    printf("0  0        0  0");
    gotoab(A, 3);
    printf("0  0        0  0");
    gotoab(A, 4);
    printf("0  0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0  0");
    gotoab(A, 6);
    printf("0  0        0  0");
    gotoab(A, 7);
    printf("0  0        0  0");
    gotoab(A, 8);
    printf("0  0        0  0");
    sleep(1);

    A = 55;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 66;
    gotoab(A, 1);
    printf("0 0 0        0 0 0");
    gotoab(A, 2);
    printf("0     0     0    0");
    gotoab(A, 3);
    printf("0        0       0");
    gotoab(A, 4);
    printf("0    0       0   0");
    gotoab(A, 5);
    printf("0    0   0   0   0");
    gotoab(A, 6);
    printf("0    0       0   0");
    gotoab(A, 7);
    printf("0    0       0   0");
    gotoab(A, 8);
    printf("0 0 0        0 0 0");
    sleep(1);

    A = 94;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 108;
    gotoab(A, 1);
    printf("0  0  0  0  0  0");
    gotoab(A, 2);
    printf("0  0  0  0  0  0");
    gotoab(A, 3);
    printf("0  0            ");
    gotoab(A, 4);
    printf("0  0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0  0");
    gotoab(A, 6);
    printf("            0  0");
    gotoab(A, 7);
    printf("0  0  0  0  0  0");
    gotoab(A, 8);
    printf("0  0  0  0  0  0");
    sleep(1);
    A = 134;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    int i;
    gotoab(0, 9);
    for (i = 0; i <= 167; i++)
    {
        printf(RESET "\xCD");
    }
}

void content_4()
{
    system("cls");
    int A;
    sleep(1);
    A = 30;
    printf(BBLUE);
    gotoab(A, 1);
        printf("0  0  0  0  0  0");
    gotoab(A, 2);
        printf("0  0  0  0  0  0");
    gotoab(A, 3);
        printf("0  0            ");
    gotoab(A, 4);
        printf("0  0  0  0  0  0");
    gotoab(A, 5);
        printf("0  0  0  0  0  0");
    gotoab(A, 6);
        printf("            0  0");
    gotoab(A, 7);
        printf("0  0  0  0  0  0");
    gotoab(A, 8);
        printf("0  0  0  0  0  0");
    sleep(1);

    A = 55;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 66;
    gotoab(A, 1);
    printf("0 0 0        0 0 0");
    gotoab(A, 2);
    printf("0     0     0    0");
    gotoab(A, 3);
    printf("0        0       0");
    gotoab(A, 4);
    printf("0    0       0   0");
    gotoab(A, 5);
    printf("0    0   0   0   0");
    gotoab(A, 6);
    printf("0    0       0   0");
    gotoab(A, 7);
    printf("0    0       0   0");
    gotoab(A, 8);
    printf("0 0 0        0 0 0");
    sleep(1);

    A = 94;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    A = 108;
    gotoab(A, 1);
    printf("0  0  0  0  0  0");
    gotoab(A, 2);
    printf("0  0  0  0  0  0");
    gotoab(A, 3);
    printf("0  0            ");
    gotoab(A, 4);
    printf("0  0  0  0  0  0");
    gotoab(A, 5);
    printf("0  0  0  0  0  0");
    gotoab(A, 6);
    printf("            0  0");
    gotoab(A, 7);
    printf("0  0  0  0  0  0");
    gotoab(A, 8);
    printf("0  0  0  0  0  0");
    sleep(1);
    A = 134;
    gotoab(A, 7);
    printf("0  0");
    gotoab(A, 8);
    printf("0  0");
    sleep(1);

    int i;
    gotoab(0, 9);
    for (i = 0; i <= 167; i++)
    {
        printf(RESET "\xCD");
    }
}

void rect_bsh1()
{
    int i;
    int a = 12;
    gotoab(5, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(5, a);
    printf("%c", 213);
    gotoab(45, a);
    printf("%c", 184);

    a = 20;
    gotoab(5, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(5, a);
    printf("%c", 212);
    gotoab(45, a);
    printf("%c", 190);
}

void rect_bsh2()
{
    int i;
    int a = 12;
    gotoab(60, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(60, a);
    printf("%c", 213);
    gotoab(100, a);
    printf("%c", 184);

    a = 20;
    // top
    gotoab(60, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(60, a);
    printf("%c", 212);
    gotoab(100, a);
    printf("%c", 190);
}

void rect_bsh3()
{
    int i;
    int a = 12;
    gotoab(110, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(110, a);
    printf("%c", 213);
    gotoab(150, a);
    printf("%c", 184);

    a = 20;
    // top
    gotoab(110, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(110, a);
    printf("%c", 212);
    gotoab(150, a);
    printf("%c", 190);
}

void rect_bsh4()
{
    int i;
    int a = 25;
    gotoab(5, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(5, a);
    printf("%c", 213);
    gotoab(45, a);
    printf("%c", 184);

    a = 33;
    gotoab(5, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(5, a);
    printf("%c", 212);
    gotoab(45, a);
    printf("%c", 190);
}

void rect_bsh5()
{
    int i;
    int a = 25;
    gotoab(60, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(60, a);
    printf("%c", 213);
    gotoab(100, a);
    printf("%c", 184);

    a = 33;
    // top
    gotoab(60, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(60, a);
    printf("%c", 212);
    gotoab(100, a);
    printf("%c", 190);
}

void rect_bsh6()
{
    int i;
    int a = 25;
    gotoab(110, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(110, a);
    printf("%c", 213);
    gotoab(150, a);
    printf("%c", 184);

    a = 33;
    // top
    gotoab(110, a);
    for (i = 1; i <= 40; i++)
    {
        printf("%c", 205);
    }
    gotoab(110, a);
    printf("%c", 212);
    gotoab(150, a);
    printf("%c", 190);
}
