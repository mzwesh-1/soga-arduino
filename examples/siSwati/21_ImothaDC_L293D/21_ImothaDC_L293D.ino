// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <siSwati.h>

lokungagucuki inombolo IJUBANE = 5;
lokungagucuki inombolo PHAMBILI = 3;
lokungagucuki inombolo EMUVA = 4;

lite qhuba(inombolo ijubane, ibhuli uya_phambili) {
    bhala_idijithali(PHAMBILI, uya_phambili ? PHETULU : PHANSI);
    bhala_idijithali(EMUVA, uya_phambili ? PHANSI : PHETULU);
    bhala_ianalogi(IJUBANE, ijubane);     // 0-255
}

lite cala() {
    setha_liphini(IJUBANE, LOKUPHUMAKO);
    setha_liphini(PHAMBILI, LOKUPHUMAKO);
    setha_liphini(EMUVA, LOKUPHUMAKO);
}

lite phindza_phindza() {
    jikeleta (inombolo i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, liciniso);
        lindza(50);
    }
    lindza(2000);
    qhuba(0, liciniso);                               // yima
    lindza(1000);
    qhuba(180, emanga);                              // emuva
    lindza(2000);
    qhuba(0, liciniso);
    lindza(1000);
}
