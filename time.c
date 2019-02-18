#include <stdio.h>
#include "time.h"

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 * Returns the current day of the year or -1 if the date doesn't exists.
 **/
int day_of_the_year(struct date date)
{
    struct date tempDate = date;

    if(exists_date(date))
    {
        int dayOfYear = 0;

        for(int i = 1; i < date.month; i++)
        {
            tempDate.month = i;
            dayOfYear += get_days_for_month(tempDate);
        }

        dayOfYear += date.day;

        if(isLeapyear(date) == 1 && date.month > 1)
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
 * Prompts the user for an input of a day, month and year.
 * Returns a date structure containing the inputted values.
**/
struct date input_date()
{
    struct date date;

    do
    {
        printf("Geben Sie einen Tag ein: ");
        scanf("%i", &date.day);

        printf("Geben Sie einen Monat ein: ");
        scanf("%i", &date.month);

        printf("Geben Sie einen Jahr ein: ");
        scanf("%i", &date.year);
    }while(!(exists_date(date)));

    return date;
}

/**
 * Returns 1 if the year of the given date structure is a leapyear and 0 if it isn't.
 * Returns -1 if the year isn't within the range of the gregorian calender.
**/
int isLeapyear(struct date date)
{
    if(date.year >= 1582 && date.year <= 2400)
    {
        if(date.year%4 == 0)
        {
            if(date.year%100 == 0)
            {
                if(date.year%400 == 0)
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
 * Returns the amount of days in the month of the given date structure.
 * Accepts months from 1 - 12 (January to December).
 * Returns -1 if the specified month doesn't exist
**/
int get_days_for_month(struct date date)
{
    if(date.month >= 1 && date.month <= 12 && !(isLeapyear(date) == -1))
    {
        int daysOfMonth = monthDays[date.month-1];

        if(isLeapyear(date) == 1 && date.month == 2)
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
 * Checks if the specified date is within the range of the gregorian calender
 * and whether the day and month value are valid.
 * Returns 1 if the date is valid and 0 if it is not.
**/
int exists_date(struct date date)
{
    if(date.year >= 1582 && date.year <= 2400)
    {
        if(date.day >= 1 && date.day <= get_days_for_month(date))
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
        return 0;
    }
}
