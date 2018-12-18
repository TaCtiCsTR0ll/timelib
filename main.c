/**
 * Autor: Sebastian Greger
 * Datum: 18.12.2018
 *
 * Beschreibung: Timelib!
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    return 0;
}

/**
Die Funktion ermittelt für ein übergebenes Jahr des gregorianischen
Kalenders, ob es sich um ein Schaltjahr handelt.

year: Das zu überprüfende Jahr

returns: '1', wenn Schaltjahr
         '0', wenn kein Schaltjahr
         '-1', wenn das Jahr vor dem Beginn des gregorianischen Kalenders liegt
**/
int isLeapyear(int year)
{
    if(year >= 1582)
    {
        if(year%4 == 0)
        {
            if(year%100 == 0)
            {
                if(year%400 == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
