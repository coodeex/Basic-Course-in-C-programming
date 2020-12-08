### Ohjelmointitehtävä 5.3: Dynaaminen taulukko (30 pts)

**Tehtävässä harjoittelet dynaamisen muistinvarauksen perusteita, sekä
olemassa olevan taulukon kasvattamista.**

Tässä tehtävässä toteutat kaksi funktiota. Kummankin oikeasta toteutuksesta
tulee osa pisteistä, mutta jotta testiohjelma kääntyy, molemmista funktioista on
löydyttävä ainakin jonkinlainen toteutus. Muista, että nyt myös
valgrind-virheistä sakotetaan.

1) Toteuta funktio `int *create_dyn_array(unsigned int n)` joka varaa taulukon
int - tyyppisille arvoille. Taulukossa tulee olla tilaa *n*:lle alkiolle.
*n* annetaan funktiolle parametrina. Kun taulukko on varattu, sinun tulee lukea
taulukon alkioille arvot käyttäjän syötteestä scanf - funktiota käyttäen.
Kun vaadittu määrä kokonaislukuja on luettu, funktio palauttaa osoittimen
dynaamisesti varattuun taulukkoon.

2) Toteuta funktio `int *add_dyn_array(int *arr, unsigned int num, int newval)`
joka lisää yhden kokonaisluvun aiemmin dynaamisesti varattuun taulukkoon (*arr*). 
Taulukon aiempi koko (alkoiden määrä) annetaan parametrissa *num*, ja uusi lisättävä kokonaisluku
kerrotaan parametrissa *newval*. Varmista että taulukossa on riittävästi
tilaa uuden kokonaisluvun lisäämiseksi, ja testaa että funktio toimii,
kun sitä kutsutaan useita kertoja peräkkäin. Funktio palauttaa osoittimen
dynaamisesti varattuun taulukkoon.
