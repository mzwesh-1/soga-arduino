// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Sesotho.h>

RTC_DS3231 iwashi;
tlhaku e_sa_fetoheng* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

lefeela bonisa_ezimbili(palo n) {
    haeba (n < 10) Seriale.bontsha('0');
    Seriale.bontsha(n);
}

lefeela qala() {
    Seriale.qalo(9600);
    haeba (!iwashi.qalo()) {
        Seriale.bontsha_mola("Angiliboni iwashi le-DS3231!");
        ha_feela (nnete) ema(10);
    }
    haeba (iwashi.matla_a_lahlehile()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lokisa_nako(Letsatsi_le_nako(F(__DATE__), F(__TIME__)));
    }
}

lefeela pheta_pheta() {
    Letsatsi_le_nako jwale = iwashi.jwale();
    Seriale.bontsha(izinsuku[jwale.letsatsi_la_beke()]);
    Seriale.bontsha(" ");
    Seriale.bontsha(jwale.selemo()); Seriale.bontsha('/');
    bonisa_ezimbili(jwale.kgwedi()); Seriale.bontsha('/');
    bonisa_ezimbili(jwale.letsatsi()); Seriale.bontsha("  ");
    bonisa_ezimbili(jwale.hora()); Seriale.bontsha(':');
    bonisa_ezimbili(jwale.motsotso()); Seriale.bontsha(':');
    bonisa_ezimbili(jwale.ya_bobedi());
    Seriale.bontsha_mola();
    ema(1000);
}
