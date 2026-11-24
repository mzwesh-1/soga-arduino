// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <isiXhosa.h>

DHT inzwa(2, DHT11);

ize qalisa() {
    Isiriyali.ukuqala(9600);
    inzwa.ukuqala();
}

ize phinda_phinda() {
    linda(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    idesimali umswakama = inzwa.funda_ubumanzi();
    idesimali ukushisa = inzwa.funda_iqondo_lobushushu();
    ukuba (akulonani(umswakama) || akulonani(ukushisa)) {
        Isiriyali.bonisa_umgca("Iphutha: angikwazi ukufunda i-DHT11");
        buyisa;
    }
    Isiriyali.bonisa("Ukushisa: ");
    Isiriyali.bonisa(ukushisa);
    Isiriyali.bonisa(" C   Umswakama: ");
    Isiriyali.bonisa(umswakama);
    Isiriyali.bonisa_umgca(" %");
}
