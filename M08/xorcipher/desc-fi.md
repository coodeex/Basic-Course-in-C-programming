### Ohjelmointitehtävä 8.6: XOR-salaus (20 pts)

**Tavoite:** perehtyä bittioperaatioihin ja pidempään (32-bittiseen) bittiavaruuteen.

Toteuta funktio nimeltään **confidentiality_xor** joka saa parametreikseen 32 bittiä 
pitkän salausavaimen `key`, salattavan/purettavan datan *data* sekä datan pituuden 
`len` eli kuinka monta 32-bittistä lohkoa `data` sisältää. Funktion on määrä toteuttaa 
yksinkertainen salaus; jokainen databufferin (32-bittinen) osa tulee salata käyttäen 
XOR-bittioperaattoria ja annettua salausavainta. Funktiossa ei tarvitse varata muistia 
eli käsittele suoraan annettua dataa. **Huom!** muista, että tässä tehtävässä dataa 
käsitellään `uint32_t` -muodossa (32-bittinen `unsigned int`). Lisätietoa funktion 
halutusta toiminnasta [Wikipediassa](https://en.wikipedia.org/wiki/XOR_cipher).

Toteuta myös funktio **confidentiality_xor_shift**, jossa muokataan salattavan datan 
lisäksi salausavainta jokaisen 32-bittisen lohkon salauksen jälkeen. Funktion idea on 
siis sama kuin **confidentiality_xor** -funktion, mutta yhden lohkon salauksen jälkeen 
salausavaimen bitit \"liikkuvat\". Kaikkia salausavaimen bittejä siirretään yhden bitin 
verran vasemmalle ja salausavaimen vasemman päädyn ensimmäinen eli eniten merkitsevä 
bitti siirtyy oikeaan päätyyn eli vähiten merkitsevän bitin paikalle. Näin muokattua 
salausavainta käytetään siis datan seuraavan lohkon salaamiseen, jonka jälkeen muokataan 
taas salausavainta samalla tavalla jne.
