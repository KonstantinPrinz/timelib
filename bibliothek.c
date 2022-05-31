#include "bibliothek.h"

int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/**
 * Die Funktion überprüft gibt von einem Datum den jeweiligen Wochentag als Integer zurück.
 * Dabei wird mit 0 bei Sonntag begonnen:
 * Sonntag:     0
 * Montag:      1
 * Dienstag:    2
 * Mittwoch:    3
 * Donnerstag:  4
 * Freitag:     5
 * Samstag:     6
 **/
int get_weekday(struct Datum datum)
{
    if(exists_date(datum) == 0)
        return -1;

    return (datum.day += datum.month < 3 ? datum.year-- : datum.year - 2, 23*datum.month/9 + datum.day + 4 + datum.year/4- datum.year/100 + datum.year/400)%7;
}

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
            }
            else
            {
                //kein Schaltjahr
                return 0;
            }
        }
        else
        {
            //Ist ein Schaltjahr
            return 1;
        }
    }
    else
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
int day_of_the_year(struct Datum datum)
{
    if(exists_date(datum) == 0) return -1;

    if(is_leapyear(datum.year))
    {
        daysPerMonth[1] = 29;
    }

    // calculating the day
    int days;
    for(int i = 0; i < datum.month-1; i++)
    {
        if(datum.month == 1)
        {
            break;
        }
        else
        {
            days += daysPerMonth[i];
        }
    }
    days += datum.day;
    daysPerMonth[1] = 28;
    return days;
}

/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 */
int get_days_for_month(struct Datum datum)
{
    if(is_leapyear(datum.year))
    {
        daysPerMonth[1] = 29;
    }

    int days = daysPerMonth[datum.month-1];
    daysPerMonth[1] = 28;
    return days;
}

/**
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 * wie alle Daten nach dem 31.12.2400.
 */
int exists_date(struct Datum datum)
{
    if(datum.year < 1582 || datum.year > 2400) return 0;

    if(is_leapyear(datum.year))
    {
        daysPerMonth[1] = 29;
    }

    if(datum.day <= 0) return 0;

    for(int i = 0; i < 12; i++)
    {
        if((datum.month-1) == i)
            if(datum.day > daysPerMonth[datum.month-1])
                return 0;
    }

    if(datum.month > 12 || datum.month< 1) return 0;
    daysPerMonth[1] = 28;
    return 1;
}
