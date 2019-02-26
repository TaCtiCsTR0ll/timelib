/**
 * Autor: Sebastian Greger
 * Datum: 18.12.2018
 *
 * Beschreibung: Initial repository for a time library written in C.
 **/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#define GREGORIAN_STARTDATE 1582
#define GREGORIAN_ENDDATE 2400

/**
 * Structure containing date values.
 **/
struct date
{
    int day;
    int month;
    int year;
};

/**
 * Returns the current day of the year or -1 if the date doesn't exists.
 **/
int day_of_the_year(struct date date);

/**
 * Prompts the user for an input of a day, month and year.
 * Returns a date structure containing the inputted values.
 **/
struct date input_date();

/**
 * Returns 1 if the year of the given date structure is a leapyear and 0 if it isn't.
 * Returns -1 if the year isn't within the range of the gregorian calender.
 **/
int is_leapyear(struct date date);

/**
 * Returns the amount of days in the month of the given date structure.
 * Accepts months from 1 - 12 (January to December).
 * Returns -1 if the specified month doesn't exist
 **/
int get_days_for_month(struct date date);

/**
 * Checks if the specified date is within the range of the gregorian calender
 * and whether the day and month value are valid.
 * Returns 1 if the date is valid and 0 if it is not.
 **/
int exists_date(struct date date);


/**
 * Checks whether the specified date is within the range of the gregorian calender.
 **/
int is_date_within_gregorian_calender(struct date date);

#endif // TIME_H_INCLUDED
