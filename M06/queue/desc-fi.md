### Ohjelmointitehtävä 6.5: Harjoitusjono (25 pts)

Tässä tehtävässä toteutat linkitetyn listan avulla
jonotusjärjestelmän, joka tallentaa listaan jonottajien nimiä (eli
merkkijonoja), joiden pituutta ei ole rajoitettu. Linkitetyn listan
alkiot tallennetaan seuraavanlaisiin tietorakenteisiin:

    struct studentqueue {
        char *name;  // Name of student (dynamically allocated)
        struct studentqueue *next;  // pointer to next student
	  };

Kuten edellä mainitaan, opiskelijoiden nimet voivat olla
mielivaltaisen mittaisia, ja nimi tulee tallentaa dynaamiseen
muistiin. Käsittelyn helpoittamiseksi listan ensimmäinen alkio on
tyhjä, ja se tulee sivuuttaa. Ensimmäisessä alkiossa kentässä *name*
tulee aina olla NULL-osoitin. Vastaavasti listan viimeisessä alkiossa
next-osoitin on NULL. Kun lista on tyhjä, ensimmäisessä
alkiossa molemmat kentät ovat siis NULL-osoittimia. Alla kuva, joka
esittää listaa jossa on kaksi alkiota.

<img src="/staticfiles/ELEC-A7100/tasks/M6-stringqueue/M06-stringqueue.svg" width="60%">

Tehtävässä tulee toteuttaa kaksi funktiota, joista kummastakin tulee
osa kokonaispisteistä:

**(a):** Funktio `int enqueue(struct studentqueue *q, const char
*name)` joka lisää jonon viimeiseksi annetun nimen *name*. Osoitin
*q* viittaa listan alkuun (jossa siis ensimmäisenä on
NULL-alkio). Funktion tulee siis tehdä kaksi muistinvarausta,
opiskelijaa esittävää tietorakennetta koskien, sekä nimeä varten.
  Funktio palauttaa kokonaisluvun 1, jos lisäys onnistui, ja
luvun 0, jos se epäonnistui (esimerkiksi muistinvarauksen osalta).

**(b):** Funktio `int dequeue(struct studentqueue *q, char *buffer,
unsigned int size)` joka poistaa jonosta ensimmäisen alkion, siis
sen joka seuraa alun NULL-alkoita. Ennen alkion poistamista sen
sisältämä nimi tulee kopioida osoitteeseen *buffer*. Tässä
osoitteessa on tilaa *size* tavua, eli voit kopioida enintään
*size-1* merkkiä. Samalla tulee vapauttaa ensimmäisen alkion
vapauttama muisti.
Funktio palauttaa luvun 1, jos listalta
poistettiin alkio, ja kyseinen nimi on kirjoitettu osoitteeseen
*buffer*. Funktio palauttaa 0, jos listalta ei poistettu alkiota,
esimerkiksi siksi että se oli tyhjä.

Toteutuksessa ja erityisesti testaamisessa kannattaa kiinnittää
huomiota erityistapauksiin, kuten tyhjän listan tapaus.
