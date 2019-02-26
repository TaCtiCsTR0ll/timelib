/**
 * Autor: Sebastian Greger
 * Datum: 18.12.2018
 *
 * Beschreibung: Initial repository for a time library written in C.
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    struct date date;

    date = input_date();

    printf("Day of year:    %i\n", day_of_the_year(date));
    printf("Is leapyear:    %i\n", is_leapyear(date));
    printf("Date exists:    %i\n", exists_date(date));
    printf("Days of Month:  %i\n", get_days_for_month(date));
    printf("Tag des Jahres: %i\n", day_of_the_year(date));

    return 0;
}
