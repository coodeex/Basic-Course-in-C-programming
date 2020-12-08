### Ohjelmointitehtävä 4.5: New String (25 pts)

**Tavoite:** Kuinka merkkijonofunktiot on toteutettu? Tämä harjoitus
  saattaa valottaa asiaa.

*Tehtävä jakautuu neljään osaan. Kunkin ratkaisemisesta saat osan pisteistä.
Maksimipistemäärän saamiseksi sinun tulee ratkaista kaikki kohdat ilman
varoituksia. Kaikki funktiot pitää kuitenkin määritellä, jotta testausohjelma
kääntyy (vaikka niitä ei olisi kokonaan toteutettu).*

Tässä tehtävässä luomme uudenlaisen merkkijonon, joka ei lopukkaan
`\0` - merkkiin, kuten normaalit merkkijonot, vaan loppumerkkinä
käytetäänkin kysymysmerkkiä ('?'). Tästä johtuen joudumme toteuttamaan
perinteiset merkkijonofunktiot uudestaan.

Huomaa, että `*<string.h>*`:ssa määritellyt merkkijonofunktiot **eivät
toimi tässä tehtävässä**, koska `\0` - merkki ei enää toimikaan
merkkijonon lopetusmerkkinä.

### a) Tulosta merkkijono

Toteuta funktio `void qstr_print(const char *s)` joka tulostaa annetun
uudentyyppisen merkkijonon ruudulle. Merkkijono loppuu siis '?' -
merkkiin, jota ei pidä tulostaa. Esimerkiksi seuraavanlainen
merkkijono: 

char *str = "Auto ajoi?kilparataa";

tulostuu näin:

Auto ajoi

### b) Merkkijonon pituus

Toteuta funktio `unsigned int qstr_length(const char *s)` joka palauttaa
merkkijonon *s* merkkien lukumäärän. Merkkijonon päättävää '?' - merkkiä
ei lasketa mukaan.

Esimerkiksi, jos funktio saa kyseisen merkkijonon:

char *str = "Auto ajoi?kilparataa";

palauttaa se:

9

### c) Merkkijonon lisäys

Toteuta funktio `int qstr_cat(char *dst, const char *src)` joka lisää merkkijonon
*src* merkkijonon *dst* perään. Funktio palauttaa tuloksena syntyneen merkkijonon
merkkien lukumäärän. Funktion tulee lisätä *src*-merkkijonoa vain ensimmäiseen
'?' - merkkiin asti, ja lisäyksen jälkeen tuloksena syntyvän merkkijonon
tulee päättyä '?' - merkkiin. Voit käyttää aiemmin
toteuttamaasi *qstr_print* - funktiota testaamaan toimiiko kopiointi
oikein.

Esimerkiksi, jos funktio saa kyseiset merkkijonot:

char dst[50] = "Auto ajoi?";
char *src = " katua pitkin? lujaa";

se palauttaa:

22

ja merkkijonon *dst* pitäisi näyttää tältä:

Auto ajoi katua pitkin

### d) Osamerkkijonon hakeminen

Toteuta funktio `const char *qstr_strstr(const char *str1, const char *str2)`, joka 
etsii merkkijonosta *str1* toista merkkijonoa *str2*. Jos merkkijono *str2* löytyy, 
funktio palauttaa osoittimen merkkijonon *str1* ensimmäisen *str2*:n esiintymän 
ensimmäiseen merkkiin. Mikäli haettavaa merkkijonoa ei löydy, tulee funktion
palauttaa NULL (määritelty `<stddef.h>` - otsakkeessa). Muista, että merkkijonot
etsivät vain '?'-merkkiin asti.

Esimerkiksi, jos funktio saa kyseiset merkkijonot:

char *str1 = "Auto ajoi katua pitkin?";
char *str2 = "katu?";

se palauttaa osoittimen sanan `katua` ensimmäiseen kirjaimeen, josta ensimmäinen
osamerkkijono `katu` alkaa.
