/**
 *  Author: Konstantin Prinz
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"

int main()
{
    struct Datum datum;
    datum.day = 0;
    datum.month = 0;
    datum.year = 0;

    // Eingaben:
    // Jahr
    printf("Eingabe des Jahres: ");
    scanf("%i", &datum.year);
    fflush(stdin);

    // Monat
    printf("Eingabe des Monats: ");
    scanf("%i", &datum.month);
    fflush(stdin);

    // Tag
    printf("Eingabe des Tages: ");
    scanf("%i", &datum.day);
    fflush(stdin);

    printf("Wochentag: %i\n", get_weekday(datum));
    printf("Tag des Jahres: %i\n", day_of_the_year(datum));
    printf("Schaltjahr?: %i\n", is_leapyear(datum.year));
    printf("Tage des Monats: %i\n", get_days_for_month(datum));
    return 0;
}
