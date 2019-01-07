/**
 * Autor: Sebastian Greger
 * Datum: 18.12.2018
 *
 * Beschreibung: Initial repository for a time library written in C.
 **/

#include <stdio.h>
#include <stdlib.h>

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
    printf("(71)  Day of year:    %i\n", day_of_the_year(12, 3, 2018));
    printf("(1)   Is leapyear:    %i\n", isLeapyear(2020));
    printf("(0)   Date exists:    %i\n", exists_date(1, 1, 1444));
    printf("(31)  Days of Month:  %i\n", get_days_for_month(12, 2020));
    printf("(365) Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}

/**
 * Returns the current day of the year or -1 if the date doesn't exists.
 **/
int day_of_the_year(int day, int month, int year)
{
    if(exists_date(day, month, year))
    {
        int dayOfYear = 0;

        for(int i = 1; i < month; i++)
        {
            dayOfYear += get_days_for_month(i, year);
        }

        dayOfYear += day;

        if(isLeapyear(year) == 1 && month > 1)
        {
            dayOfYear++;
        }

        return dayOfYear;
    }
    else
    {
        return -1;
    }
}

/**
 * Returns 1 if the specified year is a leapyear and 0 if it isn't.
 * If the year isn't withing the range of the gregorian calender -1 is returned.
**/
int isLeapyear(int year)
{
    if(year >= 1582 && year <= 2400)
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
 * Returns the amount of days of the month in the specified year
 * or -1 if the specified month doesn't exist.
**/
int get_days_for_month(int month, int year)
{
    if(month >= 1 && month <= 12 && !(isLeapyear(year) == -1))
    {
        int daysOfMonth = monthDays[month-1];

        if(isLeapyear(year) == 1 && month == 2)
        {
            daysOfMonth++;
        }

        return daysOfMonth;
    }
    else
    {
        return -1;
    }
}



/**
 * Checks if the specified date is between the dates '01.01.1582' and '31.12.2400'.
 * Returns 1 if true and 0 if false.
**/
int exists_date(int day, int month, int year)
{
    if(year >= 1582 && year <= 2400)
    {
        if(day >= 1 && day <= get_days_for_month(month, year))
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
