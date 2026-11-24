// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Tshivenda.h>

RTC_DS3231 iwashi;
ledere zwi_sa_shanduki* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

a_huna bonisa_ezimbili(nomboro n) {
    arali (n < 10) Siriale.sumbedza('0');
    Siriale.sumbedza(n);
}

a_huna thoma() {
    Siriale.mathomo(9600);
    arali (!iwashi.mathomo()) {
        Siriale.sumbedza_mutalo("Angiliboni iwashi le-DS3231!");
        musi (ngoho) lindela(10);
    }
    arali (iwashi.maanda_o_xela()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lugisa_tshifhinga(Datumu_na_tshifhinga(F(__DATE__), F(__TIME__)));
    }
}

a_huna dovholola() {
    Datumu_na_tshifhinga zwino = iwashi.zwino();
    Siriale.sumbedza(izinsuku[zwino.duvha_la_vhege()]);
    Siriale.sumbedza(" ");
    Siriale.sumbedza(zwino.nwaha()); Siriale.sumbedza('/');
    bonisa_ezimbili(zwino.nwedzi()); Siriale.sumbedza('/');
    bonisa_ezimbili(zwino.duvha()); Siriale.sumbedza("  ");
    bonisa_ezimbili(zwino.awara()); Siriale.sumbedza(':');
    bonisa_ezimbili(zwino.minithi()); Siriale.sumbedza(':');
    bonisa_ezimbili(zwino.tsha_vhuvhili());
    Siriale.sumbedza_mutalo();
    lindela(1000);
}
