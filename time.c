#include <stdio.h>
#include "time.h"

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int day_of_the_year(struct date date)
{
    struct date tempDate = date;

    if(exists_date(date))
    {
        int dayOfYear = 0;

        //Create the sum of days of the previous months
        for(int i = 1; i < date.month; i++)
        {
            tempDate.month = i;
            dayOfYear += get_days_for_month(tempDate);
        }

        //Add the days of the current month
        dayOfYear += date.day;

        /**
         * If the current month is later than february, add another day,
         * if the current year is a leapyear
         **/
        if(is_leapyear(date) == 1 && date.month > 2)
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

struct date input_date()
{
    struct date date;

    //Repeat input of date while the inputted date is invalid
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

int is_leapyear(struct date date)
{
    //Check for gregorian calender
    if(is_date_within_gregorian_calender(date))
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

int get_days_for_month(struct date date)
{
    /**
     * Check whether the current year is within the gregorian calender
     * and the month is a valid month
     **/
    if(date.month >= 1 && date.month <= 12 && !(is_leapyear(date) == -1))
    {
        int daysOfMonth = monthDays[date.month-1];

        if(is_leapyear(date) == 1 && date.month == 2)
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

int exists_date(struct date date)
{
    //Check for gregorian calender
    if(is_date_within_gregorian_calender(date))
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

int is_date_within_gregorian_calender(struct date date)
{
    if(date.year >= GREGORIAN_STARTDATE && date.year <= GREGORIAN_ENDDATE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
