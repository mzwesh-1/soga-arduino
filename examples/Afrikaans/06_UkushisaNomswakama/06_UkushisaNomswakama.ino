// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Afrikaans.h>

DHT inzwa(2, DHT11);

leeg opstel() {
    Seriaal.begin(9600);
    inzwa.begin();
}

leeg lus() {
    wag(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    dryfgetal umswakama = inzwa.lees_vogtigheid();
    dryfgetal ukushisa = inzwa.lees_temperatuur();
    as (nie_n_getal(umswakama) || nie_n_getal(ukushisa)) {
        Seriaal.drukreel("Iphutha: angikwazi ukufunda i-DHT11");
        terug;
    }
    Seriaal.druk("Ukushisa: ");
    Seriaal.druk(ukushisa);
    Seriaal.druk(" C   Umswakama: ");
    Seriaal.druk(umswakama);
    Seriaal.drukreel(" %");
}
