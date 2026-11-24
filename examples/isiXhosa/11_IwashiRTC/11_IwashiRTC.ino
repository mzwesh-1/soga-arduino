// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <isiXhosa.h>

RTC_DS3231 iwashi;
unobumba engatshintshiyo* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

ize bonisa_ezimbili(inani n) {
    ukuba (n < 10) Isiriyali.bonisa('0');
    Isiriyali.bonisa(n);
}

ize qalisa() {
    Isiriyali.ukuqala(9600);
    ukuba (!iwashi.ukuqala()) {
        Isiriyali.bonisa_umgca("Angiliboni iwashi le-DS3231!");
        ngelixa (inyani) linda(10);
    }
    ukuba (iwashi.ilahlekile_amandla()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lungisa_ixesha(Umhla_nexesha(F(__DATE__), F(__TIME__)));
    }
}

ize phinda_phinda() {
    Umhla_nexesha ngoku = iwashi.ngoku();
    Isiriyali.bonisa(izinsuku[ngoku.usuku_lweveki()]);
    Isiriyali.bonisa(" ");
    Isiriyali.bonisa(ngoku.unyaka()); Isiriyali.bonisa('/');
    bonisa_ezimbili(ngoku.inyanga()); Isiriyali.bonisa('/');
    bonisa_ezimbili(ngoku.usuku()); Isiriyali.bonisa("  ");
    bonisa_ezimbili(ngoku.iyure()); Isiriyali.bonisa(':');
    bonisa_ezimbili(ngoku.umzuzu()); Isiriyali.bonisa(':');
    bonisa_ezimbili(ngoku.eyesibini());
    Isiriyali.bonisa_umgca();
    linda(1000);
}
