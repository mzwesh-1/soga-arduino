// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <isiNdebele.h>

okungatjhugulukiko inomboro IDATHA = 2;
okungatjhugulukiko inomboro IKHIYI = 3;    // latch
okungatjhugulukiko inomboro IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
ibhayithi izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

ilize bonisa_inombolo(ibhayithi n) {
    tlola_idijithali(IKHIYI, PHASI);
    phusha_amabhithi(IDATHA, IWASHI, OKUKHULU_KUQALA, izinombolo[n]);
    tlola_idijithali(IKHIYI, PHEZULU);
}

ilize thoma() {
    beka_iphini(IDATHA, OKUPHUMAKO);
    beka_iphini(IKHIYI, OKUPHUMAKO);
    beka_iphini(IWASHI, OKUPHUMAKO);
}

ilize phinda_phinda() {
    jikeleza (ibhayithi n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        lindela(1000);
    }
}
