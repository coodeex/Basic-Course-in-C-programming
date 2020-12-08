### Ohjelmointitehtävä 9.1: Hex file (20 pts)

Toteuta funktio `int file_to_hex(const char *filename)` joka lukee annettua
tiedostoa (jonka nimi on *filename* - parametrissa) ja tulostaa
tiedoston sisällön heksadumppina: kukin
tiedostossa oleva tavu tulostetaan kahden merkin pituisessa
heksadesimaalimuodossa siten että alle 0x10:n oleviin lukuihin
lisätään 0 eteen. Kunkin luvun perässä on yksi välimerkki, ja
kullakin rivillä tulee olla enintään 16 merkkiä, jonka jälkeen
siirrytään seuraavalle riville. **Myös jokaisen rivin viimeistä merkkiä seuraa
välimerkki.** Tässä esimerkki tulosteesta:

<pre>
0e 54 65 65 6d 75 20 54 65 65 6b 6b 61 72 69 30 
30 30 30 30 41 00 00 14 45 4c 45 43 2d 41 31 31 
30 30 00 00 00 00 00 00 00 </pre>

Funktion tulee palauttaa
paluuarvonaan luettujen tavujen määrä, tai -1 mikäli tiedoston
avaamisessa sattui virhe.
