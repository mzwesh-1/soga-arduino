// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <Sesotho.h>

e_sa_fetoheng palo IDATHA = 2;
e_sa_fetoheng palo IKHIYI = 3;    // latch
e_sa_fetoheng palo IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
baete izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

lefeela bonisa_inombolo(baete n) {
    ngola_dijithale(IKHIYI, TLASE);
    sutumetsa_dibithi_ka_ntle(IDATHA, IWASHI, E_KGOLO_PELE, izinombolo[n]);
    ngola_dijithale(IKHIYI, HODIMO);
}

lefeela qala() {
    beha_phini(IDATHA, TSE_TSWANG);
    beha_phini(IKHIYI, TSE_TSWANG);
    beha_phini(IWASHI, TSE_TSWANG);
}

lefeela pheta_pheta() {
    bakeng_sa (baete n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        ema(1000);
    }
}
