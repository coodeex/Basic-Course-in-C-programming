### Ohjelmontitehtävä 4.1: Count Alpha (20 pts)

**Tavoite:** Ensituntuman hankkiminen merkkijonoihin.

Kirjoita funktio `int count_isalpha(const char *str)` joka laskee
aakkoskirjainten määrän annetussa merkkijonossa (*str*). Voit käyttää
hyväksesi funktiota **int
[isalpha](http://www.cplusplus.com/reference/cctype/isalpha/)(int character)**, joka
on määritelty *`<ctype.h>`* -otsakkeessa. Funktio kertoo onko annettu
merkki kirjainmerkki välillä A-Z (palauttaa nollasta poikkeavan
arvon), vai ei (palauttaa 0:n). Toteuttamasti funktion tulee siis
palauttaa kirjainmerkkien lukumäärä annetussa merkkijonossa.
