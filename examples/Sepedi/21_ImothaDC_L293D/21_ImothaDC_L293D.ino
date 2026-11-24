// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Sepedi.h>

sa_fetogego palo IJUBANE = 5;
sa_fetogego palo PHAMBILI = 3;
sa_fetogego palo EMUVA = 4;

lefeela qhuba(palo ijubane, bulini uya_phambili) {
    ngwala_dijithale(PHAMBILI, uya_phambili ? GODIMO : FASE);
    ngwala_dijithale(EMUVA, uya_phambili ? FASE : GODIMO);
    ngwala_analoko(IJUBANE, ijubane);     // 0-255
}

lefeela thoma() {
    bea_phini(IJUBANE, TSE_TSWAGO);
    bea_phini(PHAMBILI, TSE_TSWAGO);
    bea_phini(EMUVA, TSE_TSWAGO);
}

lefeela boeletsa() {
    dikologa (palo i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, thereso);
        leta(50);
    }
    leta(2000);
    qhuba(0, thereso);                               // yima
    leta(1000);
    qhuba(180, maaka);                              // emuva
    leta(2000);
    qhuba(0, thereso);
    leta(1000);
}
