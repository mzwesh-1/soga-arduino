// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Sesotho.h>

DHT inzwa(2, DHT11);

lefeela qala() {
    Seriale.qalo(9600);
    inzwa.qalo();
}

lefeela pheta_pheta() {
    ema(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    desimale umswakama = inzwa.bala_mongobo();
    desimale ukushisa = inzwa.bala_themperetjha();
    haeba (hase_nomoro(umswakama) || hase_nomoro(ukushisa)) {
        Seriale.bontsha_mola("Iphutha: angikwazi ukufunda i-DHT11");
        kgutlisa;
    }
    Seriale.bontsha("Ukushisa: ");
    Seriale.bontsha(ukushisa);
    Seriale.bontsha(" C   Umswakama: ");
    Seriale.bontsha(umswakama);
    Seriale.bontsha_mola(" %");
}
