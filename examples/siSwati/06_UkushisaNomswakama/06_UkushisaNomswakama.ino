// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <siSwati.h>

DHT inzwa(2, DHT11);

lite cala() {
    Siriyali.kucala(9600);
    inzwa.kucala();
}

lite phindza_phindza() {
    lindza(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    ideshimali umswakama = inzwa.fundza_umswakama();
    ideshimali ukushisa = inzwa.fundza_lizinga_lekushisa();
    nangabe (akusiyo_inombolo(umswakama) || akusiyo_inombolo(ukushisa)) {
        Siriyali.khombisa_umugca("Iphutha: angikwazi ukufunda i-DHT11");
        buyisa;
    }
    Siriyali.khombisa("Ukushisa: ");
    Siriyali.khombisa(ukushisa);
    Siriyali.khombisa(" C   Umswakama: ");
    Siriyali.khombisa(umswakama);
    Siriyali.khombisa_umugca(" %");
}
