### Ohjelmointitehtävä 8.5: TCP-otsake (20 pts) {.nonumber .csRunDiv .task_alt}

**Tavoite:** Harjoittele binäärioperaatioita.

Matalan tason protokollat pyrkivät tyypillisesti hyödyntämään
tarvittavan tilan tehokkaasti, jotta protokolla aiheuttaisi
mahdollisimman vähän turhaa tietoliikennettä. Tällä kertaa keskitytään 
TCP-otsakkeeseen.

TCP-otsakkeesta ja sen toiminnasta löytyy tietoa esimerkiksi 
[täältä](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure).
Tarvitset tehtävän toteuttamiseksi tietoa TCP-otsakkeen rakenteesta, mikä löytyy 
kyseiseltä sivulta. 

Wikipedia-artikkelissä olevaa TCP-otsaketta esittävää diagrammia
luetaan seuraavasti: kukin rivi esittää 4 tavun (eli oktetin) alueen
otsakkeesta. Kuvan vasemmassa laidassa ja ylälaidassa lasketaan näitä
oktetteja, jotka yhteenlaskemalla tiedät kuinka monta tavua otsakkeen
alkuun pitäisi lisätä jotta pääset käsittelemään kyseistä kohtaa
otsakkeessa. Esimerkiksi *checksum*-kenttä löytyy 16 ja 17 tavun
kohdalta. Jos tavuista muodostettu taulukko *tcp_hdr* esittää
otsaketta, saat *checksum*-kentän yhdistämällä tavut `tcp_hdr[16]` ja 
`tcp_hdr[17]`.

**Lisävinkkejä:**

  * Kannattaa kiinnittää huomiota C:n 
    **[laskujärjestykseen](http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence)**
    binäärioperaatioiden osalta. Bittisiirto-operaatiot `<<` ja `>>`
    lasketaan esimerkiksi aritmeettisten operaattoreiden (esim. '+' ja
    '-') jälkeen. Käytä siis sulkeita silloin kun niitä tarvitaan.

a) Parsi otsake
------------------

Toteuta seuraavat funktiot, jotka kukin lukevat ja palauttavat yhden
kentän TCP-otsakkeesta. Parsiaksesi kentät sinun tulee poimia
vastaavat bitit TCP-otsakkeesta, esimerkiksi bittisiirtoja ja muita
binäärioperaatioita käyttäen ja palauttaa lukuarvot seuraavassa
kuvatun mukaisesti.

Kaikki funktiot saavat parametrikseen osoittimen otsakkeen alkuun.

  * `getSourcePort` joka palauttaa lähdeportin.
  
  * `getDestinationPort` joka palauttaa kohdeportin.

  * `getAckFlag` joka palauttaa ACK-lipukkeen arvon (0 tai 1). Huom. ACK-lippu on tavussa 13.

  * `getDataOffset` joka palauttaa otsikon pituuden (engl. data offset).
	

b) Kirjoita otsake
----------------

Toteuta seuraavat funktiot, joiden avulla tuotetaan otsake. Parametrina 
saadusta arvosta tulee siis sijoittaa bitit otsakkeen oikeisiin kohtiin.

  * `setSourcePort` joka asettaa lähdeportin kentän
    *port* - parametrin ilmaisemalla tavalla.

  * `setDestinationPort` joka asettaa kohdeportin kentän funktion parametrissa ilmaistulla tavalla.

  * `setAckFlag` joka asettaa ACK-lipukkeen bitin joko päälle tai pois sen perusteella onko parametrian annettu 0 (pois päältä) tai nollasta
    poikkeava arvo (päällä).

  * `setDataOffset`, joka asettaa otsikon pituuden (engl. data offset) funktion parametrissa ilmaistulla tavalla.

Kutakin funktiota kutsuttaessa vain kyseinen osa otsakkeesta saa
muuttua, ja muiden kenttien sisällön tulee säilyä ennallaan.
