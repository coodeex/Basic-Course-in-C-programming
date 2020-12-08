### Ohjelmointitehtävä 9.4: Shop (25 pts)

Tässä tehtävässä sinun tulee toteuttaa kaupan kirjanpito kahdella eri tavalla. 
Kaupan tuotteet on esitetty tietorakenne *Product* muodossa. Tästä tietorakenteesta 
löytyy staattisesti varattu tuotteen nimi, liukulukuna sen hinta sekä kokonaislukuna 
varastotilanne. Kirjanpito on ohjelmassa toteutettu tällaisen *Product* -tietotyyppitaulukon 
avulla. **Taulukon viimeisen alkion tunnistaa siitä, että sen nimen ensimmäinen merkki
on lopetusmerkki** (\\0). Sinun tulee toteuttaa 4 funktiota:

**(a)** funktio *output_binary* joka tuottaa sille parametrina annetusta tuotelistasta 
*shop* tiedoston, johon on tallennettu tämän listan sisältö binäärimuodossa. Tiedoston 
nimi, johon data tulee kirjoittaa, saadaan funktion parametrista *filename*. Funktion 
paluuarvo kirjoituksen onnistuessa on 0, muuten 1.


**(b)** funktio *read_binary*, joka lukee binäärimuodossa (kohdassa a) kirjoitetusta 
tiedostosta *Product* -rakenteiset alkiot, ja palauttaa pointterin tähän listaan. 
**HUOM** Funktion tulee itse varata muisti tälle listalle, ja listaa tulee täyttää 
niin, että tiedostossa ensimmäinen alkio tulee listan ensimmäiseen indeksiin, toinen 
toiseen jne. Muista myös merkitä listan viimeinen alkio asiaankuuluvasti. 
Jos funktio epäonnistuu datan lukemisessa, palauttaa se *NULL*-pointterin. 
Funktion ei tarvitse huolehtia palautettavaan osoittimeen varatun muistin 
vapautuksesta.

**(c)** funktio *output_plaintext* joka tuottaa sille parametrina annetusta tuotelistasta 
*shop* tiedoston, johon on tallennettu tämän listan sisältö tekstimuodossa. Toisin 
sanoen ihmisen luettavassa muodossa. Jokainen listan alkio tulee kirjoittaa tiedostoon 
formaatissa
    
    jugurtti 1.200000 23
    mysli 4.300000 12
tietotyypin eri kentät erottaa siis välilyönti. Tämän vuoksi tuotteen nimessä 
ei saa olla välilyöntiä. Eri tuotteet erotetaan rivinvaihdolla. Tähän tekstitiedostoon 
listan viimeistä alkiota, jonka nimi oli nollamerkki, ei saa merkata ollenkaan. 
Jos funktio onnistuu datan kirjoittamisessa, palauttaa se paluuarvonaan 0, 
epäonnistuessaan 1.


**(d)** funktio *read_plaintext* joka lukee tekstimuodossa (kohdassa c) kirjoitetusta 
tiedostosta *Product* -rakenteiset alkiot, ja palauttaa pointterin tämän listan alkuun. 
Tässäkin osatehtävässä funktion tulee itse varata muisti tälle listalle, ja myös 
tässä tehtävässä listan viimeisen alkion merkiksi tulee nimen ensimmäinen merkki 
merkata nollamerkiksi. Funktion ei tarvitse huolehtia palautettavaan osoittimeen 
varatun muistin vapautuksesta.. Jos funktio epäonnistuu datan lukemisessa, palauttaa se 
*NULL*-pointterin.

**Vinkkejä ja muistutuksia:**

* Kannattaa ehkä lähteä liikkeelle tekstimuodossa käsiteltävistä kohdista (c ja 
d), koska niitä on helpompi debugata.
* Kun luet tekstitiedostosta, kannattaa käyttää apuna 
[sscanf](http://www.cplusplus.com/reference/cstdio/sscanf/)-funktiota.
* Binääritiedostojen yhteydessä tulee käyttää fread ja fwrite -funktioita. Kirjoita/Lue yksi *Product* yhdellä fwrite/fread-komennolla. 
* Kirjoitettuihin tiedostoihin **ei saa** sisällyttää viimeistä "nolla-alkiota", 
vaan vastaavan lukufunktion tulee lisätä se listan loppuun.
* Tekstitiedoston käsittelyssä **ei saa** käyttää tarkennettuja muotoilumääreitä, 
eli liukuluku tulee lukea `%f`, ei esimerkiksi `%0.1f`

Kannattaa luoda omia testitiedostoja toteuttamiesi funktioiden
testaamiseksi. Toteuta funktiot tiedostoon *shop.c* sen pohjalta,
mitä määrittelyt tiedostossa *aaltoshop.h* sisältävät.