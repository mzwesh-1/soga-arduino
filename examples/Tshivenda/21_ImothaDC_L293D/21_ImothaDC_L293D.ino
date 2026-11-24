// Imotha ye-DC nefeni nge-L293D: iya phambili, isheshe kancane kancane, ime, ibuyele emuva.
// Ukuxhuma i-L293D: EN1 (1) -> 5, IN1 (2) -> 3, IN2 (7) -> 4, OUT1 (3) & OUT2 (6) -> imotha,
//                   VCC1 (16) -> 5V, VCC2 (8) -> ugesi wemotha, GND (4, 5, 12, 13) -> GND
// Sebenzisa ibhodi likagesi lebhodi lokuhlola (breadboard power supply) kumotha, hhayi i-5V ye-Arduino.
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IJUBANE = 5;
zwi_sa_shanduki nomboro PHAMBILI = 3;
zwi_sa_shanduki nomboro EMUVA = 4;

a_huna qhuba(nomboro ijubane, buliani uya_phambili) {
    nwala_didzhithala(PHAMBILI, uya_phambili ? NTHA : FHASI);
    nwala_didzhithala(EMUVA, uya_phambili ? FHASI : NTHA);
    nwala_analogo(IJUBANE, ijubane);     // 0-255
}

a_huna thoma() {
    vhea_phini(IJUBANE, ZWI_BVAHO);
    vhea_phini(PHAMBILI, ZWI_BVAHO);
    vhea_phini(EMUVA, ZWI_BVAHO);
}

a_huna dovholola() {
    mona (nomboro i = 80; i <= 255; i += 5) {   // sheshisa kancane kancane
        qhuba(i, ngoho);
        lindela(50);
    }
    lindela(2000);
    qhuba(0, ngoho);                               // yima
    lindela(1000);
    qhuba(180, mazwifhi);                              // emuva
    lindela(2000);
    qhuba(0, ngoho);
    lindela(1000);
}
