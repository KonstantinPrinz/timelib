
struct Datum
{
    int day;
    int month;
    int year;
};

int get_weekday(struct Datum datum);
int is_leapyear(int year);
int day_of_the_year(struct Datum datum);
int get_days_for_month(struct Datum datum);
int exists_date(struct Datum datum);
