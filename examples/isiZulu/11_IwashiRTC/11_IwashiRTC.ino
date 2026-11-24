// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <isiZulu.h>

RTC_DS3231 iwashi;
uhlamvu engaguquki* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

ize bonisa_ezimbili(inombolo n) {
    uma (n < 10) Isiriyeli.bonisa('0');
    Isiriyeli.bonisa(n);
}

ize qala() {
    Isiriyeli.ukuqala(9600);
    uma (!iwashi.ukuqala()) {
        Isiriyeli.bonisa_umugqa("Angiliboni iwashi le-DS3231!");
        ngenkathi (iqiniso) linda(10);
    }
    uma (iwashi.kulahlekile_amandla()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lungisa_isikhathi(Usuku_nesikhathi(F(__DATE__), F(__TIME__)));
    }
}

ize phindaphinda() {
    Usuku_nesikhathi manje = iwashi.manje();
    Isiriyeli.bonisa(izinsuku[manje.usuku_lwesonto()]);
    Isiriyeli.bonisa(" ");
    Isiriyeli.bonisa(manje.unyaka()); Isiriyeli.bonisa('/');
    bonisa_ezimbili(manje.inyanga()); Isiriyeli.bonisa('/');
    bonisa_ezimbili(manje.usuku()); Isiriyeli.bonisa("  ");
    bonisa_ezimbili(manje.ihora()); Isiriyeli.bonisa(':');
    bonisa_ezimbili(manje.umzuzu()); Isiriyeli.bonisa(':');
    bonisa_ezimbili(manje.okwesibili());
    Isiriyeli.bonisa_umugqa();
    linda(1000);
}
