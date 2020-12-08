### Ohjelmointitehtävä 5.4: Liitä taulukot (20 pts)

**Nyt harjoittelet muistinkäsittelyfunktioita, ja edelleen tietysti dynaamista
muistinvarausta.**

Toteuta funktio **join_arrays** joka saa parametrikseen kolme kokonaislukutaulukkoa,
sekä kustakin taulukosta sen alkioiden lukumäärän.
Kaikkiaan funktio saa siis kuusi parametria,
jotka on esiteltävä tässä järjestyksessä:

* ensimmäisen taulukon alkioiden lukumäärä (unsigned integer)
* osoitin ensimmäiseen kokonaislukutaulukkoon (alkiot tyyppiä int)
* toisen taulukon alkioiden lukumäärä (unsigned integer)
* osoitin toiseen kokonaislukutaulukkoon (tyyppiä int)
* kolmannen taulukon alkioiden lukumäärä (unsigned integer)
* osoitin kolmanteen kokonaislukutaulukkoon (tyyppiä int)

Funktion tulee liittää nämä kolme taulukkoa yhdeksi taulukoksi,
joka sisältää kaikki kolmessa taulukossa listatut kokonaisluvut yllä
mainitussa järjestyksessä. Uusi yhdistetty taulukko tulee varata dynaamisesti
ja funktion tulee palauttaa osoitin tähän uuteen taulukkoon.
Et saa muuttaa alkuperäisiä taulukoita mitenkään.

Tässä esimerkki *main* - funktiosta, jolla voit testata ohjelmaa:

    int main(void)
    {
        /* testing exercise. Feel free to modify */
        int a1[] = { 1, 2, 3, 4, 5 };
        int a2[] = { 10, 11, 12, 13, 14, 15, 16, 17 };
        int a3[] = { 20, 21, 22 };

        int *joined = join_arrays(5, a1, 8, a2, 3, a3);

        for (int i = 0; i < 5 + 8 + 3; i++) {
            printf("%d  ", joined[i]);
        }
        printf("\n");
        
        free(joined);
    
        return 0;
    }
