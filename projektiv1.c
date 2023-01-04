/***************************************************************************
 *   Copyright (C) 2022 by Ak   *
 *   e2101587@edu.vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
        String manipulator

 2.  DESCRIPTION
        Manipulates string using commands from user

 3.  VERSIONS
       Original:
        15.3.2022 / Ak

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG

/* Global constants */
#define MAX_USER_INPUT 100

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void display_menu(void);
char ask_command(void);
void read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
    char string[MAX_USER_INPUT] = "Hello World!";

    display_menu();

    while (1)
    {
        char cmd = ask_command();

        switch (cmd)
        {
        case 'A':
            printf("String has %d vowels\n", count_vowels(string));
            break;

        case 'B':
            printf("String has %d consonants\n", count_consonants(string));
            break;

        case 'C':
            to_upper(string);
            printf("%s\n", string);
            break;

        case 'D':
            to_lower(string);
            printf("%s\n", string);
            break;

        case 'E':
            print_string(string);
            break;

        case 'F':
            read_string(string);
            break;

        case 'G':
            read_file(string);
            break;

        case 'H':
            write_file(string);
            break;

        case 'M':
            display_menu();
            break;

        case 'X':
            exit(0);
        }
    }

} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void display_menu()
 DESCRIPTION: Displays menu
	Input: none
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void display_menu()
{
    printf("A) Count the number of vowels in  the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to upper case\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n");
    printf("\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program\n");
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:char ask_command(void)
 DESCRIPTION: Asks command from user
	Input: none
	Output: s[0]
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

char ask_command(void)
{
    char s[MAX_USER_INPUT];
    printf("\nGive command: ");
    fgets(s, MAX_USER_INPUT, stdin);
    s[0] = toupper(s[0]);

    if ((s[0] >= 'A' && s[0] <= 'H') || (s[0] == 'M') || (s[0] == 'X'))
    {
        return s[0];
    }
    else
        (printf("Invalid input"));
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:void print_string(char s[])
 DESCRIPTION: Prints current string
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void print_string(char s[])
{
    printf("%s\n", s);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_vowels(char s[0])
 DESCRIPTION: Counts vowels in string
	Input: s[]
	Output: vowels
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

int count_vowels(char s[0])
{
    int length = strlen(s);
    int vowels = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        char up = toupper(s[i]);
        if ((up == 'A' ||   up == 'E' || up == 'I' || up == 'O' || up == 'U' || up == 'Y'))
        {
            vowels++;
        }
    }
    return vowels;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_consonants(char s[0])
 DESCRIPTION: Counts consonants in string
	Input: s[]
	Output: consonants
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

int count_consonants(char s[0])
{
    int length = strlen(s);
    int consonants = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        char up = toupper(s[i]);
        if (up >= 65 && up <= 90)
        {

            if (up != 'A' && up != 'E' && up != 'I' && up != 'O' && up != 'U' && up != 'Y')
            {
                consonants++;
            }
        }
    }
    return consonants;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void to_lower(char s[])
 DESCRIPTION: Turns string to lower case
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void to_lower(char s[])
{
    int i;
    int length = strlen(s);
    for (i = 0; i < length; i++)
    {
        s[i] = tolower(s[i]);
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void to_upper(char s[])
 DESCRIPTION: Turns string to upper case
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void to_upper(char s[])
{
    int i;
    int length = strlen(s);
    for (i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]);
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void read_string(char s[])
 DESCRIPTION: Reads new string from user
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void read_string(char s[])
{
    char string[MAX_USER_INPUT];
    printf("\nGive string: ");
    fgets(s, MAX_USER_INPUT, stdin);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void read_file(char s[])
 DESCRIPTION: Read string from file
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void read_file(char s[])
{

    FILE *file_pointer = fopen("filename.txt", "r");
    fgets(s, 50, file_pointer);
    fclose(file_pointer);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  void write_file(char s[])
 DESCRIPTION: Stores new string into txt file
	Input: s[]
	Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void write_file(char s[])
{
    FILE *file_pointer = fopen("filename.txt", "w");
    fprintf(file_pointer, "%s\n", s);
    fclose(file_pointer);
}