// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IJUBANE = 5;
lexi_nga_cinciki nomboro PHAMBILI = 3;
lexi_nga_cinciki nomboro EMUVA = 4;

swi_hava qhuba(nomboro ijubane, buliyani uya_phambili) {
    tsala_dijitali(PHAMBILI, uya_phambili ? HENHLA : HANSI);
    tsala_dijitali(EMUVA, uya_phambili ? HANSI : HENHLA);
    tsala_analogo(IJUBANE, ijubane);     // 0-255
}

swi_hava sungula() {
    veka_phini(IJUBANE, LESWI_HUMAKA);
    veka_phini(PHAMBILI, LESWI_HUMAKA);
    veka_phini(EMUVA, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    rhendzeleka (nomboro i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, ntiyiso);
        rindza(50);
    }
    rindza(2000);
    qhuba(0, ntiyiso);                               // yima
    rindza(1000);
    qhuba(180, mavunwa);                              // emuva
    rindza(2000);
    qhuba(0, ntiyiso);
    rindza(1000);
}
