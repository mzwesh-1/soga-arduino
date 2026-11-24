// Isibonisi sezinombolo esisodwa (7-segment) nge-74HC595: sibala kusuka ku-0 kuya ku-9.
// Ukuxhuma i-74HC595: DS (14) -> 2, ST_CP (12) -> 3, SH_CP (11) -> 4, Q0-Q6 -> a-g (220 ohm), Q7 -> DP
#include <Xitsonga.h>

lexi_nga_cinciki nomboro IDATHA = 2;
lexi_nga_cinciki nomboro IKHIYI = 3;    // latch
lexi_nga_cinciki nomboro IWASHI = 4;    // clock

// Izinombolo 0-9 (a = bit 0 ... g = bit 6), cathode efanayo
bayiti izinombolo[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

swi_hava bonisa_inombolo(bayiti n) {
    tsala_dijitali(IKHIYI, HANSI);
    susumeta_tibiti_ehandle(IDATHA, IWASHI, XIKULU_XO_SUNGULA, izinombolo[n]);
    tsala_dijitali(IKHIYI, HENHLA);
}

swi_hava sungula() {
    veka_phini(IDATHA, LESWI_HUMAKA);
    veka_phini(IKHIYI, LESWI_HUMAKA);
    veka_phini(IWASHI, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    rhendzeleka (bayiti n = 0; n < 10; n++) {
        bonisa_inombolo(n);
        rindza(1000);
    }
}
