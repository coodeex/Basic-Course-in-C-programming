### Ohjelmointitehtävä 8.4: Bittioperaatiot (30 pts)

Tässä tehtävässä opit tekemään perusoperaatioita binääriluvuilla.
Ohjelmassa käsitellään taulukkoa, joka on useamman tavun mittainen. Tehtävänäsi on
toteuttaa funktioita jotka manipuloivat yksittäisiä bittejä taulukossa siten,
että bitit lasketaan taulukon alusta lähtien. Esimerkiksi bitti 50 on seitsemännen
tavun kolmas bitti.

Tehtävänäsi on implementoida seuraavat funktiot:

**a) Perusoperaatiot**

Seuraavissa parametri *data* viittaa taulukon alkuun ja *i* on manipuloitavan
bitin indeksi, ei siis taulukon kohta tavuina (kts. selitys yllä). Toteuta
seuraavat funktiot jotka manipuloivat yksittäisiä bittejä taulukossa:

* `void op_bit_set(unsigned char* data, int i)` -- joka asettaa annetun bitin päälle

* `void op_bit_unset(unsigned char* data, int i)` -- joka asettaa annetun bitin pois päältä

* `int op_bit_get(const unsigned char* data, int i)` -- joka palauttaa 0, jos
annettu bitti ei ollut päällä, tai 1 jos annettu bitti oli päällä


**b) Tulosta tavu**

Toteuta funktio `void op_print_byte(unsigned char b)`,
joka tulostaa yhden unsigned char:n binääriesityksenä.

**c) Erota osa**

Toteuta funktio
`unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many)`,
joka erottaa maksimissaan 8 bittiä pitkän 
binääriluvun taulukosta ja palauttaa sen. Bitit luetaan annetusta indeksistä oikealle.
*data* ja *i* toimivat kuten edellä, *how_many* kertoo
kuinka monen bitin jono palautetaan (max. 8). Mikäli *how_many* on alle 8, 
palautettavan luvun eniten merkitsevät bitit jätetään nolliksi. Tässä tehtävässä
saattaa kannattaa hyödyntää (a) - kohdassa toteutettuja funktioita.

**Huomioi:**

  * Tässä tehtävässä bitti 0 on eniten merkitsevä bitti (most significant bit).
    Oletetaan myös, että unsigned charin koko on täsmälleen 8 bittiä.
    Esimerkiksi siis bitti 8 on array toisen unsigned char:n vasemmanpuoleisin
    bitti ja bitti 17 on toisiksi korkein bitti kolmannessa unsigned char:ssa.
    Siispä tarkastellessa numeroa 170 (0xAA heksadesimaalimuodossa, 10101010 
    binäärimuodossa), sen merkitsevin bitti, eli bitti 0 on arvoltaan 1.

  * Jos yrität tehdä jonkinnäköistä aputaulukkoa merkeistä tai kokonaisluvuista,
    olet todennäköisesti tekemässä jotain liian vaikeasti.
    
  * Bitti indeksillä 5 taulukossa ei löydy käyttämällä notaatiota array[5].
  
  * Jos annettu binääridata on `1110 0101 1111 0011 0001 1110 0100 1111`, 
    ja `op_bit_get_sequence`-funktiota kutsutaan indeksillä 20, ja how_manyn arvolla 5,
    haluttu vastaus olisi 28, eli 20. indeksistä löytyvän luvun `1110 0100 1111` 5 ensimmäistä
    bittiä eli `1 1100`. Haluttu tavu olisi tällöin `0001 1100` ( ` 0001 1100 ` = 28).
