// DS3231: iwashi eligcina usuku nesikhathi noma ugesi ucishiwe.
// Ukuxhuma ku-Mega: SDA -> 20, SCL -> 21, VCC -> 5V, GND -> GND
// Dinga umtapo: "RTClib" ka-Adafruit (Tools -> Manage Libraries)
#include <RTClib.h>
#include <Xitsonga.h>

RTC_DS3231 iwashi;
letere lexi_nga_cinciki* izinsuku[7] = {"ISonto", "UMsombuluko", "ULwesibili", "ULwesithathu", "ULwesine", "ULwesihlanu", "UMgqibelo"};

swi_hava bonisa_ezimbili(nomboro n) {
    loko (n < 10) Siriyali.kombisa('0');
    Siriyali.kombisa(n);
}

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    loko (!iwashi.ku_sungula()) {
        Siriyali.kombisa_layini("Angiliboni iwashi le-DS3231!");
        ntsena_loko (ntiyiso) rindza(10);
    }
    loko (iwashi.matimba_ma_lahlekile()) {
        // Setha iwashi ngesikhathi uhlelo olwakhiwe ngaso
        iwashi.lulamisa_nkarhi(Siku_ni_nkarhi(F(__DATE__), F(__TIME__)));
    }
}

swi_hava phindha_phindha() {
    Siku_ni_nkarhi sweswi = iwashi.sweswi();
    Siriyali.kombisa(izinsuku[sweswi.siku_ra_vhiki()]);
    Siriyali.kombisa(" ");
    Siriyali.kombisa(sweswi.lembe()); Siriyali.kombisa('/');
    bonisa_ezimbili(sweswi.nhweti()); Siriyali.kombisa('/');
    bonisa_ezimbili(sweswi.siku()); Siriyali.kombisa("  ");
    bonisa_ezimbili(sweswi.awara()); Siriyali.kombisa(':');
    bonisa_ezimbili(sweswi.minete()); Siriyali.kombisa(':');
    bonisa_ezimbili(sweswi.xa_vumbirhi());
    Siriyali.kombisa_layini();
    rindza(1000);
}
