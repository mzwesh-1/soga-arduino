// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <isiNdebele.h>

okungatjhugulukiko inomboro IJUBANE = 5;
okungatjhugulukiko inomboro PHAMBILI = 3;
okungatjhugulukiko inomboro EMUVA = 4;

ilize qhuba(inomboro ijubane, ibhuli uya_phambili) {
    tlola_idijithali(PHAMBILI, uya_phambili ? PHEZULU : PHASI);
    tlola_idijithali(EMUVA, uya_phambili ? PHASI : PHEZULU);
    tlola_ianalogi(IJUBANE, ijubane);     // 0-255
}

ilize thoma() {
    beka_iphini(IJUBANE, OKUPHUMAKO);
    beka_iphini(PHAMBILI, OKUPHUMAKO);
    beka_iphini(EMUVA, OKUPHUMAKO);
}

ilize phinda_phinda() {
    jikeleza (inomboro i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, iqiniso);
        lindela(50);
    }
    lindela(2000);
    qhuba(0, iqiniso);                               // yima
    lindela(1000);
    qhuba(180, amala);                              // emuva
    lindela(2000);
    qhuba(0, iqiniso);
    lindela(1000);
}
