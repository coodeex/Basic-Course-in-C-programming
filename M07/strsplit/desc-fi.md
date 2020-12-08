### Ohjelmointitehtävä 7.4: Split String

Tehtävässä pilkotaan merkkijonoja toisen merkkijonon perusteella, eli
esim. `"Merkkijono joka pilkotaan"`, joka pilkotaan `" "` mukaan, tuottaa
taulukon merkkijonon palasista: `{"Merkkijono","joka","pilkotaan",NULL}`.
Taulukot loppuvat aina NULL-osoittimeen.

Tehtävässä on kaksi osaa:

a) Toteuta funktio `void print_split_string(char** split_string)`, joka
tulostaa pilkotun merkkijonon, jokainen osa omalle rivilleen.
Esimerkiksi kutsuttaessa funktiota pilkotulle merkkijonolle 
`["Merkkijono","joka","pilkotaan",NULL]`, tulostus on seuraava:

Merkkijono
joka
pilkotaan

b) Toteuta funktiot 
    - `char** split_string(const char* str, const char* split)`
    
        Funktio pilkkoo merkkijonon
        aiemmin esitetyllä tavalla ja palauttaa osat dynaamisesti varatussa taulukossa.
        Parametrit ovat:
        - `const char* str`; merkkijono, joka pilkotaan
        - `const char* split`; merkkijono, jonka perusteella `str` pilkotaan,
        
        esimerkiksi `"One. .more. .test. .for. .string. .splitting."` ja `". ."`, jolloin
        tulokseksi saadaan taulukko, joka sisältää palat:
        `["One","more","test","for","string","splitting",NULL]`
    
        Myös osien muisti täytyy varata dynaamisesti ja teksti kopioida taulukkoon.
        Funktio `strstr` voi olla hyödyllinen tehtävässä.

    - `free_split_string(char** split_string)`
        
        Funktio taas vapauttaa pilkotun merkkijonon muistin.
