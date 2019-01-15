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
    printf("(71)  Day of year:    %i\n", day_of_the_year(12, 3, 2018));
    printf("(1)   Is leapyear:    %i\n", isLeapyear(2020));
    printf("(0)   Date exists:    %i\n", exists_date(1, 1, 1444));
    printf("(31)  Days of Month:  %i\n", get_days_for_month(12, 2020));
    printf("(365) Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
