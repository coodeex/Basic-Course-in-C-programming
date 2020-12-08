### Ohjelmointitehtävä 9.2: File basics (25 pts)

**Tavoite:** Harjoitellaan tiedoston lukemista

Ensimmäisessä kohdassa avataan tiedosto, ja tulostetaan se standaritulostevirtaan.
Toisessa tehtävässä toteutat yksinkertaisen diff-työkalun, joka kertoo 
ensimmäisen rivin, joka on erilainen kahdessa eri tiedostossa.

**a) Tulosta tiedosto**

Toteuta funktio `int print_file_and_count(const char *filename)`, joka tulostaa tiedoston
sisällön standaritulostevirtaan. Funktio palauttaa tulostettujen merkkien määrän 
ja jos tiedoston avaaminen ei onnistu, palautetaan -1.

**b) Eroavaisuus**

Toteuta funktio `char *difference(const char* file1, const char* file2)`
joka vertailee kahta tiedostoa. Funktion tulisi palauttaa ensimmäiset rivit, 
jotka eroavat toisistaan yhdistettynä allaolevan esimerkin mukaisesti.
Huom! Rivinvaihto rivin lopussa on osa riviä.
Jos tiedostot ovat samat, palautetaan NULL. Funktion suoritus loppuu heti,
kun jompikumpi tiedostoista loppuu, ja silloin palautetaan myös NULL.
Voit varata tilan paluumerkkijonolle dynaamisesti, tarkistin vapauttaa muistin.

Tiedosto 1:

    #include <stdio.h>

    int main(void) {
        printf("Hello world!\n");

        return 0;
    }

Tiedosto 2:

    #include <stdio.h>

    int main(void) {
        printf("Hello!\n");

        return 0;
    }

Funktio palauttaa:
<pre>
        printf("Hello world!\n");
----
        printf("Hello!\n");
</pre>
