// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Setswana.h>

e_sa_fetogeng palo IJUBANE = 5;
e_sa_fetogeng palo PHAMBILI = 3;
e_sa_fetogeng palo EMUVA = 4;

lefela qhuba(palo ijubane, bulini uya_phambili) {
    kwala_dijithale(PHAMBILI, uya_phambili ? GODIMO : TLASE);
    kwala_dijithale(EMUVA, uya_phambili ? TLASE : GODIMO);
    kwala_analoko(IJUBANE, ijubane);     // 0-255
}

lefela simolola() {
    baya_phini(IJUBANE, TSE_DI_TSWANG);
    baya_phini(PHAMBILI, TSE_DI_TSWANG);
    baya_phini(EMUVA, TSE_DI_TSWANG);
}

lefela boeletsa() {
    dikologa (palo i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, boammaaruri);
        ema(50);
    }
    ema(2000);
    qhuba(0, boammaaruri);                               // yima
    ema(1000);
    qhuba(180, maaka);                              // emuva
    ema(2000);
    qhuba(0, boammaaruri);
    ema(1000);
}
