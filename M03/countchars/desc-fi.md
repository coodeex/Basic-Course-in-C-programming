### Ohjelmointitehtävä 3.5: Count chars (20 pts)

**Tässä tehtävässä käsitellään taulukkoa, joka koostuu merkeistä, eli
char - tyyppisistä alkioista. Taulukon loppu merkitään alkiolla,
jonka arvo on 0.**

Tehtävässä toteutat kaksi funktiota, joista kumpikin tuottaa osan tehtävän
pisteistä.

**(a):** Toteuta funktio, jonka määritelmä on `unsigned int
  arraylen(const char *array)`. Funktio saa siis parametrikseen
  taulukon *array*, jonka pituutta et kutsuvaiheessa tiedä, mutta
  tiedät, että se päättyy alkioon 0. Funktion tulee palauttaa taulukon
  sisältämien alkioiden lukumäärä. 0 - alkiota ei sisällytetä laskuun.

**(b):** Toteuta funktio, jonka määritelmä on `void countchars(const
  char *array, unsigned int *counts)`. Funktio saa parametrikseen
  taulukon *array*, jonka rakenne kuvattiin edellä. Toinen parametri
  *counts* viittaa 256-alkioiseen taulukkoon, johon tulee laskea
  kunkin *array* - taulukossa esiintyvän merkin lukumäärä. Muista että
  char-tyyppi on 8-bittinen, joten *counts* - taulu voi sisältää
  kaikki mahdolliset merkkiarvot. Esimerkiksi
  jos *array* on `{ 'a','b','r','a','c','a','d','a','b','r','a',0 }`,
  niin `counts['a']` saa arvokseen 5, ja `counts['b']` saa
  arvokseen 2. Huomioi että esimerkiksi merkkivakio 'a' on sekin vain
  tapa esittää kokonaisluku (jonka desimaalimuoto olisi ASCII-taulukon
  perusteella 97). Voit olettaa että *counts* - taulukko on kutsujan
  puolesta alustettu nolla-arvoilla.
  
Muista ottaa huomioon myös tapaus, jossa parametrina annettu taulukko on tyhjä.

Voit käyttää esimerkiksi seuraavaa ohjelmaa testataksesi
funktiota. Lisää funktiosi alla olevien funktioiden edelle.

    void printcounts(int min, int max, const unsigned int *counts) {
        for (int i = min; i <= max; i++) {
	        printf("%c: %u  ---  ", i, counts[i]);
	        if ((i - min + 1) % 6 == 0)
	            printf("\n");
        } 
    }

    void printarray(const char *array) {
        printf("{ ");
        while (*array) {
	        printf("'%c',", *array);
	        array++;
        }
        printf("0 }");
    }

    int main()
    {
         unsigned int counts[256] = { 0 };

         char sample[] = { 'a','b','r','a','c','a','d','a','b','r','a',0 };

         printf("%s, length: %u\n", sample, arraylen(sample));
         countchars(sample, counts);
         printcounts('a', 'z', counts);

        return 0;
    }
