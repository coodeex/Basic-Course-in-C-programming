### Ohjelmointitehtävä 5.5: Koodisiistijä (25 pts)

Toteuta funktio `char *delete_comments(char *input)`, joka poistaa
C-kommentit ohjelmasta, joka on tallennettu osoitteeseen
*input*. Huomaa että kyseessä on dynaamisesti varattu puskuri. 
Funktio palauttaa osoittimen kommenteista
siivottuun ohjelmaan. Voit joko varata uuden muistilohkon muokattua
ohjelmaa varten, tai muokata ohjelmaa suoraan *input* - parametrissa
saamassasi muistissa.

Muistutuksena vielä C:n kommenttisäännöt, jotka sinun pitää siivota:

  * Komenttilohkot, jotka alkavat merkeillä `/*` ja päättyvät
    merkkeihin `*/`. Nämä lohkot voivat olla usean rivin
    pituisia. Sinun tulee poistaa vain nämä lohkot: jos esimerkiksi
    lohkon loppua seuraa rivinvaihto, se jää edelleen ohjelmaan.

  * Rivikommentit, jotka alkavat merkeillä `//` ja päättyvät
    rivinvaihtoon. Huom. päättävä rivinvaihto täytyy myös poistaa muokatusta ohjelmasta.

Funktiota kutsuva ohjelma on vastuussa vain siitä osoittimesta, jonka
funktio palauttaa. Yksi tapa toteuttaa funktio on varata kirjoittamista
varten uusi muistialue. Tällöin pitää kuitenkin muistaa lopuksi vapauttaa
alkuperäinen muistivaraus *input* - osoittimessa.

Tässä avuksi testifile.c tiedosto sivun alussa olevassa  zip-tiedostossa. Toki 
voit testata millä tahansa c-kielisellä lähdetiedostolla.
