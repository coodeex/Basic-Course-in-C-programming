**Tässä tehtävässä opit kirjoittamaan funktion, jossa on muutamia parametreja.
Lisäksi joudut kutsumaan eräitä matematiikkakirjastofunktiota, jotka on
esitelty tietyssä otsaketiedostossa.**

Toteuta funktio nimeltään **vectorlength(double x, double y, double z)** joka laskee annetun
kolmiulotteisen vektorin pituuden. Vektorin alkupiste on 0,0,0, minkä 
lisäksi funktio saa kolme parametria, jotka esittävät vektorin alkioita 
eri ulottuvuuksissa. Funktio palauttaa vektorin pituuden. 
Kaikki luvut tulee käsitellä **double**-tyyppisinä liukulukuesityksinä.

Mikäli vektorilaskut ovat ehtineet unohtua, esimerkiksi [Wikipediassa]
kerrotaan laskukaava. Tarvitset siis esimerkiksi neliöjuurilaskua,
joka ei sisälly C-kielen perusoperaattoreihin, vaan sitä varten on
[sqrt] - funktio matematiikkakirjastossa, jota sinun tulee
kutsua. [pow] - funktiolla voi laskea potenssilaskuja. Katso tarkemmat
tiedot funktioista linkitetyiltä manuaalisivuilta. Jotta voit käyttää näitä
funktioita, sinun tulee sisällyttää otsake **math.h** ohjelmaasi, sekä
lisätä gcc-käännöskomennon loppuun **-lm** - optio, joka kertoo että mukaan
linkataan myös matematiikkakirjasto, esimerkiksi:

    gcc -std=c99 -Wall -g -o main source.c -lm

Toteuta funktio tiedostoon ja tee funktion perään myös oma
main-funktiosi, jossa testaat funktiosi toimintaa eri syötteillä. 
Kun funktiosi mielestäsi toimii oikein, palauta se alle tarkistusta varten.

**Huom!** Tarkistin vaatii, että kaikki paluuarvolliset fuktiot palauttavat paluuarvon.

[Wikipediassa]: https://fi.wikipedia.org/wiki/Vektori
[sqrt]: http://linux.die.net/man/3/sqrt
[pow]: http://linux.die.net/man/3/pow
