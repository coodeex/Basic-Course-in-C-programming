### Ohjelmointitehtävä 9.3: Statistics (25 pts)

Toteuta seuraavat funktiot tekstitiedostojen analysoimiseen:

**(a) Rivilaskuri**

Toteuta funktio `int line_count(const char *filename)` joka laskee
rivien lukumäärän annetussa tiedostossa, ja palauttaa lukumäärän
paluuarvonaan. Jos tiedoston avaamisessa tai lukemisessa tapahtuu
virhe, funktion tulee palauttaa -1. Jos tiedosto on tyhjä, siinä ei
ole yhtään riviä. Rivinvaihto on osa sitä edeltävää riviä. Jos 
tiedoston viimeisellä rivillä on sisältöä, mutta rivi ei pääty 
rivinvaihtomerkkiin, se tulee laskea omaksi rivikseen.

**(b) Sanalaskuri**

Toteuta funktio `int word_count(const char *filename)` joka laskee
tiedostossa esiintyvien sanojen määrän. Määrittelemme tässä
harjoituksessa sanan sellaiseksi, jossa on vähintään yksi
kirjainmerkki (**[isalpha](http://www.cplusplus.com/reference/cctype/isalpha/)**
- paluuarvo on tosi). Kaksi sanaa erotetaan toisistaan jollain
välimerkillä ("whitespace",
**[isspace](http://www.cplusplus.com/reference/cctype/isspace/?kw=isspace)** - 
funktion paluuarvo on tosi). Mikäli tiedoston avaamisessa
tai lukemisessa tapahtuu virhe, tulee palauttaa -1. (Kannattaa
huomioida, että shell-komento 'wc -w' määrittelee sanan eritavalla,
joten sitä ei voi käyttää tämän funktion testaamiseen).
