/**
 *  Author: Konstantin Prinz
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>
int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/**
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 * ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 **/
int is_leapyear(int year)
{
    if(year < 1582)
        return -1;

    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                //Ist ein Schaltjahr
                return 1;
            } else
            {
                 //kein Schaltjahr
                return 0;
            }
        } else
        {
            //Ist ein Schaltjahr
            return 1;
        }
    } else
    {
        //kein Schaltjahr
        return 0;
    }
}

/**
 * Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 * Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 **/
int day_of_the_year(int day, int month, int year)
{
    if(exists_date(day, month, year) == 0) return -1;

    if(is_leapyear(year))
    {
        daysPerMonth[1] = 29;
    }

    // calculating the day
    int days;
    for(int i = 0; i < month-1; i++)
    {
        if(month == 1)
        {
            break;
        }
        else
        {
            days += daysPerMonth[i];
        }
    }
    days += day;
    daysPerMonth[1] = 28;
    return days;
}

/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 */
int get_days_for_month(int month, int year)
{
    if(is_leapyear(year))
    {
        daysPerMonth[1] = 29;
    }

    int days = daysPerMonth[month-1];
    daysPerMonth[1] = 28;
    return days;
}

/**
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 * wie alle Daten nach dem 31.12.2400.
 */
int exists_date(int day, int month, int year)
{
    if(year < 1582 || year > 2400) return 0;

    if(is_leapyear(year))
    {
        daysPerMonth[1] = 29;
    }

    if(day <= 0) return 0;

    for(int i = 0; i < month-1; i++)
    {
        switch(month)
        {
        case 1:
            if(day > daysPerMonth[0]) return 0;
            break;
        case 2:
            if(day > daysPerMonth[1]) return 0;
            break;
        case 3:
            if(day > daysPerMonth[2]) return 0;
            break;
        case 4:
            if(day > daysPerMonth[3]) return 0;
            break;
        case 5:
            if(day > daysPerMonth[4]) return 0;
            break;
        case 6:
            if(day > daysPerMonth[5]) return 0;
            break;
        case 7:
            if(day > daysPerMonth[6]) return 0;
            break;
        case 8:
            if(day > daysPerMonth[7]) return 0;
            break;
        case 9:
            if(day > daysPerMonth[8]) return 0;
            break;
        case 10:
            if(day > daysPerMonth[9]) return 0;
            break;
        case 11:
            if(day > daysPerMonth[10]) return 0;
            break;
        case 12:
            if(day > daysPerMonth[11]) return 0;
            break;
        }
    }

    if(month > 12 || month < 1) return 0;
    daysPerMonth[1] = 28;
    return 1;
}

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

    printf("Tag des Jahres: %i\n", day_of_the_year(tag, monat, jahr));
    return 0;
}
