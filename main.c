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
    int jahr = 0;
    int monat = 0;
    int tag = 0;

    // Eingaben:
    // Jahr
    printf("Eingabe des Jahres: ");
    scanf("%i", &jahr);
    fflush(stdin);

    // Monat
    printf("Eingabe des Monats: ");
    scanf("%i", &monat);
    fflush(stdin);

    // Tag
    printf("Eingabe des Tages: ");
    scanf("%i", &tag);
    fflush(stdin);

    printf("Wochentag: %i\n", get_weekday(tag, monat, jahr));
    return 0;
}
