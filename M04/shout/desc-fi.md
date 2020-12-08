### Ohjelmointitehtävä 4.4: EI TARVITSE HUUTAA!!! (20 pts)

Toteuta funktio, jonka rajapinta on `char *my_toupper(char *dest, const
char *src)`. Funktion parametri *src* osoittaa merkkijonoon, jota
sinun tulee muokata alla kuvatulla tavalla. Muutettu merkkijono
kirjoitetaan osoitteeseen *dest*. Funktion tulee lisäksi palauttaa
osoitin muutettuun merkkijonoon (eli siihen osoitteeseen, johon *dest*
kutsuessa on osoittanut).

Merkkijonoa tulee muuttaa seuraavilla tavoilla:

    * kaikki kirjainmerkit on muutettava isoiksi kirjaimiksi. Tähän voit
        käyttää avuksi **[toupper](http://en.cppreference.com/w/c/string/byte/toupper)** -
        funktiota joka muuttaa yhden
        kirjainmerkin isoksi. *toupper* - funktio on määritely *ctype.h* -
        nimisessä otsakkeessa, eli sinun tulee tällöin lisätä ohjelman
        alkuun `#include <ctype.h>`.

    * Mikäli alkuperäisessä merkkijonossa on kysymysmerkki ('?'), se
        tulee muuttaa huutomerkiksi ('!').

    * Mikäli alkuperäisessä merkkijonossa on piste ('.'), se tulee
        korvata kolmella huutomerkillä.

Alkuperäistä merkkijonoa ei siis muuteta, vaan tulos kirjoitetaan
*dest* - muuttujan osoittamaan paikkaan.

Esimerkiksi seuraava main-funktio:

#include <stdio.h>  // for printf
#include <string.h>  // for memset
#include <ctype.h>  // for toupper

int main(void)
{
    char dest[200];

    /* The following helps detecting string errors, e.g. missing final nil */
    memset(dest, '#', 199);
    dest[199] = 0;

    printf("%s",
        my_toupper(dest,
            "Would you like to have a sausage? It will be two euros. Here you are.\n"));

    printf("%s",
        my_toupper(dest,
            "Madam, where are you going? The health care center is over there.\n"));

    return 0;
}

Tulostaa:

WOULD YOU LIKE TO HAVE A SAUSAGE! IT WILL BE TWO EUROS!!! HERE YOU ARE!!!
MADAM, WHERE ARE YOU GOING! THE HEALTH CARE CENTER IS OVER THERE!!!

Huomaa, että *toupper* - funktio ei välttämättä osaa muuntaa Ä ja Ö -
merkkejä oikein. Sinun ei tarvitse välittää tästä.
