// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <isiZulu.h>

engaguquki inombolo IJUBANE = 5;
engaguquki inombolo PHAMBILI = 3;
engaguquki inombolo EMUVA = 4;

ize qhuba(inombolo ijubane, ibhuli uya_phambili) {
    bhala_idijithali(PHAMBILI, uya_phambili ? PHEZULU : PHANSI);
    bhala_idijithali(EMUVA, uya_phambili ? PHANSI : PHEZULU);
    bhala_ianalogi(IJUBANE, ijubane);     // 0-255
}

ize qala() {
    setha_iphini(IJUBANE, OKUPHUMAYO);
    setha_iphini(PHAMBILI, OKUPHUMAYO);
    setha_iphini(EMUVA, OKUPHUMAYO);
}

ize phindaphinda() {
    jikeleza (inombolo i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, iqiniso);
        linda(50);
    }
    linda(2000);
    qhuba(0, iqiniso);                               // yima
    linda(1000);
    qhuba(180, amanga);                              // emuva
    linda(2000);
    qhuba(0, iqiniso);
    linda(1000);
}
