// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <isiNdebele.h>

DHT inzwa(2, DHT11);

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    inzwa.ukuthoma();
}

ilize phinda_phinda() {
    lindela(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    idesimali umswakama = inzwa.funda_umswakama();
    idesimali ukushisa = inzwa.funda_izinga_lokutjhisa();
    nangabe (akusinomboro(umswakama) || akusinomboro(ukushisa)) {
        Isiriyali.khombisa_umugqa("Iphutha: angikwazi ukufunda i-DHT11");
        buyisa;
    }
    Isiriyali.khombisa("Ukushisa: ");
    Isiriyali.khombisa(ukushisa);
    Isiriyali.khombisa(" C   Umswakama: ");
    Isiriyali.khombisa(umswakama);
    Isiriyali.khombisa_umugqa(" %");
}
