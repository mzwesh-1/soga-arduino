// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <isiXhosa.h>

engatshintshiyo inani IJUBANE = 5;
engatshintshiyo inani PHAMBILI = 3;
engatshintshiyo inani EMUVA = 4;

ize qhuba(inani ijubane, ibhuli uya_phambili) {
    bhala_idijithali(PHAMBILI, uya_phambili ? PHEZULU : EZANTSI);
    bhala_idijithali(EMUVA, uya_phambili ? EZANTSI : PHEZULU);
    bhala_ianalogu(IJUBANE, ijubane);     // 0-255
}

ize qalisa() {
    misela_iphini(IJUBANE, OKUPHUMAYO);
    misela_iphini(PHAMBILI, OKUPHUMAYO);
    misela_iphini(EMUVA, OKUPHUMAYO);
}

ize phinda_phinda() {
    jikeleza (inani i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, inyani);
        linda(50);
    }
    linda(2000);
    qhuba(0, inyani);                               // yima
    linda(1000);
    qhuba(180, ubuxoki);                              // emuva
    linda(2000);
    qhuba(0, inyani);
    linda(1000);
}
