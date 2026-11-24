// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <Sepedi.h>

sa_fetogego palo IDATHA = 2;
sa_fetogego palo IKHIYI = 3;    // latch
sa_fetogego palo IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
paete izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

lefeela bonisa_inombolo(paete n) {
    ngwala_dijithale(IKHIYI, FASE);
    kgorometsa_dipiti_ntle(IDATHA, IWASHI, E_KGOLO_PELE, izinombolo[n]);
    ngwala_dijithale(IKHIYI, GODIMO);
}

lefeela thoma() {
    bea_phini(IDATHA, TSE_TSWAGO);
    bea_phini(IKHIYI, TSE_TSWAGO);
    bea_phini(IWASHI, TSE_TSWAGO);
}

lefeela boeletsa() {
    dikologa (paete n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        leta(1000);
    }
}
