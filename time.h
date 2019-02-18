#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};

int day_of_the_year(struct date date);
struct date input_date();
int isLeapyear(struct date date);
int get_days_for_month(struct date date);
int exists_date(struct date date);

#endif // TIME_H_INCLUDED
