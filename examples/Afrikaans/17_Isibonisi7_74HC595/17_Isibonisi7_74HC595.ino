// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <Afrikaans.h>

konstant heelgetal IDATHA = 2;
konstant heelgetal IKHIYI = 3;    // latch
konstant heelgetal IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
greep izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

leeg bonisa_inombolo(greep n) {
    skryfdigitaal(IKHIYI, LAAG);
    skuif_bisse_uit(IDATHA, IWASHI, GROOTSTE_EERSTE, izinombolo[n]);
    skryfdigitaal(IKHIYI, HOOG);
}

leeg opstel() {
    penmodus(IDATHA, UITSET);
    penmodus(IKHIYI, UITSET);
    penmodus(IWASHI, UITSET);
}

leeg lus() {
    vir (greep n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        wag(1000);
    }
}
