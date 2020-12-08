### Ohjelmointitehtävä 2.6: ASCII-taulu (20 pts)

**Tässä tehtävässä perehdytään
[ASCII-taulukkoon](https://fi.wikipedia.org/wiki/ASCII),
joka auttaa hahmottamaan miten
kokonaisluvut vastaavat niiden merkkikoodauksia. Samalla tulevat tutuksi erilaiset
printf-muotoilumääreet sekä saadaan lisää harjoitusta silmukoista**

Jos ASCII-taulukko ei ole entuudestaan tuttu, voit katsoa esimerkiksi 
[tämän](https://www.youtube.com/watch?v=0VqcOSC10Yw)
videon.

Toteuta funktio `void ascii_chart(char min, char max)` joka tulostaa
annetun osan ASCII-taulukosta. Funktion tulee käydä läpi luvut
*min*:stä *max*:iin, sekä jokaiselle lukuarvolle tulostaa seuraavasti:

  * kolmen merkkiä leveä kenttä, joka tulostaa kyseisen luvun
    kokonaislukumuodossa. Jos numero on pienempi kuin 100, se tulee tasata
    oikealle.

  * yksi välimerkki, jonka jälkeen neljä merkkiä leveä kenttä johon
    tulostetaan sama lukuarvo heksadesimaalimuodossa. Kukin heksaluku
    vie kaksi merkkiä, ja sen eteen tulee tulostaa merkit '0x'. Mikäli
    heksaluku vie vain yhden merkin, eteen tulee sijoittaa '0' siten
    jokaisessa luvussa on aina kaksi merkkiä.

  * yksi välimerkki, jonka perään kyseistä lukua vastaava
    ASCII-merkki. Tämä vie aina vain yhden merkin verran tilaa. **Jotkut
    merkkiarvot eivät ole tulostettavissa**, eli niille ei ole
    määritelty näkyvää tulostetta. Tällaisten merkkien tilalle tulee
    tulostaa kysymysmerkki ('?'). Voi käyttää kirjastofunktiota `int
    isprint(int c)` ([man-sivu][1]) selvittääksesi onko merkki *c*
    tulostettavissa vai ei. Jos funktio palauttaa 0, merkki ei ole
    tulostettavissa. *isprint* - funktio on määritelty erillisessä
    otsaketiedostossa *ctype.h*

  * Lopuksi tulosta yksi tabulaattorimerkki (`\t`) ennen seuraavaa
    merkkiarvoa, paitsi jos rivillä on jo neljän luvun
    tiedot. Neljännelle luvulle sinun tulee vaihtaa riviä, eli
    tulostaa tabulaattorimerkin sijaan rivinvaihto (`\n`)

[1]: http://linux.die.net/man/3/isprint "isprint manual page"

Sinun tulee siis käydä läpi edellä mainitulla tavalla kaikki lukuarvot
annetulla numerovälillä (sisältäen myös arvon *max*). Esimerkiksi
funktiokutsun *ascii_chart(28,38)* tulisi aiheuttaa seuraavanlainen
tuloste:

28 0x1c ?	 29 0x1d ?	 30 0x1e ?	 31 0x1f ?
32 0x20  	 33 0x21 !	 34 0x22 "	 35 0x23 #
36 0x24 $	 37 0x25 %	 38 0x26 &
