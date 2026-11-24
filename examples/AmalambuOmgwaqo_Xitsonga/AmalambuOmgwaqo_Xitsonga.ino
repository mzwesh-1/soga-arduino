#include <Xitsonga.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

lexi_nga_cinciki nomboro ILAMBU_ELIBOMVU   = 10;
lexi_nga_cinciki nomboro ILAMBU_ELIPHUZI   = 9;
lexi_nga_cinciki nomboro ILAMBU_ELILUHLAZA = 8;

lexi_nga_cinciki nomboro ISIKHATHI_SOKUHAMBA  = 10000;
lexi_nga_cinciki nomboro ISIKHATHI_SOKUNCIPHA = 3000;
lexi_nga_cinciki nomboro ISIKHATHI_SOKUMA     = 5000;

swi_hava sungula() {
    veka_phini(ILAMBU_ELIBOMVU, LESWI_HUMAKA);
    veka_phini(ILAMBU_ELIPHUZI, LESWI_HUMAKA);
    veka_phini(ILAMBU_ELILUHLAZA, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    tsala_dijitali(ILAMBU_ELILUHLAZA, HENHLA);
    tsala_dijitali(ILAMBU_ELIPHUZI, HANSI);
    tsala_dijitali(ILAMBU_ELIBOMVU, HANSI);
    rindza(ISIKHATHI_SOKUHAMBA);

    tsala_dijitali(ILAMBU_ELILUHLAZA, HANSI);
    tsala_dijitali(ILAMBU_ELIPHUZI, HENHLA);
    rindza(ISIKHATHI_SOKUNCIPHA);

    tsala_dijitali(ILAMBU_ELIPHUZI, HANSI);
    tsala_dijitali(ILAMBU_ELIBOMVU, HENHLA);
    rindza(ISIKHATHI_SOKUMA);
}
