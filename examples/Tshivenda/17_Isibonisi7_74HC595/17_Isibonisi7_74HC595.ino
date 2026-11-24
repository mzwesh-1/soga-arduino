// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IDATHA = 2;
zwi_sa_shanduki nomboro IKHIYI = 3;    // latch
zwi_sa_shanduki nomboro IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
baithi izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

a_huna bonisa_inombolo(baithi n) {
    nwala_didzhithala(IKHIYI, FHASI);
    sundedza_bithi_nnda(IDATHA, IWASHI, HULWANE_U_THOMA, izinombolo[n]);
    nwala_didzhithala(IKHIYI, NTHA);
}

a_huna thoma() {
    vhea_phini(IDATHA, ZWI_BVAHO);
    vhea_phini(IKHIYI, ZWI_BVAHO);
    vhea_phini(IWASHI, ZWI_BVAHO);
}

a_huna dovholola() {
    mona (baithi n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        lindela(1000);
    }
}
