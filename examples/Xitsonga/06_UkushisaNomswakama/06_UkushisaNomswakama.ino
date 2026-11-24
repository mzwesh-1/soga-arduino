// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Xitsonga.h>

DHT inzwa(2, DHT11);

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    inzwa.ku_sungula();
}

swi_hava phindha_phindha() {
    rindza(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    desimali umswakama = inzwa.hlaya_ku_tsakama();
    desimali ukushisa = inzwa.hlaya_mahiselo();
    loko (a_hi_nomboro(umswakama) || a_hi_nomboro(ukushisa)) {
        Siriyali.kombisa_layini("Iphutha: angikwazi ukufunda i-DHT11");
        vuyisa;
    }
    Siriyali.kombisa("Ukushisa: ");
    Siriyali.kombisa(ukushisa);
    Siriyali.kombisa(" C   Umswakama: ");
    Siriyali.kombisa(umswakama);
    Siriyali.kombisa_layini(" %");
}
