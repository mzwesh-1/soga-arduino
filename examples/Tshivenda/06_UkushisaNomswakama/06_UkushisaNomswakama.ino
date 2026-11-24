// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Tshivenda.h>

DHT inzwa(2, DHT11);

a_huna thoma() {
    Siriale.mathomo(9600);
    inzwa.mathomo();
}

a_huna dovholola() {
    lindela(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    desimala umswakama = inzwa.vhala_vhunyoro();
    desimala ukushisa = inzwa.vhala_mufhiso();
    arali (a_si_nomboro(umswakama) || a_si_nomboro(ukushisa)) {
        Siriale.sumbedza_mutalo("Iphutha: angikwazi ukufunda i-DHT11");
        vhuisa;
    }
    Siriale.sumbedza("Ukushisa: ");
    Siriale.sumbedza(ukushisa);
    Siriale.sumbedza(" C   Umswakama: ");
    Siriale.sumbedza(umswakama);
    Siriale.sumbedza_mutalo(" %");
}
