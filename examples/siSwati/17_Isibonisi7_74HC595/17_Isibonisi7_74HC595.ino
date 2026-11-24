// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <siSwati.h>

lokungagucuki inombolo IDATHA = 2;
lokungagucuki inombolo IKHIYI = 3;    // latch
lokungagucuki inombolo IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
libhayithi izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

lite bonisa_inombolo(libhayithi n) {
    bhala_idijithali(IKHIYI, PHANSI);
    phusha_emabhithi(IDATHA, IWASHI, LOKUKHULU_KUCALA, izinombolo[n]);
    bhala_idijithali(IKHIYI, PHETULU);
}

lite cala() {
    setha_liphini(IDATHA, LOKUPHUMAKO);
    setha_liphini(IKHIYI, LOKUPHUMAKO);
    setha_liphini(IWASHI, LOKUPHUMAKO);
}

lite phindza_phindza() {
    jikeleta (libhayithi n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        lindza(1000);
    }
}
