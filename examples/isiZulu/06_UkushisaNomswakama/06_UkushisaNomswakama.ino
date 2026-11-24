// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <isiZulu.h>

DHT inzwa(2, DHT11);

ize qala() {
    Isiriyeli.ukuqala(9600);
    inzwa.ukuqala();
}

ize phindaphinda() {
    linda(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    idesimali umswakama = inzwa.funda_umswakama();
    idesimali ukushisa = inzwa.funda_izinga_lokushisa();
    uma (akuyona_inombolo(umswakama) || akuyona_inombolo(ukushisa)) {
        Isiriyeli.bonisa_umugqa("Iphutha: angikwazi ukufunda i-DHT11");
        buyisa;
    }
    Isiriyeli.bonisa("Ukushisa: ");
    Isiriyeli.bonisa(ukushisa);
    Isiriyeli.bonisa(" C   Umswakama: ");
    Isiriyeli.bonisa(umswakama);
    Isiriyeli.bonisa_umugqa(" %");
}
