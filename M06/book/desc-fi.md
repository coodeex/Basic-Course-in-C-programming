### Ohjelmointitehtävä 6.3: Book (25 pts)

**Tavoite:** Harjoittele dynaamisesti varattujen ja kokoaan muuttavien
  taulukoiden käyttöä tietorakenteista koostetuista alkioista.

Tässä tehtävässä toteutat yksinkertaisen tietokannan kirjojen
tallentamiseen. Tietokannan jokainen tietue noudattaa `struct book`
rakennetta, ja tietokanta muodostuu dynaamisesti varatusta taulukosta,
jossa siis on useita `struct book` - instansseja peräkkäin. Aina kun
uusi alkio lisätään taulukkoon, pitää varmistua että taulukolle on
varattu riittävästi muistia uuden alkion tallentamiseen.

`struct book` - määrittely ja sen kenttien kuvaukset löytyvät
 tiedostosta **book.h**.
 Kannattaa perehtyä tietorakenteen määrittelyyn
 ja selvittää itselleen mitkä kentät saavat tarvitsemansa tilan osana
 tietorakennetta, ja mille kentille tarvittava tila pitää varata
 erikseen. Esimerkiksi kentät *author* ja *title* ovat merkkijonoja, joille pitää
 dynaamisesti varata tarvittava tila erikseen.

Harjoituksessa on kaksi kohtaa, jotka pisteytetään erikseen.
Kannattaa toteuttaa tehtäväkohdat annetussa järjestyksessä,
koska myöhemmät tehtäväkohdat saattavat riippua aiemmin toteutetuista
funktioista. Kannattaa myös testata ohjelmaasi jokaisen tehtäväkohdan
välissä, ja mikäli se näyttää toimivan, lähettää pisteytystä varten
palvelimelle. Vaikka koko tehtävä ei olisikaan valmis, yksittäisistä
tehtäväkohdista voi silti saada pisteitä.

(a) Alusta kirjatietue
------------------

Toteuta funktio '**init_book**' joka alustaa annetun *book* -
rakenteen osoittimen *p_book* osoittamassa paikassa saamiensa parametrien
(*p_id, p_name,* jne...) pohjalta. Sinun ei tarvitse varata
muistia tässä tehtäväkohdassa, vaan voit olettaa että *p_book* - osoitin
viittaa muistialueeseen jossa on riittävästi tilaa varattuna. Sinun
tulee kuitenkin varata muistia niille rakenteen kentille, joiden
vaatima tila ei sisälly *book* - rakenteeseen. Kannattaa esimerkiksi
kiinnittää huomiota merkkijonoihin.

Funktio palauttaa arvon 1, jos alustus onnistui, tai 0 jos se
epäonnistui jostain syystä. Funktio epäonnistuu esimerkiksi silloin,
jos sille annetaan virheellinen id, jossa on enemmän
kuin 9 merkkiä. Voit olettaa että mikä tahansa 9 merkkiä pitkä (tai
lyhyempi) merkkijono on hyväksyttävä id.

(b) Lisää uusi tietue
-----------------

Toteuta funktio '**add_to_collection**' joka lisää uuden *book* -
tietorakenteen dynaamisesti varatun taulukon loppuun, ja tarvittaessa
varaa taulukolle lisää tilaa. Osoitin taulukon alkuun tulee
funktioparametrissa *collection*, ja taulukon nykyinen pituus parametrissa
*size*. Lisättävä tieto annetaan parametrissa *new_book*. On syytä
huomioida että *new_book*:n sisältö tulee kopioida taulukkoon oikealle
paikalle, ja jälleen kannattaa kiinnittää huomiota merkkijonojen
käsittelyyn.

Funktio palauttaa osoittimen taulukkoon lisäyksen jälkeen. Tämähän
saattaa olla eri osoite kuin se, joka *collection* - parametrissa annettiin
sisään.
