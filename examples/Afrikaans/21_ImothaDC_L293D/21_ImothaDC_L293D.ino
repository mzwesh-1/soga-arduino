// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Afrikaans.h>

konstant heelgetal IJUBANE = 5;
konstant heelgetal PHAMBILI = 3;
konstant heelgetal EMUVA = 4;

leeg qhuba(heelgetal ijubane, boolees uya_phambili) {
    skryfdigitaal(PHAMBILI, uya_phambili ? HOOG : LAAG);
    skryfdigitaal(EMUVA, uya_phambili ? LAAG : HOOG);
    skryfanaloog(IJUBANE, ijubane);     // 0-255
}

leeg opstel() {
    penmodus(IJUBANE, UITSET);
    penmodus(PHAMBILI, UITSET);
    penmodus(EMUVA, UITSET);
}

leeg lus() {
    vir (heelgetal i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, waar);
        wag(50);
    }
    wag(2000);
    qhuba(0, waar);                               // yima
    wag(1000);
    qhuba(180, vals);                              // emuva
    wag(2000);
    qhuba(0, waar);
    wag(1000);
}
