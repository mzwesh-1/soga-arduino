// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Sesotho.h>

e_sa_fetoheng palo IJUBANE = 5;
e_sa_fetoheng palo PHAMBILI = 3;
e_sa_fetoheng palo EMUVA = 4;

lefeela qhuba(palo ijubane, bulini uya_phambili) {
    ngola_dijithale(PHAMBILI, uya_phambili ? HODIMO : TLASE);
    ngola_dijithale(EMUVA, uya_phambili ? TLASE : HODIMO);
    ngola_analoko(IJUBANE, ijubane);     // 0-255
}

lefeela qala() {
    beha_phini(IJUBANE, TSE_TSWANG);
    beha_phini(PHAMBILI, TSE_TSWANG);
    beha_phini(EMUVA, TSE_TSWANG);
}

lefeela pheta_pheta() {
    bakeng_sa (palo i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, nnete);
        ema(50);
    }
    ema(2000);
    qhuba(0, nnete);                               // yima
    ema(1000);
    qhuba(180, leshano);                              // emuva
    ema(2000);
    qhuba(0, nnete);
    ema(1000);
}
