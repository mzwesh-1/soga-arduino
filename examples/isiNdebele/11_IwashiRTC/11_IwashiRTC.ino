// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <isiNdebele.h>

RTC_DS3231 iwashi;
uhlamvu okungatjhugulukiko* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

ilize bonisa_ezimbili(inomboro n) {
    nangabe (n < 10) Isiriyali.khombisa('0');
    Isiriyali.khombisa(n);
}

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    nangabe (!iwashi.ukuthoma()) {
        Isiriyali.khombisa_umugqa("Angiliboni iwashi le-DS3231!");
        ngesikhathi (iqiniso) lindela(10);
    }
    nangabe (iwashi.kulahlekile_amandla()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lungisa_isikhathi(Ilanga_nesikhathi(F(__DATE__), F(__TIME__)));
    }
}

ilize phinda_phinda() {
    Ilanga_nesikhathi manje = iwashi.manje();
    Isiriyali.khombisa(izinsuku[manje.ilanga_leveke()]);
    Isiriyali.khombisa(" ");
    Isiriyali.khombisa(manje.umnyaka()); Isiriyali.khombisa('/');
    bonisa_ezimbili(manje.inyanga()); Isiriyali.khombisa('/');
    bonisa_ezimbili(manje.ilanga()); Isiriyali.khombisa("  ");
    bonisa_ezimbili(manje.iri()); Isiriyali.khombisa(':');
    bonisa_ezimbili(manje.umzuzu()); Isiriyali.khombisa(':');
    bonisa_ezimbili(manje.okwesibili());
    Isiriyali.khombisa_umugqa();
    lindela(1000);
}
