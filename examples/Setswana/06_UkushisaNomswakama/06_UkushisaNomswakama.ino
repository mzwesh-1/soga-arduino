// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Setswana.h>

DHT inzwa(2, DHT11);

lefela simolola() {
    Seriale.tshimologo(9600);
    inzwa.tshimologo();
}

lefela boeletsa() {
    ema(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    tesimale umswakama = inzwa.bala_mongobo();
    tesimale ukushisa = inzwa.bala_bothito();
    fa (ga_se_nomore(umswakama) || ga_se_nomore(ukushisa)) {
        Seriale.bontsha_mola("Iphutha: angikwazi ukufunda i-DHT11");
        busa;
    }
    Seriale.bontsha("Ukushisa: ");
    Seriale.bontsha(ukushisa);
    Seriale.bontsha(" C   Umswakama: ");
    Seriale.bontsha(umswakama);
    Seriale.bontsha_mola(" %");
}
