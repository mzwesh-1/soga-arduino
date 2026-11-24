// DHT11: ifunda izinga lokushisa (degrees C) nomswakama (%).
// Ukuxhuma: S (data) -> 2, + -> 5V, - -> GND
// Dinga umtapo: "DHT sensor library" ka-Adafruit (Tools -> Manage Libraries)
#include <DHT.h>
#include <Sepedi.h>

DHT inzwa(2, DHT11);

lefeela thoma() {
    Seriale.mathomo(9600);
    inzwa.mathomo();
}

lefeela boeletsa() {
    leta(2000);                               // i-DHT11 ifundwa kanye emizuzwaneni emi-2
    tesimale umswakama = inzwa.bala_mongobo();
    tesimale ukushisa = inzwa.bala_themphereitsha();
    ge (ga_se_nomoro(umswakama) || ga_se_nomoro(ukushisa)) {
        Seriale.bontsha_mothaladi("Iphutha: angikwazi ukufunda i-DHT11");
        busetsa;
    }
    Seriale.bontsha("Ukushisa: ");
    Seriale.bontsha(ukushisa);
    Seriale.bontsha(" C   Umswakama: ");
    Seriale.bontsha(umswakama);
    Seriale.bontsha_mothaladi(" %");
}
