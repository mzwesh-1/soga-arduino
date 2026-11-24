// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <siSwati.h>

RTC_DS3231 iwashi;
luhlavu lokungagucuki* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

lite bonisa_ezimbili(inombolo n) {
    nangabe (n < 10) Siriyali.khombisa('0');
    Siriyali.khombisa(n);
}

lite cala() {
    Siriyali.kucala(9600);
    nangabe (!iwashi.kucala()) {
        Siriyali.khombisa_umugca("Angiliboni iwashi le-DS3231!");
        ngesikhatsi (liciniso) lindza(10);
    }
    nangabe (iwashi.kulahlekile_emandla()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lungisa_sikhatsi(Lilanga_nesikhatsi(F(__DATE__), F(__TIME__)));
    }
}

lite phindza_phindza() {
    Lilanga_nesikhatsi nyalo = iwashi.nyalo();
    Siriyali.khombisa(izinsuku[nyalo.lilanga_leliviki()]);
    Siriyali.khombisa(" ");
    Siriyali.khombisa(nyalo.umnyaka()); Siriyali.khombisa('/');
    bonisa_ezimbili(nyalo.inyanga()); Siriyali.khombisa('/');
    bonisa_ezimbili(nyalo.lilanga()); Siriyali.khombisa("  ");
    bonisa_ezimbili(nyalo.lihora()); Siriyali.khombisa(':');
    bonisa_ezimbili(nyalo.umzuzu()); Siriyali.khombisa(':');
    bonisa_ezimbili(nyalo.kwesibili());
    Siriyali.khombisa_umugca();
    lindza(1000);
}
