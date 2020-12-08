### Ohjelmointitehtävä 3.6: Sort (25 pts)

Toteuta funktio `void sort(int *start, int size)` joka järjestää
annetussa taulukossa (*start*) olevat kokonaisluvut nousevaan
suuruusjärjestykseen (pienimmästä suurimpaan). Taulukossa on *size* alkiota.
Voit käyttää
esimerkiksi *valintalajittelua* (selection sort): aloita etsimällä
taulukon pienin alkio, ja vaihda sen paikkaa taulukon ensimmäisen
alkion kanssa. Sitten tarkastelen lopputaulukkoa toisesta alkiosta
eteenpäin, ja jälleen vaihdan lopputaulukon pienimmän alkion taulukon
toisen alkion kanssa. Näin jatkat kolmanteen ja neljänteen alkioon,
kunnes koko taulukko on käyty läpi, jolloin taulukon alkiot ovat
oikeassa järjestyksessä. Testaa funktiota erilaisilla ja erikokoisilla
kokonaislukutaulukoilla.
