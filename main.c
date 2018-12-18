/**
 * Autor: Sebastian Greger
 * Datum: 18.12.2018
 *
 * Beschreibung: Timelib!
 **/

#include <stdio.h>
#include <stdlib.h>

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    int dayOfYear = 0;



    return 0;
}

/**
 * Die Funktion ermittelt für ein übergebenes Jahr des gregorianischen
 * Kalenders, ob es sich um ein Schaltjahr handelt.
 *
 * year: Das zu überprüfende Jahr
 *
 * returns: '1', wenn Schaltjahr
 *          '0', wenn kein Schaltjahr
 *          '-1', wenn das Jahr vor dem Beginn des gregorianischen Kalenders liegt
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

/**
 *
**/
int get_days_for_month(int month, int year)
{
    int daysOfMonth = monthDays[month-1];

    if(isLeapyear(year) == 1 && month == 2)
    {
        daysOfMonth++;
    }

    return daysOfMonth;
}

/**
 *
**/
int exists_date(int day, int month, int year)
{
    if(year < 1582 || year > 2400)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    printf("%i", get_days_for_month(12, 2020));
    //printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
