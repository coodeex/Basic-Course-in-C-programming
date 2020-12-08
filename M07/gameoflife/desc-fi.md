### Ohjelmointitehtävä 7.5: Elämän Peli (Game of life) (25 pts)

**Tavoite:** Harjoitella dynaamisesti varattavia kaksiulotteisia
  taulukoita osana pientä peliä.

[Game of Life](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
on perinteinen "peli", jossa lähinnä tietokone pelaa
muuntamalla kaksiulotteista pelikenttää tiettyjen sääntöjen
perusteella. Game of Life:n kaksiulotteinen pelikenttä muodostuu
soluista, jotka voivat olla kahdessa eri tilassa: elossa tai
kuolleita. Pelikenttää päivitetään askel (eli sukupolvi) kerrallaan
siten, että kunkin solun tila voi muuttua riippuen sen naapurisolujen
tilasta. Peli jatkuu näin periaatteessa ikuisesti, kunnes joku
keskeyttää sen toiminnan.

Kunkin solun tilaa säädetään seuraavien sääntöjen perusteella:

  * Jos **elossa** olevalla solulla on **vähemmän kuin kaksi elossa
    olevaa** naapuria, solu **kuolee**.

  * Jos **elossa** olevalla solulla on **kaksi tai kolme elossa
    olevaa** naapuria, soluu säilyy hengissä.

  * Jos **elossa** olevalla solulla on **enemmän kuin kolme elossa
    olevaa** naapuria, solu **kuolee**.

  * Mikäli **kuolleella** solulla on **tasan kolme elossa olevaa**
    naapuria, solu **muuttuu elolliseksi**

Myös kulmittaiset solut lasketaan naapureiksi, eli kullakin solulla
(joka ei ole pelikentän reunassa) on 8 naapuria. Huomioi että
pelikentän reunassa olevat solut pitää käsitellä erikoistapauksina:
et saa yrittää käsitellä pelikentän ulkopuolella olevia alueita.

Pelikentän tilamuutosten tulee tapahtua loogisesti saman aikaisesti,
eli kunkin solun tilan tulee riippua edellisen sukupolven
tilanteesta.

Esimerkiksi seuraavan näköinen pelikenttä (jossa '*' merkitsee elävää
solua) 

..........
.**.***...
.**......*
.*.*.....*
........*.

tulisi seuraavassa sukupolvessa muuttua tämän näköiseksi:

.....*....
.***.*....
*...**....
.*......**
..........

Aiheeseen liittyvä [wikipedia-sivu](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
kertoo aiheesta lisätietoa.

Tässä harjoituksessa sinun tulee toteuttaa seuraavat osat, joita
tarvitaan pelin pyörittämiseen. *main* - funktio
**main.c**:ssä sisältää pelin päärakenteen, josta kutsutaan toteuttamiasi funktioita
sukupolvi kerrallaan kunnes päätät lopettaa pelin.

Harjoituksessa on seuraavat osat:

**a) Luo ja vapauta pelikenttä**

Toteuta funktio *createGameArea*, joka varaa tarvittavan muistin
*GameArea* - tietorakenteelle, johon pelikenttä tallennetaan. Pelikentän
koko määritellään parametreilla *x_size* ja *y_size*. Aluksi kukin
kentän solu tulee asettaa *DEAD* - tilaan, sekä lisäksi sinun tulee
asettaa *x_size* ja *y_size* - kentät tietorakenteessa saamiesi
parametrien mukaisiksi. *cells* on kaksiulotteinen taulukko, johon tallennetaan
jokaisen solun tila.

**HUOM** Testit olettavat, että kentän rivipointterit (y-akseli) on status-pointterin 
ensimmäinen ulottuvuus. Toisin sanoen cells-rakenne on muodossa cells[y][x]

Sinun pitää lisäksi toteuttaa funktio *releaseGameArea*, joka vapauttaa
varaamasi muistin. On tärkeää, että toteutat tämän funktion aikaisessa
vaiheessa, koska tehtävän testit tulevat käyttämään sitä jatkossa
muistin vapauttamiseen. Toisin sanoen Valgrind ei ole tyytyväinen (ja
estää pisteiden saamisen) ennenkuin tämä funktio on toteutettu.

**b) Alusta kenttä**

Toteuta funktio *initGameArea*, joka muuttaa annetun määrän (*n*) soluja
*ALIVE*-tilaan. Voit itse määrittää millä perusteella muutettavat
solut valitaan. Yksi vaihtoehto on käyttää 
*[rand](http://linux.die.net/man/3/rand)* - funktiota, ja
valita solut satunnaisesti. Tärkeintä on, että funktion jälkeen tasan
*n* solua on vaihtanut tilaansa.

**c) Tulosta kenttä**

Toteuta funktio *printGameArea* joka tulostaa kentän sen hetkisen tilan
ruudulle. Kuolleet solut tulee merkata pisteellä ('.'), ja elossa
olevat solut tähdellä ('*'). Solujen välissä ei ole tyhjiä välejä, ja
kukin rivi loppuu rivinvaihtomerkkiin ('\\n'), mukaanlukien viimeinen
rivi. Tulosteen tulisi siis näyttää samanlaiselta, kuin yllä
annetuissa esimerkeissä.

**d) Käsittele sukupolvi**

Toteuta funktio *gameTick* joka siirtää pelikentän tilaa yhden sukupolven
verran eteenpäin noudattaen edellä annettuja sääntöjä. Muista, että
kunkin solun tilan tulee riippua edellisestä sukupolvesta, eli kaikki
solut muuttuvat loogisesti "samaan aikaan" (vaikka ohjelmassa joudut
käsittelemään ne yksi kerrallaan). Voit joutua esimerkiksi
tilapäisesti taltioimaan kaksi kopiota pelikentästä: edellisen
sukupolven ja uuden sukupolven.

(Mikäli varaat uutta muistia tässä funktiossa, muista huolehtia myös
muistin vapautuksesta)

**Vinkki:** Älä käy kaikkia reunatapauksia erikseen läpi ehtolauseilla naapureita laskettaessa.
Käy naapurit läpi toistorakenteilla ja, ennen kyseisen solun arvon tarkastelua,
varmista, että se on pelikentän rajojen sisällä.
