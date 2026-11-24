// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Setswana.h>

RTC_DS3231 iwashi;
tlhaka e_sa_fetogeng* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

lefela bonisa_ezimbili(palo n) {
    fa (n < 10) Seriale.bontsha('0');
    Seriale.bontsha(n);
}

lefela simolola() {
    Seriale.tshimologo(9600);
    fa (!iwashi.tshimologo()) {
        Seriale.bontsha_mola("Angiliboni iwashi le-DS3231!");
        fa_fela (boammaaruri) ema(10);
    }
    fa (iwashi.maatla_a_latlhegile()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.baakanya_nako(Letlha_le_nako(F(__DATE__), F(__TIME__)));
    }
}

lefela boeletsa() {
    Letlha_le_nako jaanong = iwashi.jaanong();
    Seriale.bontsha(izinsuku[jaanong.letsatsi_la_beke()]);
    Seriale.bontsha(" ");
    Seriale.bontsha(jaanong.ngwaga()); Seriale.bontsha('/');
    bonisa_ezimbili(jaanong.kgwedi()); Seriale.bontsha('/');
    bonisa_ezimbili(jaanong.letsatsi()); Seriale.bontsha("  ");
    bonisa_ezimbili(jaanong.ura()); Seriale.bontsha(':');
    bonisa_ezimbili(jaanong.motsotso()); Seriale.bontsha(':');
    bonisa_ezimbili(jaanong.ya_bobedi());
    Seriale.bontsha_mola();
    ema(1000);
}
