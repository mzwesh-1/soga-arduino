// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Sepedi.h>

RTC_DS3231 iwashi;
tlhaka sa_fetogego* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

lefeela bonisa_ezimbili(palo n) {
    ge (n < 10) Seriale.bontsha('0');
    Seriale.bontsha(n);
}

lefeela thoma() {
    Seriale.mathomo(9600);
    ge (!iwashi.mathomo()) {
        Seriale.bontsha_mothaladi("Angiliboni iwashi le-DS3231!");
        ge_fela (thereso) leta(10);
    }
    ge (iwashi.maatla_a_lahlegile()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lokisa_nako(Letsatsi_le_nako_la_lehono(F(__DATE__), F(__TIME__)));
    }
}

lefeela boeletsa() {
    Letsatsi_le_nako_la_lehono bjale = iwashi.bjale();
    Seriale.bontsha(izinsuku[bjale.letsatsi_la_beke()]);
    Seriale.bontsha(" ");
    Seriale.bontsha(bjale.ngwaga()); Seriale.bontsha('/');
    bonisa_ezimbili(bjale.kgwedi()); Seriale.bontsha('/');
    bonisa_ezimbili(bjale.letsatsi()); Seriale.bontsha("  ");
    bonisa_ezimbili(bjale.iri()); Seriale.bontsha(':');
    bonisa_ezimbili(bjale.motsotso()); Seriale.bontsha(':');
    bonisa_ezimbili(bjale.ya_bobedi());
    Seriale.bontsha_mothaladi();
    leta(1000);
}
