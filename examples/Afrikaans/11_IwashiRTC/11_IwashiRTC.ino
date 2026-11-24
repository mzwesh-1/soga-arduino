// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Afrikaans.h>

RTC_DS3231 iwashi;
karakter konstant* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

leeg bonisa_ezimbili(heelgetal n) {
    as (n < 10) Seriaal.druk('0');
    Seriaal.druk(n);
}

leeg opstel() {
    Seriaal.begin(9600);
    as (!iwashi.begin()) {
        Seriaal.drukreel("Angiliboni iwashi le-DS3231!");
        terwyl (waar) wag(10);
    }
    as (iwashi.krag_verloor()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.stel_tyd(DatumTyd(F(__DATE__), F(__TIME__)));
    }
}

leeg lus() {
    DatumTyd nou = iwashi.nou();
    Seriaal.druk(izinsuku[nou.weekdag()]);
    Seriaal.druk(" ");
    Seriaal.druk(nou.jaar()); Seriaal.druk('/');
    bonisa_ezimbili(nou.maand()); Seriaal.druk('/');
    bonisa_ezimbili(nou.dag()); Seriaal.druk("  ");
    bonisa_ezimbili(nou.uur()); Seriaal.druk(':');
    bonisa_ezimbili(nou.minuut()); Seriaal.druk(':');
    bonisa_ezimbili(nou.tweede());
    Seriaal.drukreel();
    wag(1000);
}
