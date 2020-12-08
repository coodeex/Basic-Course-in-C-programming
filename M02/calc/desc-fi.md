### Ohjelmointitehtävä 2.3: Calculator (40 pts)

**Tämän tehtävän myötä opit käyttämään ehtorakenteita ja erilaisia syötteitä
osana omaa C-ohjelmaasi.** Tehtävässä toteutetaan kaksi erillistä funktiota,
jotka molemmat tarkistetaan ja pisteytetään erikseen. Molemmat funktiot
toteutetaan *source.c* - tiedostoon.

**simple_multiply**: Toteuta funktio *simple_multiply*, joka kysyy käyttäjältä kaksi
kokonaislukua ja laskee niiden tulon. Lopuksi funktio tulostaa tulon
seuraavassa muodossa:

`1 * 2 = 2`

Tulosteen lopussa tulee olla rivinlopetus ('`\n`'). Seuravassa
esimerkki käyttäjän syötteestä (ensimmäinen rivi) ja sitä seuraavasta
ohjelman tulosteesta (toinen rivi):

4 5
4 * 5 = 20
  
**simple_math**: Toteuta funktio *simple_math*, joka kysyy kolmiosaisen syötteen
käyttäjältä: numeron, operaattorin, ja numeron. Operaattorin tulee
olla yksi seuraavista merkeistä: '+', '-', '*' tai '/'. Jos jotain
muuta merkkiä yritetään käyttää operaattorina, funktion tulee tulostaa
merkkijono `ERR`. Numerot ovat **liukulukuja** (float).

Mikäli käyttäjän syöte ei noudata oikeanlaista
numero-operaattori-numero - rakennetta, funktion tulee niinikään
tulostaa `ERR`. Kun hyväksytty syöte on annettu, funktion tulee
tulostaa annetun laskutoimituksen tulos **yhden desimaalin
tarkkuudella**.

Seuraavassa esimerkki ohjelman mahdollisesista syötteestä ja tulosteesta:

8 - 2  (käyttäjä)
6.0  (vastaus)

5 * 5  (käyttäjä)
25.0  (vastaus)

8.3 / 5.1  (käyttäjä)
1.6  (vastaus)

-3.456 - 2.31  (käyttäjä)
-5.8  (vastaus)

Kuten aiemmin, toteuta funktioiden perään main-funktio, joka käynnistää
ohjelman, ja jossa testaat funktioitasi erilaisilla syötteillä.

**Vinkkejä:**

  * Koska *scanf* ohittaa kaikki tyhjät merkit
    muotoiluohjeiden välissä, ohjelma saa hyväksyä syötteet, joissa
    kaksi kokonaislukua ovat eri riveillä, tai ne on erotettu useilla
    välilyönneillä.

  * Kiinnitä huomiota merkkivakioiden käyttöön, ja siihen
    kuinka yksittäisiä merkkejä käytetään esimerkiksi *scanf* - funktion
    yhteydessä.
