### Ohjelmointitehtävä 3.4: Arrays (30 pts)

**Tässä tehtävässä jatketaan perusharjoittelua osoittimien ja taulukoiden
kanssa, mutta nyt toteutat asiat omassa ohjelmassasi.**

Tässä tehtävässä sinun on määrä toteuttaa kaksi funktiota seuraavasti.

**1)** Toteuta funktio `int array_sum(int *array, int count)`, joka laskee
taulukon *array* alkioiden summan ja palauttaa sen
paluuarvonaan. Taulukossa olevien numeroiden määrä kerrotaan
parametrissa *count*.

Esimerkiksi seuraavan ohjelman tulisi asettaa *ret* 1110:ksi.

    int valarray[] = { 10, 100, 1000 };
    int ret = array_sum(valarray, 3);
    
**2)** Toteuta funktio `unsigned int array_reader(int *vals, int n)` joka
lukee käyttäjältä kokonaislukuja *vals*-muuttujan osoittamaan
taulukkoon. Taulukon tarvitsema tila on jo valmiiksi varattu, ja
parametri *n* kertoo taulukon maksimikoon. Numerot voi lukea
*scanf*-funktiota käyttäen siten että niiden välissä on rivivaihto tai
väli, tai mikä tahansa ns. whitespace-merkki, joka toimii
oletusarvoisesti scanf-syötteen erottimena.

Mikäli käyttäjä ei syötä numeroa (mikä nähdään scanf-paluuarvosta),
taulukko ja funktion suoritus loppuu. Funktion tulee palauttaa
taulukon lopullinen koko, joka siis voi olla pienempi kuin *n*, mutta
ei koskaan suurempi.

Alla esimerkki siitä kuinka funktiota voi testata:

    int array[10];
    unsigned int n = array_reader(array, 10);
    printf("%d numbers read\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

Esimerkiksi seuraava syöte lukee taulukkoon neljä numeroa, ja lopettaa
sen jälkeen, kun viides arvo on viivamerkki.

5 8 2 7 -

Toteuta siis .c - tiedostoosi edellä mainitut kaksi funktiota, sekä
main-funktio niiden testaamiseksi. Saat kummastakin oikein toimivasta
funktiosta 15 pistettä, mikäli varoituksia ei tule.
